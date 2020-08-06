#include <stdio.h>

int somaDigitos(int a);

int main()
{
  int n = 45;

  printf("\nSoma dos digitos do inteiro eh: %i", somaDigitos(n));
  return 0;
}

int somaDigitos(int a)
{
  int soma = 0;
  if (a < 10)
  {
    return a;
  }
  else
  {
    soma += somaDigitos(a / 10) + a % 10;
    return soma;
  }
}