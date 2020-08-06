#include <stdio.h>

int divisao(int n1, int n2);

int main()
{
  int n1 = 20, n2 = 4;

  // printf("Digite 2 numeros: ");
  // scanf("%i %i", &n1, &n2);

  printf("\nResultado da divisao de %i por %i eh: %i", n1, n2, divisao(n1, n2));
  return 0;
}

int divisao(int a, int b)
{
  if (a - b < 0)
  {
    return 0;
  }
  return divisao(a - b, b) + 1;
}