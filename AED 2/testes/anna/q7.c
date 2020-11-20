#include "stdio.h"
#include "time.h"

int Random(int min, int max);
int main() {
  int a[10][10];

  // inicializa rand com timestamp atual para gerar numeros aleatorios a partir dele
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      a[i][j] = Random(15, 50);
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

int Random(int min, int max) {
  return (min + (rand() % ((max + 1) - min)));
}