#include <stdio.h>

int main(void) {
  int n, maior, menor;
  scanf("%i", &n);
  int v[n];

  for (int i = 0; i < n; i++) {
    scanf("%i", &v[i]);
  }

  maior = v[0];
  menor = v[0];

  for (int i = 0; i < n; i++) {
    if (v[i] > maior) {
      maior = v[i];
    }
    if (v[i] < menor) {
      menor = v[i];
    }
  }

  printf("MAIOR = %i\n", maior);
  printf("MENOR = %i\n", menor);
}
