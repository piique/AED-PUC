#include <stdio.h>
#include <string.h>

int ehPalindromoRecursivo(char *);
int _ehPalindromoRecursivo(char *v, int i, int j);

int main() {
  char v1[100];
  printf("Digite uma palavra: ");
  scanf("%s", v1);
  fflush(stdin);
  ehPalindromo(v1);
}

/*
Descrição: recebe uma string e verifica se eh palindromo atraves da chamada de funcao recursiva
Entradas: recebe 1 strings (char[])
Saída: printa na tela se eh palindromo ou nao
*/
int ehPalindromoRecursivo(char *v) {
  int i = 0;
  int j = strlen(v) - 1;
  return _ehPalindromoRecursivo(v, i, j);
}

int _ehPalindromoRecursivo(char *v, int i, int j) {
  if (v[i] != v[j]) {
    printf("\nNao eh palindromo\n");
    return -1;
  } else if (j == -1) {
    printf("\nEh palindromo\n");
    return 1;
  }

  return _ehPalindromoRecursivo(v, ++i, --j);
}