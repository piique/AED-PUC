#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[100];
  int len;
} String;

int main(void) {
  String string[100];
  char input[1000];  // conjunto de palavras
  int count;         // contador de palavras para cada conjunto / qtd palavras
  int index;         // index para cada palavra
  int aux, max, n;

  // começar laco externo
  scanf("%i\n", &n);

  while (n > 0) {
    n--;
    // realiza input de strings
    scanf(" %[^\n]s\n", input);
    fflush(stdin);

    count = 0;
    max = 0;

    // divide input em varias strings e salvas ela no vetor de struct
    for (int i = 0; i < strlen(input); i++) {
      index = 0;
      while (input[i] != ' ' && input[i] != '\0' && input[i] != '\n' && input[i] != '\r') {
        string[count].nome[index++] = input[i++];
      }
      string[count].nome[index] = '\0';
      string[count].len = index;
      if (index > max) {
        max = index;
      }
      count++;
    }

    // for para percorrer todos os elementos do vetor de strings e ir mostrando do maior para o menor
    for (int i = 0; i < max; max--) {
      for (int j = 0; j < count; j++) {
        if (string[j].len == max) {
          printf("%s ", string[j].nome);
        }
      }
    }
    printf("\n");
  }

  return 0;
}
