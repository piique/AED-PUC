//Faça um algoritmo para ler dois inteiros (variáveis A e B) e efetuar as operações de adição,
// subtração, multiplicação e divisão de A por B apresentando ao final os quatro resultados obtidos.
#include <stdio.h>

int main(void) {
  int a, b, c, maior, menor;
  scanf("%i %i %i", &a, &b, &c);

  if (a >= b && a >= c) {
    printf("MAIOR = %i\n", a);
  } else if (b >= a && b >= c) {
    printf("MAIOR = %i\n", b);
  } else if (c >= a && c >= b) {
    printf("MAIOR = %i\n", c);
  }

  if (a <= b && a <= c) {
    printf("MENOR = %i\n", a);
  } else if (b <= a && b <= c) {
    printf("MENOR = %i\n", b);
  } else if (c <= a && c <= b) {
    printf("MENOR = %i\n", c);
  }
}
