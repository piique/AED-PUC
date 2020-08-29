#include <stdio.h>

int main() {
  char nomeArquivo[50] = "exemplo.txt";
  FILE *fp = fopen(nomeArquivo, "w");

  int n = 10, aux;
  for (int i = 0; i < n; i++) {
    scanf("%i", &aux);
    fprintf(fp, "%i ", aux);
  }
  fclose(fp);

  FILE *p = fopen(nomeArquivo, "r");

  for (int i = 0; i < n; i++) {
    fscanf(p, "%i ", &aux);
    printf("%i ", aux);
  }

  fclose(p);

  return 0;
}
