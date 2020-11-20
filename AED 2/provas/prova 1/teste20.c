#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *alocar(int n) {
  int vetor;
  vetor = (int)malloc(n * sizeof(int));

  return vetor;
}

int mais_proximo(int vet[], int tam, int x) {
  int meio;
  int inicio = 0;
  int fim = tam - 1;
  while ((fim - inicio) > 1) {
    meio = inicio + (fim - inicio) / 2;
    if (x <= vet[meio])
      fim = meio;
    else
      inicio = meio;
  }
  if ((x - vet[inicio]) > (vet[fim] - x))
    return vet[fim];
  else
    return vet[inicio];
}

int main() {
  int *vetor;
  int N, x;
  scanf("%d", &N);
  scanf("%d", &x);

  vetor = alocar(N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &vetor[i]);
  }

  int resultado;
  resultado = mais_proximo(vetor, N, x);
  printf("%d", resultado);

  free(vetor);
  return 0;
}