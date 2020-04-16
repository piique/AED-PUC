#include <stdio.h>
/*
  Crie uma função que recebe dois valores boleanos (A e B) e retorne o valor verdade da
  operação XOR em relação aos dois valores.
*/

/*
Descrição: função que recebe 10 números e retorna a media
Entradas: 2 inteiros (true ou false: 1 ou 0);
Saída: um valor float
*/
int xorTable(int A, int B)
{
  if (A)
  {
    if (B)
      return 0;
    else
      return 1;
  }
  else
  {
    if (B)
      return 1;
    else
      return 0;
  }
}

void main()
{

  int A = 1,
      B = 1,
      result;

  result = xorTable(A, B);
  if (result == 0)
  {
    printf("\n%i xor %i: false\n\n", A, B);
  }
  else
  {
    printf("\n%i xor %i: true\n\n", A, B);
  }

  return 0;
}