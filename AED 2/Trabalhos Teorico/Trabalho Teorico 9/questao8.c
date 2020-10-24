#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int n;

  printf("Digite um valor N: ");
  scanf("%i", &n);

  // alocacao dinamica
  int *vetor = (int *)(malloc(n * sizeof(int)));
  int soma = 0;

  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    // gerando valores aleatórios na faixa de 0 a 10 e salvando no vetor
    *(vetor + i) = rand() % 10;
    soma += *(vetor + i);
  }

  printf("Soma total dos elementos: %i", soma);

  return 0;
}
