#include <stdio.h>
#include <stdlib.h>

int main()
{
  srand(time(NULL));
  int vetor[15];
  for (int i = 0; i <= 15; i++)
  {
    vetor[i] = rand() % 11; // numeros aleatorios entre 0 e 10
  }

  for (int i = 0; i <= 9; i++)
  {
    printf("\nVetor[%i]: %i", i, vetor[i]);
  }
}