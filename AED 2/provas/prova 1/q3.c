#include <stdio.h>
#include <stdlib.h>

// declaração função
int* somente_pares(int* v, int n);

int main(void) {
  int N;
  int v[10000];

  // input usuario
  scanf("%i\n", &N);

  // input usuario
  for (int i = 0; i < N; i++) {
    fflush(stdin);
    scanf(" %i", &v[i]);
  }

  // chamada de função e atribuição de resultado em ponteiro
  int* aux = somente_pares(v, N);

  // printa novo vetor
  for (int i = 0; i < N && aux[i] != -1; i++) {
    printf("%i\n", aux[i]);
  }

  free(aux);

  return 0;
}

// função que realiza copia os valores pares de um vetor  para outro e retorna um ponteiro para o segundo
int* somente_pares(int* v, int n) {
  int* newV = malloc(n * sizeof(float));
  int aux = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] % 2 == 0) {
      newV[aux++] = v[i];
    }
  }
  newV[aux] = -1;

  return newV;
}