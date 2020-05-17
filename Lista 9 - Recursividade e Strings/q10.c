#include <stdio.h>
#include <string.h>

int ehPalindromo(char *);
int _ehPalindromo(char *v, int i, int j);

int main() {
  char v1[100];
  printf("Digite uma palavra: ");
  scanf("%s", v1);
  fflush(stdin);
  ehPalindromo(v1);
}

int ehPalindromo(char *v) {
  int i = 0;
  int j = strlen(v) - 1;
  return _ehPalindromo(v, i, j);
}

int _ehPalindromo(char *v, int i, int j) {
  if (v[i] != v[j]) {
    printf("\nNao eh palindromo\n");
    return -1;
  } else if (j == -1) {
    printf("\nEh palindromo\n");
    return 1;
  }

  return _ehPalindromo(v, ++i, --j);
}