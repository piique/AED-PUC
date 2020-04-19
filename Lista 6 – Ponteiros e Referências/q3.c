#include <stdio.h>

void nand(int n1, int n2, int *result);

int main()
{
  int num1, num2, result;
  do
  {
    printf("Digite 2 valores booleanos (0 ou 1): ");
    scanf("%i %i", &num1, &num2);
    if ((num1 == 0 || num1 == 1) && (num2 == 0 || num2 == 1))
    {
      nand(num1, num2, &result);
      printf("\n%i nand %i: %i\n\n", num1, num2, result);
    }
    else
    {
      printf("Numeros digitados devem ser 0 ou 1! Tente novamente\n\n");
    }
  } while ((num1 != 0 && num1 != 1) || (num2 != 0 && num2 != 1));

  return 0;
}

/*
Descrição: recebe 2 valores booleanos (int 0 e 1) e 1 ponteiro para retornanr a operação ⌐ (A ^ B).
Entradas: 2 valores inteiros e um endereço de memoria
Saída: Não possui saida, valor alterado por referencia
*/
void nand(int n1, int n2, int *result)
{
  if (!(n1 && n2))
  {
    *result = 1;
  }
  else
  {
    *result = 0;
  }
}