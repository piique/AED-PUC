#include <stdio.h>

int qtdDigitos(int a);

int main()
{
  int n = 123456;
  // int count = 0;

  // while (n % 10 < 10 && n % 10 > 0)
  // {
  //   n = n / 10;
  //   count++;
  // }

  printf("\nQuantidade de digitos do inteiro eh: %i", qtdDigitos(n));
  return 0;
}

int qtdDigitos(int a)
{
  int count = 1;
  if (a < 10)
  {
    return 1;
  }
  else
  {
    count += qtdDigitos(a / 10);
    return count;
  }
}