#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
int pop(Pilha *p) {
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

// procedimento para printar conteudo da pilha
void print_pilha(Pilha *p) {
  Celula *tmp = p->topo;
  printf("\nTamanho: %d\n", p->tam);
  while (tmp != NULL) {
    printf("%c ", tmp->dado);
    tmp = tmp->prox;
  }
}

// procedimento para ordernar pilha
void sort_stack(Pilha *p) {
  for (int i = 0; i < p->tam - 1; i++) {
    Celula *tmp = p->topo;
    for (int j = 0; j < p->tam - i - 1; j++) {
      if (tmp->dado > tmp->prox->dado) {
        char aux = tmp->dado;
        tmp->dado = tmp->prox->dado;
        tmp->prox->dado = aux;
      }
      tmp = tmp->prox;
    }
  }
}

bool is_empty(Pilha *p) {
  return p->tam == 0;
}

//==================================================
// #endif  // PILHA_H_INCLUDED
