#include <stdio.h>

// declaracao de funcoes
void printaArray(int array[], int n);
void shellsortMovimentacoes(int array[], int n);
void insercaoPorCorMovimentacoes(int cor, int h, int array[], int n, int *movimentacoes);
void shellsortComparacoes(int array[], int n);
void insercaoPorCorComparacoes(int cor, int h, int array[], int n, int *comparacoes);

int main(void) {
  int array[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

  shellsortComparacoes(array, 18);
  // shellsortMovimentacoes(array, 18);

  printaArray(array, 18);
  return 0;
}

// metodo para printar array
void printaArray(int array[], int n) {
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

// função shellsort para ordernar vetor mostrando e contando movimentacoes
void shellsortMovimentacoes(int array[], int n) {
  int movimentacoes = 0;
  int h = 1;

  do {
    h = (h * 3) + 1;
  } while (h < n);

  do {
    h /= 3;
    printf("\n\nMovimentacoes h = %i:", h);
    for (int cor = 0; cor < h; cor++) {
      if (h + cor < n) {
        printf("\n\nCor = %i:", cor);
      }
      insercaoPorCorMovimentacoes(cor, h, array, n, &movimentacoes);
    }
    printf("\n------------------------------------------");
  } while (h != 1);
  printf("\nQuantidade total de movimentacoes: %i", movimentacoes);
}

void insercaoPorCorMovimentacoes(int cor, int h, int array[], int n, int *movimentacoes) {
  for (int i = (h + cor); i < n; i += h) {
    int tmp = array[i];
    *movimentacoes = *movimentacoes + 1;
    printf("\nMovimenta %i para variavel tmp", array[i]);

    int j = i - 1;

    while ((j >= 0) && (array[j] > tmp)) {
      *movimentacoes = *movimentacoes + 1;
      printf("\nMovimenta %i para lugar do %i", array[j], array[j + 1]);
      array[j + 1] = array[j];
      j--;
    }

    *movimentacoes = *movimentacoes + 1;
    printf("\nMovimenta %i (tmp) para lugar do %i", tmp, array[j + 1]);
    array[j + 1] = tmp;
  }
}

// função shellsort para ordernar vetor mostrando e contnando comparacoes
void shellsortComparacoes(int array[], int n) {
  int comparacoes = 0;
  int h = 1;

  printf("\nBuscando h inicial: ");
  do {
    h = (h * 3) + 1;
    comparacoes++;
    printf("\nCompara h < n: %i < %i", h, n);
  } while (h < n);
  printf("\n------------------------------------------");

  do {
    h /= 3;
    printf("\n\nComparacoes h = %i:", h);
    printf("\nCompara cor < h: %i < %i", 0, h);
    for (int cor = 0; cor < h; cor++) {
      if (h + cor < n) {
        printf("\n\nCor = %i:", cor);
      }
      insercaoPorCorComparacoes(cor, h, array, n, &comparacoes);

      // comparação da proxima verificação do for
      comparacoes++;
      printf("\nCompara cor < h: %i < %i", 0, h);
    }
    printf("\n------------------------------------------");
  } while (h != 1);
  printf("\nQuantidade total de comparacoes: %i", comparacoes);
}

// utilizado para contar comparacoes
void insercaoPorCorComparacoes(int cor, int h, int array[], int n, int *comparacoes) {
  for (int i = (h + cor); i < n; i += h) {
    int tmp = array[i];
    int j = i - 1;

    *comparacoes = *comparacoes + 1;
    printf("\nCompara %i com %i", tmp, array[j]);

    while ((j >= 0) && (array[j] > tmp)) {
      array[j + 1] = array[j];
      j--;
      if ((j >= 0) && (array[j] > tmp)) {
        *comparacoes = *comparacoes + 1;
        printf("\nCompara %i com %i", tmp, array[j]);
      }
    }
    array[j + 1] = tmp;
  }
}
