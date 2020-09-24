#include <stdio.h>

void shellsort(int *vet, int n);
void bolha(int *v, int n);
void bolhaDecrescente(int *v, int n);
void substituiArrayOriginal(int *v, int n, int *vPar, int auxPar, int *vImpar, int auxImpar);

int main(void) {
  int n, auxPar = 0, auxImpar = 0;
  int vPar[1000], vImpar[1000], v[1000];

  scanf("%i\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("\n%i", &v[i]);
  }

  // separa em 2 arrays (Par e Impar)
  for (int i = 0; i < n; i++) {
    if (v[i] % 2 == 0) {
      vPar[auxPar++] = v[i];
    } else {
      vImpar[auxImpar++] = v[i];
    }
  }

  bolha(vPar, auxPar);
  bolhaDecrescente(vImpar, auxImpar);
  substituiArrayOriginal(v, n, vPar, auxPar, vImpar, auxImpar);

  return 0;
}

// metodo de ordenação bolha
void bolha(int *v, int n) {
  int i, j, temp;
  for (i = n - 1; i >= 1; i--) {
    for (j = 0; j < i; j++) {
      if (v[j] > v[j + 1]) {
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

// metodo de ordenação bolha decrescente
void bolhaDecrescente(int *v, int n) {
  int i, j, temp;
  for (i = n - 1; i >= 1; i--) {
    for (j = 0; j < i; j++) {
      if (v[j] < v[j + 1]) {
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

// função para substituir valores no array original enquanto printa os mesmos
void substituiArrayOriginal(int *v, int n, int *vPar, int auxPar, int *vImpar, int auxImpar) {
  int aux = 0;
  for (int i = 0; i < n; i++) {
    if (i < auxPar) {
      v[i] = vPar[i];
    } else {
      v[i] = vImpar[aux++];
    }
    printf("%i\n", v[i]);
  }
}
