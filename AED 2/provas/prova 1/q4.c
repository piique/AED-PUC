#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// declaração função
int mais_proximo(int* v, int n, int x);
bool buscaBinaria(int v[], int n, int x);

int main(void) {
  int v[1000];
  int n, x;

  scanf("%i\n", &n);

  scanf("%i\n", &x);

  for (int i = 0; i < n; i++) {
    scanf(" %i\n", &v[i]);
  }

  printf("%i", mais_proximo(v, n, x));
  return 0;
}

// retorna valor mais proximo do valor de x que tem dentro do vetor atraves de busca binaria
int mais_proximo(int* v, int n, int x) {
  // ordena vetor
  int result;
  if (buscaBinaria(v, n, x)) {
    return x;
  } else {
    for (int i = 1;; i++) {
      // procura pelo mais proximo para esquerda
      if (x - i >= 0 && buscaBinaria(v, n, x - i)) {
        return x - i;
      } else {
        // procura pelo mais proximo para direita
        if (x + i < v[n - 1] && buscaBinaria(v, n, x + i)) {
          return x + 1;
        }
      }
    }
  }
}

// realiza busca binaria no vetor v de tamanho n procurando por x e retornando verdadeiro caso ache
bool buscaBinaria(int v[], int n, int x) {
  int esq = 0, dir = n - 1;

  while (esq <= dir) {
    int meio = (esq + dir) / 2;

    if (v[meio] == x)
      return true;

    if (x > v[meio])
      esq = meio + 1;
    else
      dir = meio - 1;
  }

  return false;
}
