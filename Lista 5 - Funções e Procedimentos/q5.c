#include <stdio.h>
#include <math.h>
/*
  Crie uma função que calcule e retorne o seguinte somatório:
  S = 1/225 + 2/196 + 3/169 ... + 16384/1
*/

/*
Descrição: procedimento que calcula e imprime a sequencia: 
  S = 1/225 + 2/196 + 3/169 ... + 16384/1
Entradas: não possui
Saída: um valor float
*/
void calculaSomatorio(){
  int numerador = 1;
  float soma = 0, 
        denominador = 225; // denominador declarado como float por problemas com alguns compiladores ao usar sqrt

  while (denominador >= 1)
  {
    soma += numerador / denominador;
    // printf("%i / %0.0f = %f\n", numerador, denominador, numerador / denominador); // mostra o resultado de cada fração em decimal
    numerador += numerador;
    denominador = pow(sqrt(denominador) - 1.0, 2.0); // pega raiz do denominador, subtrai 1 e eleva ao quadrado
  }

  printf("%0.2f", soma);
}

int main()
{
  calculaSomatorio();
  return 0;
}
