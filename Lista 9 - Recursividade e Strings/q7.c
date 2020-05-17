#include <stdio.h>
#include <string.h>

void verificaIgualdade(char[], char[], int, int);

int main() {
  char v1[100], v2[100];
  printf("Digite duas palavras a serem verificadas: ");
  scanf("%s %s", v1, v2);
  fflush(stdin);

  // utilizacao da funcao strncmp para verificar igualdade
  if (strncmp(v1, v2, 100) == 0) {
    printf("Palavras iguais\n");
  } else {
    printf("Palavras diferentes\n");
  }
  // verificaIgualdade(v1, v2, 100, 100);
}