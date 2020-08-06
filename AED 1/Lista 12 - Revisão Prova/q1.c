#include <stdio.h>

struct Coordenada {
  int x, y, z;
};

int main() {
  FILE* fp;
  char nome_arquivo[100];
  struct Coordenada pontos[4];
  printf("Digite o nome do arquivo: ");
  scanf("%s", nome_arquivo);

  fp = fopen(nome_arquivo, "r");

  if (fp == NULL) {
    return 0;
  }

  for (int i = 0; i < 4; i++) {
    fscanf(fp, "%i %i %i\n", &pontos[i].x, &pontos[i].y, &pontos[i].z);
    printf("%i %i %i\n", pontos[i].x, pontos[i].y, pontos[i].z);
  }

  fclose(fp);
  return 0;
}
