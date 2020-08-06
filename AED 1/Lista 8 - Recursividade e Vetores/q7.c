#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{

  // int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int vetor[10];
  printf("Digite 10 numeros: ");

  for (int i = 0; i <= 9; i++)
  {
    scanf("%i", &vetor[i]);
  }

  for (int i = 0; i <= 9; i++)
  {
    if (i == vetor[i])
    {
      printf("\nVetor[%i]: %i", i, vetor[i]);
    }
  }
}