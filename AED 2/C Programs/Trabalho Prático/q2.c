#include <stdio.h>

int main(void) {
  int N, menorValor, menorPosicao;
  scanf("%i", &N);
  int X[N];

  for (int i = 0; i < N; i++) {
    scanf("%i", &X[i]);
  }

  menorPosicao = 0;
  menorValor = X[1];

  for (int i = 0; i < N; i++) {
    if (X[i] < menorValor) {
      menorValor = X[i];
      menorPosicao = i;
    }
  }

  printf("Menor valor: %i\n", menorValor);
  printf("Posicao: %i", menorPosicao);

  return 0;
}
