#include <stdio.h>

void media3(float n1, float n2, float n3, float *media);

int main()
{
  float n1 = 10, n2 = 20, n3 = 30, media;

  printf("Digite 3 numeros: ");
  scanf("%f %f %f", &n1, &n2, &n3);
  media3(n1, n2, n3, &media);

  printf("\nMedia: %0.2f\n\n", media);
  return 0;
}

/*
Descrição: recebe 3 numeros e 1 ponteiro para retornar a media
Entradas: 3 float e 1 ponteiros apontanto para float
Saída: Não possui saida, valor alterado por referencia
*/
void media3(float n1, float n2, float n3, float *media)
{
  *media = (n1 + n2 + n3) / 3;
}