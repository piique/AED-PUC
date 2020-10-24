#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int somaMatriz(int **matriz, int linha, int coluna) {
  int soma = 0;

  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      printf("%d ", **(matriz + i) + j);
      soma += *(*(matriz + i) + j);
    }
    printf("\n");
  }

  return soma;
}

int main() {
  int linha;   // linhas
  int coluna;  // colunas

  int menor, menor_linha = 0, menor_coluna = 0;
  int maior, maior_linha = 0, maior_coluna = 0;

  // input de dados
  printf("Digite a quantidade de linhas: ");
  scanf("%i", &linha);
  printf("Digite a quantidade de colunas: ");
  scanf("%i", &coluna);

  // alocação de matriz de forma dinamica
  int **matriz;
  matriz = malloc(linha * sizeof(int *));
  for (int i = 0; i < linha; ++i)
    *(matriz + i) = (int *)malloc(coluna * sizeof(int));

  srand(time(NULL));

  // preenchendo matriz
  for (int i = 0; i < linha; i++)
    for (int j = 0; j < coluna; j++)
      *(*(matriz + i) + j) = rand() % 10;

  maior = **matriz;
  menor = **matriz;

  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      if (maior < *(*(matriz + i) + j)) {
        maior = *(*(matriz + i) + j);
        maior_coluna = i;
        maior_linha = j;
      }
      if (menor > *(*(matriz + i) + j)) {
        menor = *(*(matriz + i) + j);
        menor_coluna = i;
        menor_linha = j;
      }
    }
  }

  printf("Maior: matriz[%i][%i] = %i\n", maior_linha, maior_coluna, maior);
  printf("Menor: matriz[%i][%i] = %i\n", menor_linha, menor_coluna, menor);

  return 0;
}
