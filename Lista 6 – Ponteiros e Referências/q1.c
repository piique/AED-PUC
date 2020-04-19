#include <stdio.h>

void maiorEMenor(float n1, float n2, float n3, float *min, float *max);

int main()
{
  float n1 = 10, n2 = 9, n3 = 12, menor, maior;

  // printf("Digite 3 numeros: ");
  // scanf("%f %f %f", &n1, &n2, &n3);
  maiorEMenor(n1, n2, n3, &menor, &maior);

  printf("\nMair elemento: %0.2f\nMenor elemento: %0.2f \n", maior, menor);
  return 0;
}

/*
Descrição: recebe 3 numeros e 2 ponteiros para retornar o maior e menor valor recebido
Entradas: 3 float e 2 ponteiros apontanto para float
Saída: Não possui saida, valor alterado por referencia
*/
void maiorEMenor(float n1, float n2, float n3, float *min, float *max)
{
  *max = n1;
  *min = n1;

  // maior elemento
  if (n1 > n2)
  {
    *max = n1;
  }
  else
  {
    *max = n2;
  }
  if (n3 > *max)
  {
    *max = n3;
  }

  // menor elemento
  if (n1 < n2)
  {
    *min = n1;
  }
  else
  {
    *min = n1;
  }
  if (n3 < *min)
  {
    *min = n3;
  }
}