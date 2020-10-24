#include <stdio.h>
#include <stdlib.h>

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
  int linha = 3;   // linhas
  int coluna = 3;  // colunas
  int aux = 1;     // valores

  int **matriz;

  matriz = malloc(linha * sizeof(int *));

  for (int i = 0; i < linha; ++i) {
    *(matriz + i) = (int *)malloc(coluna * sizeof(int));
  }

  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      // printf("%p ", *(matriz + i));
      *(*(matriz + i) + j) = aux;
      // matriz[i][j] = aux;
      // printf("%d ", **(matriz + i) + j);
      aux++;
    }
    // printf("\n");
  }

  printf("Soma total: %i", somaMatriz(matriz, linha, coluna));

  return 0;
}
