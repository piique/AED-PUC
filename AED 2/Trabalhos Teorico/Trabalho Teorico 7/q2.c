#include <stdio.h>

void printaArray(int array[], int n);

int getMaiorMovimentacoes(int *array, int n, int *movimentacoes);
void countingsortMovimentacoes(int *array, int n);

int getMaiorComparacoes(int *array, int n, int *comparacoes);
void countingsortComparacoes(int *array, int n);

int main() {
  int array[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

  // countingsortComparacoes(array, 18);
  countingsortMovimentacoes(array, 18);

  printaArray(array, 18);
  return 0;
}

// funcao para printar array
void printaArray(int array[], int n) {
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

// funcao para pegar maior elemento do array e contar movimentações
int getMaiorMovimentacoes(int *array, int n, int *movimentacoes) {
  int maior = array[0];
  printf("\n\nMovimentacoes pegando maior: ");
  for (int i = 0; i < n; i++) {
    if (maior < array[i]) {
      *movimentacoes = *movimentacoes + 1;
      printf("\nMovimenta %i para variavel maior", array[i]);
      maior = array[i];
    }
  }
  return maior;
}

// funcao para ordenar com countingsort e contar/mostrar movimentações
void countingsortMovimentacoes(int *array, int n) {
  int movimentacoes = 0;
  //Array para contar o numero de ocorrencias de cada elemento
  int tamCount = getMaiorMovimentacoes(array, n, &movimentacoes) + 1;
  int count[tamCount];
  int ordenado[n];

  //Inicializar cada posicao do array de contagem
  for (int i = 0; i < tamCount; i++) {
    count[i] = 0;
  };

  //Agora, o count[i] contem o numero de elemento iguais a i
  for (int i = 0; i < n; i++) {
    count[array[i]]++;
  };

  //Agora, o count[i] contem o numero de elemento menores ou iguais a i
  for (int i = 1; i < tamCount; i++) {
    count[i] += count[i - 1];
  };

  printf("\n\nMovimentacoes de array original para array final");
  //Ordenando
  for (int i = n - 1; i >= 0; i--) {
    movimentacoes++;
    printf("\nMovimenta %i para array_final[%i]", array[i], count[array[i]] - 1);
    ordenado[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  };

  printf("\n\nMovimentacoes de array final para array ordenado: ");
  //Copiando para o array original
  for (int i = 0; i < n; i++) {
    movimentacoes++;
    printf("\nMovimenta %i para array_original[%i]", array[i], count[array[i]] - 1);
    array[i] = ordenado[i];
  };
  printf("\nMovimentacoes totais: %i", movimentacoes);
}

// funcao para pegar maior elemento do array e contar comparações
int getMaiorComparacoes(int *array, int n, int *comparacoes) {
  int maior = array[0];
  printf("\nComparacoes pegando maior: ");
  for (int i = 0; i < n; i++) {
    printf("\nCompara maior < array[%i]: %i < %i", i, maior, array[i]);
    *comparacoes = *comparacoes + 1;
    if (maior < array[i]) {
      maior = array[i];
    }
  }
  return maior;
}

// funcao para ordenar com countingsort e contar/mostrar comparações
void countingsortComparacoes(int *array, int n) {
  int comparacoes = 0;

  //Array para contar o numero de ocorrencias de cada elemento
  int tamCount = getMaiorComparacoes(array, n, &comparacoes) + 1;
  int count[tamCount];
  int ordenado[n];

  //Inicializar cada posicao do array de contagem
  for (int i = 0; i < tamCount; i++) {
    count[i] = 0;
  };

  //Agora, o count[i] contem o numero de elemento iguais a i
  for (int i = 0; i < n; i++) {
    count[array[i]]++;
  };

  //Agora, o count[i] contem o numero de elemento menores ou iguais a i
  for (int i = 1; i < tamCount; i++) {
    count[i] += count[i - 1];
  };

  //Ordenando
  for (int i = n - 1; i >= 0; i--) {
    ordenado[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  };

  //Copiando para o array original
  for (int i = 0; i < n; i++) {
    array[i] = ordenado[i];
  };

  printf("\nComparacoes totais: %i", comparacoes);
}
