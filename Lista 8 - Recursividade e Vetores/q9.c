#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
  int vetor[15], soma = 0, max = 18, min = 40; // valores entre 18 e 40
  float media;
  srand(time(NULL));

  for (int i = 0; i <= 15; i++)
  {
    vetor[i] = rand() % 23 + 18; // valores aleatorios entre 18 e 40
    printf("\nVetor[%i]: %i", i, vetor[i]);

    // soma dos valores para calculo da media
    soma += vetor[i];

    // pegar valor maximo
    if (vetor[i] > max)
      max = vetor[i];

    // pegar valor minimo
    if (vetor[i] < min)
      min = vetor[i];
  }
  media = soma / 15.0;
  printf("\nValor da media: %0.2f", media);
  printf("\nValor maximo: %i", max);
  printf("\nValor minimo: %i", min);

  soma = 0; // utilizada como contador
  // for para validar quantas vezes a temperatura foi abaixo da media
  for (int i = 0; i <= 15; i++)
  {
    if (vetor[i] < media)
    {
      soma++;
    }
  }

  printf("\nQuantidade de vezes abaixo da media: %i", soma);
}