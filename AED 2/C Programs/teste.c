#include <stdio.h>

int main() {
  int n, menor, pos;
  scanf("%i", &n);
  int vetor[n];
  if (n >= 1 && n <= 2000) {
    for (int i = 0; i < n; i++) {
      scanf("%i", &vetor[i]);
      if (vetor[i] < menor) {
        menor = vetor[i];
        pos = i;
      }
    }
    printf("Menor valor: %i\n", menor);
    printf("Posicao: %i", pos);
  }

  return 0;
}
