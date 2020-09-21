#include <stdio.h>

int main(void) {
  int maior, menor, n = 18;
  int array[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

  encontraMaiorMenor(array, 18, &maior, &menor);

  printf("Maior: %i\n", maior);
  printf("Menor: %i\n", menor);

  return 0;
}

// função para encontrar maior e menor elemento e retornar por referencia
void encontraMaiorMenor(int *array, int n, int *maior, int *menor) {
  *maior = array[0];
  *menor = array[0];
  for (int i = 1; i < n; i++) {
    if (*maior < array[i]) {
      *maior = array[i];
    }
    if (*menor > array[i]) {
      *menor = array[i];
    }
  }
}
