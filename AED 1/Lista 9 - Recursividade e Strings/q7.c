#include <stdio.h>
#include <string.h>

void verificaIgualdade(char[], char[], int);

int main() {
  char v1[100], v2[100];
  printf("Digite duas palavras a serem verificadas: ");
  scanf("%s %s", v1, v2);
  fflush(stdin);
  verificaIgualdade(v1, v2, 100);
}

/*
Descrição: recebe duas strings e verifica sua igualdade
Entradas: recebe duas strings (char[]) e o tamanho delas(int)
Saída: printa na tela se as palavras são iguais ou não
*/
void verificaIgualdade(char *v1, char *v2, int tamanho) {
  if (strncmp(v1, v2, tamanho) == 0) {
    printf("Palavras iguais\n");
  } else {
    printf("Palavras diferentes\n");
  }
}