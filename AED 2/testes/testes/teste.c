#include <stdio.h>
#include <stdlib.h>

// função para somar matriz utilizando ponteiros para percorrer matriz
int somarMatriz(int **matriz, int linhas, int colunas) {
  int soma = 0;
  for (int x = 0; x < linhas; x++) {
    for (int y = 0; y < colunas; y++) {
      soma += **(matriz + x) + y;
    }
  }
  return soma;
}

int main() {
  int m = 2;  // linhas
  int n = 3;  // colunas
  int i = 0;  // valores

  int **matriz;
  matriz = malloc(m * sizeof(int *));
  for (int i = 0; i < m; ++i) {
    matriz[i] = (int *)malloc(n * sizeof(int));
  }

  for (int x = 0; x < m; x++) {
    for (int y = 0; y < n; y++) {
      matriz[x][y] = i;
      printf("%i ", **(matriz + x) + y);
      i++;
    }
    printf("\n");
  }

  printf("Soma: %i", somarMatriz(matriz, m, n));

  // for (int i = 0; i < n * m; i++) {
  //   printf("%i ", *(matriz + i));
  // }

  return 0;

  // int v[5];
  // char *v = (char *)malloc(5 * sizeof(char));

  // ['', '', '', '', '']
  // *(v + 0) = 'a';
  // *(v + 1) = 'b';
  // *(v + 2) = 'c';
  // *(v + 3) = 'd';
  // *(v + 4) = '\0';

  // printf("%c", *(v + 2));

  // printf("Primeira posicao: %i", *v);

  // return 0;

  // NAO INDEXADO
  // printf("Teste sem index: \n");
  // for (int i = 0; i < 5; i++) {
  //   *v = 3;
  //   printf("%i ", *v);
  //   v++;
  // }

  // printf("\n");

  // indexado
  // printf("Teste indexado: \n");
  // for (int i = 0; i < 5; i++) {
  //   v[i] = 2;  // indexado
  //   printf("%i ", v[i]);
  // }

  return 0;
}
