#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

typedef struct Celula {
  Pessoa dado;
  struct Celula *prox;
} Celula;

typedef struct Fila {
  Celula *inicio;
  Celula *fim;
  int tam;
} Fila;

// cria fila
void create_fila(Fila *f) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->prox = NULL;

  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}

// ennfilar com prioridade
bool enfila_prioridade(Fila *f, Pessoa dado) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  if (nova == NULL)
    return false;
  nova->prox = NULL;
  nova->dado = dado;

  Celula *ant = f->inicio;

  while (ant->prox != NULL && ant->prox->dado.idade >= 65)
    ant = ant->prox;

  // while (ant->prox != NULL && dado.idade >= ant->prox->dado.idade)
  //   ant = ant->prox;

  nova->prox = ant->prox;
  ant->prox = nova;

  if (nova->prox == NULL)
    f->fim = nova;

  f->tam++;

  return true;
}

// Enfilar
bool enfila(Fila *f, Pessoa dado) {
  if (dado.idade >= 65)
    return enfila_prioridade(f, dado);

  Celula *nova = (Celula *)malloc(sizeof(Celula));
  if (nova == NULL)
    return false;
  nova->prox = NULL;
  nova->dado = dado;

  f->fim->prox = nova;
  f->fim = nova;
  f->tam++;

  return true;
}

// função para printar fila
void print_fila(Fila *f) {
  Celula *tmp = f->inicio->prox;

  printf("\nTamanho: %d\n", f->tam);
  while (tmp != NULL) {
    print_pessoa(tmp->dado);
    tmp = tmp->prox;
  }
}

// função para desenfilar elemento e retornar ele
Pessoa desenfila(Fila *f) {
  if (f->tam == 0) {
    return invalida_pessoa();
  }

  Celula *tmp = f->inicio;
  f->inicio = f->inicio->prox;
  free(tmp);

  f->tam--;
  return f->inicio->dado;
}

#endif  // FILA_H_INCLUDED
