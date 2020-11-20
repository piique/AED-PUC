#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// celular para armazenar vetor de char
typedef struct Celula {
  // char string[100];
  char dado;
  struct Celula *prox;
} Celula;

// definição da Pilha
typedef struct Pilha {
  Celula *topo;
  int tam;
} Pilha;

// procedimento para criar pilha
void create_pilha(Pilha *p) {
  p->topo = NULL;
  p->tam = 0;
}

// funçao para empilhar
bool push(Pilha *p, char dado) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));

  // verifica se pilha está cheia
  if (nova == NULL) {
    // printf("\nPilha Cheia!\n");
    return false;
  }

  nova->dado = dado;

  nova->prox = p->topo;
  p->topo = nova;
  p->tam++;
  return true;
}

// função para desempilhar elemento do topo
char pop(Pilha *p) {
  if (p->tam == 0) {
    // printf("\nPilha Vazia!\n");
    return -1;
  }

  int dado = p->topo->dado;

  Celula *tmp = p->topo;
  p->topo = p->topo->prox;
  free(tmp);

  p->tam--;
  return dado;
}

bool is_empty(Pilha *p) {
  return p->tam == 0;
}

Pilha *concatena_pilha(Pilha *p1, Pilha *p2) {
  Pilha *concatenada = (Pilha *)malloc(sizeof(Pilha));
  Celula *tmp = (Celula *)malloc(sizeof(Pilha));

  concatenada->topo = p2->topo;

  return concatenada;
}

int main(void) {
  int qtd;
  char string[1000], letra, aux;
  scanf("%i", &qtd);

  for (int i = 0; i < qtd; i++) {
    fflush(stdin);
    scanf("%s", string);
    verificaString(string);
  }
}

// // verifica parenteses
// void verificaParenteses(char *string) {
//   Pilha pilha;
//   create_pilha(&pilha);

//   printf("\nVALIDADOR PARENTESES\n");
//   printf("Digite uma expressao: ");
//   scanf("%s", string);

//   int len = strlen(string);

//   for (int i = 0; i < len; i++) {
//     if (string[i] == '(') {
//       push(&pilha, string[i]);
//     } else if (string[i] == ')') {
//       if (pop(&pilha) == -1) {
//         printf("\nExpressão Matemática Incorreta\n");
//         return;
//       }
//     }
//   }
//   if (is_empty(&pilha)) {
//     printf("\nExpressão Matemática Correta\n");
//   } else {
//     printf("\nExpressão Matemática Incorreta\n");
//   }
// }
