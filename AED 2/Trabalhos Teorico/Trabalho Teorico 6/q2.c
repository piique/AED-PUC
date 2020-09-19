#include <stdio.h>

void printaArray(int array[], int n);
void insercao(int array[], int n);
int pesquisaBinaria(int array[], int item, int menor, int maior);

int main(void) {
  // array usado no exercicio anterior
  int array[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
  insercao(array, 18);
  printaArray(array, 18);
  return 0;
}

// função para printar array
void printaArray(int array[], int n) {
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

// função para realização de pesquisa binaria
int pesquisaBinaria(int array[], int item, int menor, int maior) {
  if (maior <= menor)
    return (item > array[menor]) ? (menor + 1) : menor;

  int mid = (menor + maior) / 2;

  if (item == array[mid])
    return mid + 1;

  if (item > array[mid])
    return pesquisaBinaria(array, item, mid + 1, maior);
  return pesquisaBinaria(array, item, menor, mid - 1);
}

// função de ordenacao insercao para contar comparações enquanto realiza ordenação
void insercao(int array[], int n) {
  int index;
  for (int i = 1; i < n; i++) {
    int tmp = array[i];
    int j = i - 1;

    index = pesquisaBinaria(array, tmp, 0, j);

    while (j >= index) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = tmp;
  }
}
