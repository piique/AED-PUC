#include <stdio.h>

void printaArray(int array[], int n);
void insercaoMovimentacoes(int array[], int n);
void insercaoComparacoes(int array[], int n);
void insercaoDecrescente(int array[], int n);

int main(void) {
  int array[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

  insercaoMovimentacoes(array, 18);
  // insercaoComparacoes(array, 18);

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

// metodo de ordenacao insercao para contar comparações enquanto realiza ordenação
void insercaoMovimentacoes(int array[], int n) {
  int qtdMovimentacoes = 0;
  for (int i = 1; i < n; i++) {
    int tmp = array[i];
    qtdMovimentacoes++;
    printf("\nMovimenta %i para variavel tmp", array[i]);

    int j = i - 1;

    while ((j >= 0) && (array[j] > tmp)) {
      qtdMovimentacoes++;
      printf("\nMovimenta %i para lugar do %i", array[j], array[j + 1]);
      array[j + 1] = array[j];
      j--;
    }

    qtdMovimentacoes++;
    printf("\nMovimenta %i (tmp) para lugar do %i", tmp, array[j + 1]);
    array[j + 1] = tmp;
  }
  printf("\nQuantidade de movimentacoes: %i", qtdMovimentacoes);
}

// metodo de ordenacao insercao para contar comparações enquanto realiza ordenação
void insercaoComparacoes(int array[], int n) {
  int qtdComparacoes = 0;
  for (int i = 1; i < n; i++) {
    int tmp = array[i];
    int j = i - 1;

    qtdComparacoes++;
    printf("\nCompara %i com %i", tmp, array[j]);

    while ((j >= 0) && (array[j] > tmp)) {
      array[j + 1] = array[j];
      j--;
      if ((j >= 0) && (array[j] > tmp)) {
        qtdComparacoes++;
        printf("\nCompara %i com %i", tmp, array[j]);
      }
    }
    array[j + 1] = tmp;
  }
  printf("\nQuantidade de comparacoes: %i", qtdComparacoes);
}

// metodo de ordenacao insercao de forma decrescente utilizada para testes
void insercaoDecrescente(int array[], int n) {
  for (int i = 1; i < n; i++) {
    int tmp = array[i];
    int j = i - 1;
    while ((j >= 0) && (array[j] < tmp)) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = tmp;
  }
}
