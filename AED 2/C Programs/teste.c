#include <stdio.h>

int main() {
  int N = 1, MAIOR, MENOR;
  int vetor[N];
  scanf("%i", &N);
  if (N > 0) {
    for (int i = 0; i < N; i++) {
      scanf("%i", &vetor[i]);
    }
    MAIOR = vetor[0];
    MENOR = vetor[0];
    for (int i = 0; i < N; i++) {
      if (MAIOR < vetor[i]) {
        MAIOR = vetor[i];
      }
      if (MENOR > vetor[i]) {
        MENOR = vetor[i];
      }
    }

    printf("MAIOR = %i\n", MAIOR);
    printf("MENOR = %i\n", MENOR);
  }
  return 0;
}
