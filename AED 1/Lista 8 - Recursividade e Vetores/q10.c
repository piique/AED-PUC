#include <stdio.h>
#include <stdlib.h>

int main()
{
  int vetor[10], i;
  for (i = 0; i < 10; i++)
  {
    if (i % 2 == 0)
    {
      vetor[i] = 1;
      printf("\nVetor[%i]: %i", i, vetor[i]);
    }
    else
    {
      vetor[i] = 0;
      printf("\nVetor[%i]: %i", i, vetor[i]);
    }
  }

  return 0;
}