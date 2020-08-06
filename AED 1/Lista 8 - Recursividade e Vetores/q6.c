#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{

  // preenche o vetor
  // vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  int vetor[10];
  printf("Digite 10 valores para serem colocados no vetor: ");
  for (int i = 0; i <= 9; i++)
  {
    scanf("%d", &vetor[i]);
  }

  // imprime o vetor na ordem contraria
  for (int i = 9; i >= 0; i--)
  {
    printf("%i ", vetor[i]);
  }
  return 0;
}