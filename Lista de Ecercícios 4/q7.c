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

  float px = -1, py, qx, qy, distancia;

  printf("Para sair do programa digite a cordenada 0 para todos os pontos.\n");

  while (px != 0, py != 0, qx != 0, qy != 0)
  {
    printf("\nDigite o valor dos pontos P (x, y)  e Q (x, y)\n Px: ");
    scanf("%f", &px);
    printf("Py: ");
    scanf("%f", &py);
    printf("Qx: ");
    scanf("%f", &qx);
    printf("Qy: ");
    scanf("%f", &qy);

    distancia = pow(pow(qx - px, 2) + pow(qy - py, 2), 1 / 2);
    printf("Distancia entre os pontos P e Q e: %f\n", distancia);
  }
}
