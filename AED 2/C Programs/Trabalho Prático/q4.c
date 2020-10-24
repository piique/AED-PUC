#include <stdio.h>
#include <string.h>

//declaração de função
void criptografaString(char v[], int i, int len);

int main(void) {
  char v[1000], aux;

  // rodar ate encontrar string FIM
  scanf(" %[^\n]s", v);
  while (v[0] != 'F' && v[1] != 'I' && v[2] != 'M') {
    criptografaString(v, 0, strlen(v));
    scanf(" %[^\n]s", v);
  }

  return 0;
}

// função recusrsiva para criptografar letra por letra em cada chamada
void criptografaString(char v[], int i, int len) {
  if (i < len) {
    // verifica se chegou ao final da string atraves da palavra FIM
    if (v[i] == 'F' && v[i + 1] == 'I' && v[i + 2] == 'M') {
      return;
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
      printf("%c", v[i] - 23);
    }

    // chama a função novamente para a proxima letra ser criptografada
    criptografaString(v, ++i, len);
  }
}