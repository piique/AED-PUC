#include <stdio.h>
#include <stdlib.h>
void misterio1(int xval)
{
  int x;
  x = xval;
  printf("\nValor de x: %i", x);
}

void misterio2(int nada)
{
  int y;
  printf("\nValor de y: %i", y);
}

int main()
{
  misterio1(7);
  misterio2(11);
  return 0;
}