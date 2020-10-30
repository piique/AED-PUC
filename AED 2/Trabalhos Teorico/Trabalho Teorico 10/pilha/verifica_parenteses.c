#include <stdio.h>

#include "pilha_dinamica.h"
// #include "pilha_estatica.h"

// declaração de procedimento
void verificaParenteses();

int main() {
  // chamada de procedimento para verificação de parenteses
  verificaParenteses();
  return 0;
}

// procedimento para validar parenteses de uma expressão matemática
void verificaParenteses() {
  char string[100];
  Pilha pilha;
  create_pilha(&pilha);

  printf("\n\nVALIDADOR PARENTESES\n");
  printf("Digite uma expressao: ");
  scanf("%s", string);

  int len = strlen(string);

  for (int i = 0; i < len; i++) {
    if (string[i] == '(') {
      push(&pilha, string[i]);
    } else if (string[i] == ')') {
      if (pop(&pilha) == -1) {
        printf("\nExpressão Matemática Incorreta\n");
        return;
      }
    }
  }
  if (is_empty(&pilha)) {
    printf("\nExpressão Matemática Correta\n");
  } else {
    printf("\nExpressão Matemática Incorreta\n");
  }
}
