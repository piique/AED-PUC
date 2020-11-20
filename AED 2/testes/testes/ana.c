#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//procedimento para ordenar vetor
void ordena(char text[], int n) {
  int aux, menor;

  for (int i = 0; i < n; i++) {
    text[i] = tolower(text[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    menor = i;
    for (int j = i + 1; j < n; j++) {
      if (text[menor] > text[j]) {
        menor = j;
      }
    }
    aux = text[menor];
    text[menor] = text[i];
    text[i] = aux;
  }
}

void frequencia(char text[]) {
  char letra[26];
  int tam, cont = 0, maior = 0, aux = 0;

  tam = strlen(text);

  ordena(text, tam);

  //zerando letra
  for (int i = 0; i < 26; i++) {
    letra[i] = 0;
  }

  for (int i = 0; i < tam; i++) {
    if (text[i] >= 97 && text[i] <= 122) {
      cont++;
      if (text[i] != text[i + 1]) {
        letra[text[i] - 97] = cont;
        cont = 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (maior < letra[i]) {
      maior = letra[i];
    }
  }
  printf("\nMaior: %i\n", maior);

  for (int i = 0; i < 26; i++) {
    if (maior == letra[i]) {
      printf("%c", i + 97);
    }
  }
}

int main() {
  char text[1000];
  int n, aux = 0;

  scanf("%i", &n);

  while (aux < n) {
    scanf("\n%[^\n]s", &text);
    printf("%s", text);
    frequencia(text);
    aux++;
  }

  return 0;
}