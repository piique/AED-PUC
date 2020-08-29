#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// declaracao de funcao
bool ehPalindromo(char v[], int tamanho);

int main(void) {
  // vetor de string para armazenar input do usuario
  char v[500];

  while (true) {
    v[0] = '\0';
    // input de string pegando espacos
    scanf("\n%[^\n]s", v);

    // limpa buffer do teclado
    setbuf(stdin, NULL);

    // verifica se string eh igual a FIM
    if (v[0] == 'F' && v[1] == 'I' && v[2] == 'M') {
      return 0;
    }

    // verifica se eh palindromo atraves da funcao e printa saida
    if (ehPalindromo(v, strlen(v))) {
      printf("SIM\n");
    } else {
      printf("NAO\n");
    }
  }
  return 0;
}

// Descrição: recebe uma string e verifica se eh palindromo desconsiderando
// espacos vazios.
// Entradas: recebe 1 strings (char[]) e seu tamanho (int)
// Saída: true para eh palindromo e false para nao palindromo
bool ehPalindromo(char v[], int tamanho) {
  char aux[tamanho];
  int count = 0;  // armazenar quantidade de caracteres presentes no aux

  // for para retirar espacos em branco e transformar letras maiusculas em minusculas
  for (int i = 0; i < tamanho; i++) {
    if (v[i] != ' ' && v[i] != '\n' && v[i] != '\r') {
      aux[count] = tolower(v[i]);
      count++;
    }
  }

  // finalizar string aux com '\0'
  if (count < tamanho - 1)
    aux[count] = '\0';

  int j = count - 1;
  int i = 0;

  while (i < j) {
    if (aux[i] != aux[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
