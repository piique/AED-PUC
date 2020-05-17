#include <stdio.h>
#include <string.h>

void ehPalindromo(char *);

int main() {
  char v1[100];
  printf("Digite uma palavra: ");
  scanf("%s", v1);
  fflush(stdin);
  ehPalindromo(v1);
}

void ehPalindromo(char *v) {
  int j = strlen(v) - 1;
  int i = 0;
  while (i < strlen(v)) {
    if (v[i] != v[j]) {
      printf("\nNao eh palindromo\n");
      return;
    }
    i++;
    j--;
  }
  printf("\nEh palindromo\n");
}