#include <stdio.h>

int main(void) {
  int n1, n2;
  scanf("%i %i", &n1, &n2);

  printf("SOMA = %i\n", n1 + n2);
  printf("SUBTRACAO = %i\n", n1 - n2);
  printf("MULTIPLICACAO = %i\n", n1 * n2);
  if (n2 == 0) {
    printf("DIVISAO = INDETERMINADO");
  } else {
    printf("DIVISAO = %0.2f\n", (float)n1 / n2);
  }
}
