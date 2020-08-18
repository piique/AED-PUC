#include <stdio.h>

int main(void) {
  char v[1000], aux;

  scanf(" %[^\n]s", &v);

  // for para percorrer toda a string
  for (int i = 0; v[i] != '\0'; i++) {
    // verifica se chegou ao final da string atraves da palavra FIM
    if (v[i] == 'F' && v[i + 1] == 'I' && v[i + 2] == 'M') {
      return 0;
    }
    // verifica se caracter esta contitido no alfabeto de acordo com a tabela ascii (imprimir espacos vazios)
    if ((v[i] >= 65 && v[i] <= 87) || (v[i] >= 97 && v[i] <= 119))
      // adiciona 3 numeros a letra caso nao seja uma das 3 ultimas
      printf("%c", v[i] + 3);
    else {
      printf(" ");
    }

    // verifica se as letras sao as 3 ultimas do alfabeto
    if ((v[i] >= 120 && v[i] <= 122) || (v[i] >= 88 && v[i] <= 90)) {
      if (v[i] == 'X') {
        printf("A");
      } else if (v[i] == 'x') {
        printf("a");
      } else if (v[i] == 'Y') {
        printf("B");
      } else if (v[i] == 'y') {
        printf("b");
      } else if (v[i] == 'Z') {
        printf("B");
      } else if (v[i] == 'z') {
        printf("b");
      }
    }
  }

  return 0;
}
