#include <stdio.h>
#include <stdlib.h>

// declaração função
float* reverso(float* v, int N);

int main(void) {
  int N;
  float v[10000];

  // input usuario
  scanf("%i\n", &N);

  // input usuario
  for (int i = 0; i < N; i++) {
    fflush(stdin);
    scanf(" %f", &v[i]);
  }

  // chamada de função e atribuição de resultado em ponteiro
  float* aux = reverso(v, N);

  // printa novo vetor
  for (int i = 0; i < N; i++) {
    printf("%0.2f\n", aux[i]);
  }

  free(aux);

  return 0;
}

// função que realiza inversão de um vetor  para outro e retorna um ponteiro para o segundo
float* reverso(float* v, int n) {
  float* newV = malloc(n * sizeof(float));

  for (int i = 0; i < n; i++) {
    newV[i] = v[n - i - 1];
  }

  return newV;
}