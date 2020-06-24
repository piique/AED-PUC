#include <stdio.h>

int main() {
  FILE* fp;
  char texto[100];

  fp = fopen("arquivo.txt", "w");

  printf("Digite alguma coisa: ");
  scanf(" %[^\n]s", texto);

  fprintf(fp, "%s\n", texto);

  fclose(fp);
  return 0;
}
