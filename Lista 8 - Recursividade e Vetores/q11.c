#include <stdio.h>
#include <stdlib.h>

int main()
{
  int vetor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, n = 0;
  while (n != -1)
  {
    printf("Digite numeros entre 0 e 9 (digite -1 para sair): ");
    scanf("%i", &n);

    if (n >= 0 && n <= 9)
      vetor[n]++;
    else if (n != -1)
      printf("Apenas numeros entre 0 e 9!\n");
  }

  // printa o vetor
  for (int i = 0; i < 10; i++)
    printf("\nVetor[%i]: %i", i, vetor[i]);

  return 0;
}