#include <stdio.h>
#include <math.h>

/*
  Crie uma função que receba um número real x e calcule a série a seguir:
    sin(x) = x + x³/!3 - x⁵/!5 + x⁷/!7 + ...
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
Descrição: função que receba um número real x e calcule a série a seguir:
    sin(x) = x + x³/!3 - x⁵/!5 + x⁷/!7 + ...
Entradas: não possui
Saída: um valor float
*/ 
float calculaSerie(float x) {
  int aux = 3;
  int soma = 1;
  float serieValue = x;

  // maximo de 4 casas decimais, tanto para positivos quanto para negativos
  while (serieValue < 9999.0 && serieValue > -9999.0) {
    if (soma){
      serieValue += pow(x, aux) / fat(x);
      soma = 0;
    }else { 
      serieValue -= pow(x, aux) / fat(x);
      soma = 1;
    }
    aux += 2;
  }
  return serieValue;  
}

int main()
{
  float x = 5.0;
  printf("\nsin(x) = x + x³/!3 - x⁵/!5 + x⁷/!7 + ...\n\nsin(%0.2f): %0.2f\n\n", x, calculaSerie(x));
  return 0;
}
