#include <stdio.h>
#include <string.h>

void ordena(char[], char[], char[]);

int main() {
  char v1[100], v2[100], v3[100];
  printf("Digite 3 palavras a serem verificadas: ");
  scanf("%s %s %s", v1, v2, v3);
  ordena(v1, v2, v3);
  fflush(stdin);
}

void ordena(char v1[], char v2[], char v3[]) {
  char nomes[3][100], aux[100];
  strcpy(nomes[0], v1);
  strcpy(nomes[1], v2);
  strcpy(nomes[2], v3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (strcmp(nomes[j], nomes[i]) > 0) {
        strcpy(aux, nomes[i]);
        strcpy(nomes[i], nomes[j]);
        strcpy(nomes[j], aux);
      }
    }
  }

  for (int i = 0; i < 3; i++)
    printf("%s\n", nomes[i]);
}
