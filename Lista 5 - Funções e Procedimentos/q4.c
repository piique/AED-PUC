#include <stdio.h>
#include <math.h>
/*
  Crie um procedimento que calcule e escreva a soma dos 20 primeiros números da série:
  100/!0 + 99/!1 + 98/!2 + 97/!3 + 96/!4 ... + 1/!99
*/

/*
Descrição: função que um numero e retorna seu fatorial
Entradas: um valor inteiro
Saída: um valor float
*/
float fat(int n)
{
  float fat = 1;
  while (n > 1)
  {
    fat = fat * n;
    n--;
  }
  return fat;
}

/*
Descrição: procedimento que calcula e imprime a sequencia: 
  100/!0 + 99/!1 + 98/!2 + 97/!3 + 96/!4 ... + 1/!99
Entradas: não possui
Saída: um valor float
*/
void calculaSerie()
{
  float numerador = 100, denominador = 0, soma = 0;

  for (int i = 0; i < 20; i++) // for para rodar 20 vezes
  {
    soma += numerador / fat(denominador);
    // printf("Soma: %f Denominador: %f\n", soma, fat(denominador));
    // printf("%f / %f! = %f\n", numerador, denominador, numerador / fat(denominador)); // mostra o resultado de cada fração em decimal
    numerador--;
    denominador++;
  }

  printf("\nSoma total: %0.2f\n\n", soma);
}

int main()
{
  calculaSerie();
  return 0;
}
