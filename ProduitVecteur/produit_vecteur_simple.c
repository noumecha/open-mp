#include <stdio.h>
int main(int argc, char const *argv[]) {

  /* Déclarations */
  int U[50], V[50]; /* tableau de données : nos vecteurs */
  int N; /* dimension du tableau */
  int I; /* indice courant */
  long P; /* produit scalaire */

  /* Saisie des données */

  printf("*******************************************************\n");
  printf("**** Programme de calcul du produi de deux vecteurs ***\n");
  printf("*******************************************************\n");

  printf("[] dimension des tableau (max.50) : \n");
  scanf("%d" ,&N);

  printf("** premier tableau : \n");
  for(I=0; I<N; I++)
  {

    printf("Elément %d : ", I);
    scanf("%d", &U[I]);

  }

  printf("*** Deuxième tableau : ** \n");
  for (I=0; I<N; I++)
  {

    printf("Elément %d : ", I);
    scanf("%d", &V[I]);

  }

  /* calcul du produit */

  for (P = 0, I = 0; I<N; I++)
    P += (long)U[I]*V[I];

  /* résultat */
  printf("Produit des deux tableau : %ld\n", P);
  return 0;

}
