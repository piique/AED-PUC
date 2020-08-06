#include <stdio.h>
#include <stdlib.h>

int main()
{
  // declara variaveis
  double vetor[100];
  int i;

  // preenche as duas primeiras posicoes da sequencia de fibonacci
  vetor[0] = 1;
  vetor[1] = 1;

  // preenche o vetor com a seguencia de fibonacci
  for (i = 2; i <= 100; i++)
  {
    vetor[i] = vetor[i - 1] + vetor[i - 2];
  }

  // printa o vetor
  for (int i = 0; i < 100; i++)
    printf("\nVetor[%i]: %0.0f", i, vetor[i]);

  return 0;
}