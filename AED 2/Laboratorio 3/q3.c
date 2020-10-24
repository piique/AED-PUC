#include <stdio.h>

void insertionsort(float v[], int n);

int main(void) {
  int N, K;
  float notas[10000];

  // input qtd participantes
  scanf("%i", &N);

  // input qtd classificados
  scanf("%i", &K);

  // tratamento de exceção
  if (K > N || K <= 0) {
    K = N;
    printf("%i", K);
    return 0;
  }

  // input de notas
  for (int i = 0; i < N; i++) {
    scanf("%f", &notas[i]);
  }

  // chamada de função para ordenação
  insertionsort(notas, N);

  // for para contar quantas notas a mais do limite de classificação passaram
  for (int i = K; i < N; i++) {
    if (notas[i - 1] == notas[i]) {
      K++;
    } else {
      break;
    }
  }

  printf("%i", K);

  return 0;
}

// metodo de ordenacao por insercao
void insertionsort(float v[], int n) {
  int i, j;
  float aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while (j > -1 && v[j] < aux) {
      v[j + 1] = v[j];
      j -= 1;
    }
    v[j + 1] = aux;
  }
}
