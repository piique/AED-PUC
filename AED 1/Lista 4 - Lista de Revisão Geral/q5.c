#include <stdio.h>
#include <math.h>

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

int main()
{

  float numerador = 100, denominador = 0, soma = 0;

  for (int i = 0; i < 20; i++) // for para rodar 20 vezes
  {
    soma += numerador / fat(denominador);
    printf("Soma: %f Denominador: %f\n", soma, fat(denominador));
    printf("%f / %f! = %f\n", numerador, denominador, numerador / fat(denominador)); // mostra o resultado de cada fração em decimal
    numerador--;
    denominador++;
  }

  printf("Soma total: %0.2f", soma);

  return 0;
}
