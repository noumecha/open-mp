#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#define SIZE 2000

double get_time() {

	struct timeval tv;
	gettimeofday(&tv ,(void *)0);

	return (double) tv.tv_sec + tv.tv_usec*1e-6;

}

int main(int argc , char **argv) {

	// déclaration des variables :
  int nb,i,j,k;
  double t,start,stop;
  double* matrice_A;
  double* matrice_B;
  double* matrice_res;

  // allocation
  matrice_A = (double*) malloc(SIZE*SIZE*sizeof(double));
  matrice_B = (double*) malloc(SIZE*SIZE*sizeof(double));
  matrice_res = (double*) malloc(SIZE*SIZE*sizeof(double));

  // remplissage des matrices

  for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
       matrice_A[i*SIZE + j] = (double)rand()/(double)RAND_MAX;
       matrice_B[i*SIZE + j] = (double)rand()/ (double)RAND_MAX;
    }
  }

	// éxécution du programme en simultané grace à openmp

  printf("Nb.threads\tTps.\n");

  for(nb=1;nb<=12;nb++){
   start = get_time();
  #pragma omp parallel for num_threads(nb) private(j,k)

   for(i=0;i<SIZE;i++){

    for(j=0;j<SIZE;j++){

     matrice_res[i*SIZE + j] = 0.0;

     for(k=0;k<SIZE;k++){

      matrice_res[i*SIZE + j] += (matrice_A[i*SIZE + k]*matrice_B[k*SIZE + j]);

     }

    }

  }
   stop = get_time();

   t=stop=start;

	 // affichage du resultat à lécran 
  printf("%d\t%f\n",nb,t);

 }
  // liberation

  free(matrice_A);
  free(matrice_B);
  free(matrice_res);

  return EXIT_SUCCESS;
}
