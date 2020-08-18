#include <stdio.h>

int main(void) {
  int n, aux, count = 0;
  scanf("%i", &n);
  int v[n];

  for (int i = 0; i < n; i++) {
    scanf("%i", &v[i]);
  }
  printaVetor(v, n);
  ordenaVetor(v, n);
  printf("Vetor ordenado: \n");
  printaVetor(v, n);

  for (int i = 0; i < n; i++) {
    count++;
    if (v[i] != v[i + 1]) {
      printf("%i aparece %i vez(es)\n", v[i], count);
      count = 0;
    }
  }
  return 0;
}

void ordenaVetor(int v[], int n) {
  int aux;
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i] > v[i + 1]) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }
}

void printaVetor(int v[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%i ", v[i]);
  }
}
