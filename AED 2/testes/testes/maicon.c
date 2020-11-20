#include <stdio.h>
#include <stdlib.h>
#define coluna 3
#define linha 3
void soma_mat(int aux) {
  int soma = 0;
  int maior = 0;
  int menor = 0;
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      aux = (rand() % 9);
      printf("%d ", aux);
      if (aux < menor) {
        menor = aux;
      }
      if (aux > maior) {
        maior = aux;
      }
    }
    printf("\n");
  }
  printf("maior eh: %d na posicao %d|%d\n", maior);
  printf("menor eh: %d na posicao %d|%d\n", menor);
}

void printaMatrix(int **matrix) {
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      // printf("%i ", matrix[i][j]);
      printf("%i ", *(*(matrix + i) + j));
    }
    printf("\n");
  }
}

int main() {
  int aux = 0;

  // criando matrix
  // int matrix[3][3];

  // criando matrix
  int **matrix = malloc(linha * sizeof(int));
  for (int i = 0; i < coluna; i++) {
    *(matrix + i) = (int *)malloc(coluna * sizeof(int));
  }

  // preenchendo matrix
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      *(*(matrix + i) + j) = aux;
    }
  }

  printaMatrix(matrix);

  soma_mat(aux);
  printf("aux: %d", aux);

  return 0;
}
