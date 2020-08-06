#include <stdio.h>
#include <stdlib.h>

int func(int x)
{
  return (3 * pow(x, 3) + 2 * pow(x, 2) + x - 5);
}

int main()
{
  int vetor[10];
  // preenche o vetor
  for (int i = 0; i < 10; i++)
    vetor[i] = func(i);

  // printa o vetor
  for (int i = 0; i < 10; i++)
    printf("\nVetor[%i]: %i", i, vetor[i]);

  return 0;
}