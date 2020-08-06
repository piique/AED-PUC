#include <stdio.h>
#include <math.h>

int main()
{
  int numerador = 1;
  float soma = 0, denominador = 225; // denominador declarado como float por problemas com alguns compiladores ao usar sqrt

  while (denominador >= 1)
  {
    soma += numerador / denominador;
    printf("%i / %0.0f = %f\n", numerador, denominador, numerador / denominador); // mostra o resultado de cada fração em decimal
    numerador += numerador;
    denominador = pow(sqrt(denominador) - 1.0, 2.0); // pega raiz do denominador, subtrai 1 e eleva ao quadrado
  }

  printf("%0.2f", soma);

  return 0;
}