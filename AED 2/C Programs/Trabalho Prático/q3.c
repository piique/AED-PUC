#include <stdio.h>

// declaracao de funcao
void ciframento(char *v);

int main(void) {
  char v[1000], aux;

  // leitura de string
  scanf(" %[^\n]s", &v);

  // verifica se chegou ao final da string atraves da palavra FIM
  while (v[0] != 'F' && v[1] != 'I' && v[2] != 'M') {
    // chamada de funcao para criptografar
    ciframento(v);

    // leitura de proxima string
    scanf(" %[^\n]s", &v);
  }
}

void ciframento(char *v) {
  // for para percorrer toda a string
  for (int i = 0; v[i] != '\0'; i++) {
    // verifica se chegou ao final da string atraves da palavra FIM
    if (v[i] == 'F' && v[i + 1] == 'I' && v[i + 2] == 'M') {
      return;
    }
    // verifica se caracter esta contitido no alfabeto de acordo com a tabela ascii (imprimir espacos vazios)
    if ((v[i] >= 65 && v[i] <= 87) || (v[i] >= 97 && v[i] <= 119))
      // adiciona 3 numeros a letra caso nao seja uma das 3 ultimas
      printf("%c", v[i] + 3);
    // verifica se as letras sao as 3 ultimas do alfabeto
    else if ((v[i] >= 120 && v[i] <= 122) || (v[i] >= 88 && v[i] <= 90))
      v[i] = v[i] - 23;
    else
      printf(" ");
  }
}
