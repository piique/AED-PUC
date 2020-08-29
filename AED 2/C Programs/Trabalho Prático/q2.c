#include <stdio.h>

int main(void) {
  int N, menorValor, menorPosicao, X[1000];

  // recebe quantidade de numeros que serao recebidos
  scanf("%i", &N);

  // preenche vetor
  for (int i = 0; i < N; i++) {
    scanf("%i", &X[i]);
  }

  // atribui valor para as variaveis relacionadas o menor valor e posicao
  menorPosicao = 0;
  menorValor = X[0];

  // for para buscar pelo menor valor armazena-lo junto com sua posicao
  for (int i = 0; i < N; i++) {
    if (X[i] < menorValor) {
      menorValor = X[i];
      menorPosicao = i;
    }
  }

  // printa saida
  printf("Menor valor: %i\n", menorValor);
  printf("Posicao: %i", menorPosicao);

  return 0;
}
