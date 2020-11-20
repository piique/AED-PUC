#include "stdio.h"

int fat(int a);
int buscaValor(int matriz[][5]);

int main() {
  int a[3][5], b[3][5];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      printf("Escreva o um valor para a matriz na posicao [%d, %d]: ", i, j);
      scanf("%i", &a[i][j]);
      b[i][j] = fat(a[i][j]);
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      printf("\nO fatorial do numero %d eh %d", a[i][j], b[i][j]);
    }
  }

  buscaValor(a);
}

// função para calcular fatorial
int fat(int n) {
  float fat = 1;
  while (n > 1) {
    fat = fat * n;
    n--;
  }
  return fat;
}

int buscaValor(int matriz[][5]) {
  int i, j, value = -1;
  printf("\n\nDigite os valores de i e j: ");
  scanf("%i %i", &i, &j);

  // verifica se é possivel existir valor na matriz
  if (i >= 0 && i <= 3 && j >= 0 && j <= 5) {
    printf("\nValor da matriz na posicao [%d, %d]: %d", i, j, matriz[i][j]);
    return matriz[i][j];
  }

  return value;
}