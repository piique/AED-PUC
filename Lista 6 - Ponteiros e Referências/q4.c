#include <stdio.h>

void deslocaEsquerda(int *a, int *b, int *c, int *d, int *e);

int main()
{
  int num1, num2, num3, num4, num5;
  num1 = 5;
  num2 = 9;
  num3 = 1;
  num4 = 6;
  num5 = 19;

  // printf("\nDigite 5 numeros: ");
  // scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);
  deslocaEsquerda(&num1, &num2, &num3, &num4, &num5);
  return 0;
}

/*
Descrição: recebe 5 valores inteiros e desloca seus valores de forma circular para esquerda.
Entradas: 5 endereços de memoria
Saída: Não possui saida, valor alterado por referencia
*/
void deslocaEsquerda(int *a, int *b, int *c, int *d, int *e)
{
  int antigoA = *a, antigoB = *b, antigoC = *c, antigoD = *d, antigoE = *e;
  *a = antigoE;
  *b = antigoA;
  *c = antigoB;
  *d = antigoC;
  *e = antigoD;

  printf("NOME_VARIAVEL | ENDERECO  | VALOR ANTIGO | VALOR  NOVO\n");
  printf("    a         | %p  |       %i      |     %i\n", a, antigoA, *a);
  printf("    b         | %p  |       %i      |     %i\n", b, antigoB, *b);
  printf("    c         | %p  |       %i      |     %i\n", c, antigoC, *c);
  printf("    d         | %p  |       %i      |     %i\n", d, antigoD, *d);
  printf("    e         | %p  |       %i      |     %i\n", e, antigoE, *e);
}