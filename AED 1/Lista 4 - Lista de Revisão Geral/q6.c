#include <stdio.h>
#include <math.h>

// função para calcular fatorial
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

  float denominador = 1, e = 0, x;
  int expoente = 1;
  printf("Digite um numero: ");
  scanf("%f", &x);

  if (x < pow(10, -4)) // aceitar apenas numeros maiores que 10^-4
    return 0;

  e = 1; // x^0 - primeiro numero da sequencia

  for (int i = 0; i < 20; i++) // for para rodar 20 vezes
  {
    e += pow(x, expoente) / fat(denominador);
    // printf("\nExpoente: %i Denominador: %f", expoente, fat(denominador));
    expoente++;
    denominador++;
  }

  printf("Valor de e^%0.2f: %f", x, e);

  return 0;
}
