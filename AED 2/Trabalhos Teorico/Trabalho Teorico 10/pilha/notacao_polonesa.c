#include <stdlib.h>
#include <string.h>

#include "pilha_dinamica.h"
// #include "pilha_estatica.h"

int main() {
  Pilha pilha;
  char letra;

  int ultimo, penultimo;
  create_pilha(&pilha);

  scanf("%c", &letra);

  while (letra != '\n') {
    switch (letra) {
      case '*':
        ultimo = pop(&pilha);
        penultimo = pop(&pilha);
        push(&pilha, penultimo * ultimo);
        printf("%i\n", penultimo * ultimo);
        break;
      case '/':
        ultimo = pop(&pilha);
        penultimo = pop(&pilha);
        push(&pilha, penultimo / ultimo);
        printf("%i\n", penultimo / ultimo);
        break;
      case '+':
        ultimo = pop(&pilha);
        penultimo = pop(&pilha);
        push(&pilha, penultimo + ultimo);
        printf("%i\n", penultimo + ultimo);
        break;
      case '-':
        ultimo = pop(&pilha);
        penultimo = pop(&pilha);
        push(&pilha, penultimo - ultimo);
        printf("%i\n", penultimo - ultimo);
        break;
      default:
        push(&pilha, letra - '0');
        break;
    }
    scanf("\n%c", &letra);
  }

  fflush(stdin);
}
