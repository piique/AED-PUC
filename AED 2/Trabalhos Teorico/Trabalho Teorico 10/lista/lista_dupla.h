#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

typedef struct Celula {
  Pessoa dado;
  struct Celula *prox;
  struct Celula *ant;
} Celula;

typedef struct Lista {
  Celula *inicio;
  Celula *fim;
  int qtd;
} Lista;

void create_lista(Lista *l) {
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->prox = NULL;
  tmp->ant = NULL;

  l->inicio = tmp;
  l->fim = tmp;
  l->qtd = 0;
}

bool add_lista(Lista *l, Pessoa p) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));

  if (nova == NULL) {
    printf("\nLista Cheia!\n");
    return false;
  }

  nova->dado = p;
  nova->prox = NULL;

  l->fim->prox = nova;
  nova->ant = l->fim;
  l->fim = nova;
  l->qtd++;

  return true;
}

void print_lista(Lista *l) {
  Celula *tmp = l->inicio->prox;

  while (tmp != NULL) {
    print_pessoa(tmp->dado);
    tmp = tmp->prox;
  }
}

void print_lista_invertida(Lista *l) {
  Celula *tmp = l->fim;

  while (tmp->ant != NULL) {
    print_pessoa(tmp->dado);
    tmp = tmp->ant;
  }
}

bool update_lista(Lista *l, Pessoa p) {
  bool achou = false;

  for (Celula *tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    if (tmp->dado.codigo == p.codigo) {
      tmp->dado = p;
      achou = true;
      break;
    }
  }

  if (achou)
    return true;
  else {
    printf("\nPessoa nao encontrado na lista!\n");
    return false;
  }
}

bool delete_lista(Lista *l, int codigo) {
  bool achou = false;
  Celula *ant, *tmp;

  for (ant = l->inicio, tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox) {
    if (tmp->dado.codigo == codigo) {
      ant->prox = tmp->prox;

      if (tmp->prox == NULL)
        l->fim = ant;
      else
        tmp->prox->ant = ant;

      free(tmp);
      l->qtd--;
      achou = true;
      break;
    }
  }

  if (achou)
    return true;
  else {
    printf("\nPessoa nao encontrado na lista!\n");
    return false;
  }
}

#endif  // FILA_H_INCLUDED
