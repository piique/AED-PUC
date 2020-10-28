// #ifndef PILHA1_H_INCLUDED
// #define PILHA1_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

// definição da Pilha
typedef struct Pilha {
  char dados[MAX];
  int topo;
} Pilha;

// funçao para criar pilha
void create_pilha(Pilha *p) {
  p->topo = 0;
}

// funçao para empilhar
bool push(Pilha *p, char dado) {
  if (p->topo == MAX) {
    // printf("\nPilha Cheia!\n");
    return false;
  }

  p->dados[p->topo] = dado;
  p->topo++;
  return true;
}

// função para desempilhar elemento do topo
int pop(Pilha *p) {
  if (p->topo == 0) {
    // printf("\nPilha Vazia!\n");
    return -1;
  }

  p->topo--;
  return p->dados[p->topo];
}

// procedimento para printar pilha
void print_pilha(Pilha *p) {
  printf("\nTamanho: %d\n", p->topo);
  for (int i = p->topo - 1; i >= 0; i--)
    printf("%c ", p->dados[i]);
}

// procedimento para ordernar pilha
void sort_stack(Pilha *p) {
  int tmp = p->topo;
  for (int i = 0; i < p->topo; i++) {
    for (int j = 0; j < p->topo - i - 1; j++) {
      if (p->dados[tmp] > p->dados[j]) {
        char aux = p->dados[j];
        p->dados[j] = p->dados[tmp];
        p->dados[tmp] = aux;
      }
    }
    tmp--;
  }
}

// função para verificar se pilha está vazia
bool is_empty(Pilha *p) {
  return p->topo == 0;
}
