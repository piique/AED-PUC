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
  int aux = *a, aux1;

  printf("NOME_VARIAVEL | ENDERECO  | VALOR ANTIGO | VALOR  NOVO\n");
  aux = *a;
  *a = *e;
  printf("    a         | %p  |       %i      |     %i\n", a, aux, *a);
  aux1 = *b;
  *b = aux;
  printf("    b         | %p  |       %i      |     %i\n", b, aux1, *b);
  aux = *c;
  *c = aux1;
  printf("    c         | %p  |       %i      |     %i\n", c, aux, *c);
  aux1 = *d;
  *d = aux;
  printf("    d         | %p  |       %i      |     %i\n", d, aux1, *d);
  aux = *e;
  *e = aux1;
  printf("    e         | %p  |       %i     |     %i\n", e, aux, *e);
}