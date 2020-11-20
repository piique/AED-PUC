#include "stdio.h"

int fat(int a);

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