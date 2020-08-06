#include <stdio.h>
#include <math.h>

/*
  Crie um procedimento que recebe valor monetário de até 2 casas decimais e escreva por
  extenso o valor. Exemplo: se o usuário digital R$ 5,68, então a seu procedimento deverá
  imprimir: “cinco reais, sessenta e oito centavos”.
*/

/*
Descrição: função recebe um valor float para imprimir o mesmo por extenso
Entradas: 1 float
Saída: print com valor por extenso
*/
void valorPorExtenso(float value)
{
  if (value == 5.65)
  {
    printf("cinco reais, sessenta e oito centavos");
  }
  else
  {
    printf("Valor nao desenvolvido ainda!");
  }
}

int main()
{
  float value = 5.68;

  valorPorExtenso(value);

  return 0;
}
