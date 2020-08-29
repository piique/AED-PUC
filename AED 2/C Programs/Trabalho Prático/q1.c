#include <stdio.h>

int main(void) {
  int n, count = 0;
  int v[2000];

  // recebe quantidade de numeros que serao recebidos
  scanf("%i", &n);

  // preenche vetor
  for (int i = 0; i < n; i++) {
    scanf("%i", &v[i]);
  }

  ordenaVetor(v, n);

  // for para realizar a contagem de numeros repetidos e printa-los
  for (int i = 0; i < n; i++) {
    count++;
    if (v[i] != v[i + 1]) {
      printf("%i aparece %i vez(es)\n", v[i], count);
      count = 0;
    }
  }
  return 0;
}

// realiza ordenação do vetor através do método bolha
void ordenaVetor(int v[], int n) {
  int aux;
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i] > v[i + 1]) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }
}
