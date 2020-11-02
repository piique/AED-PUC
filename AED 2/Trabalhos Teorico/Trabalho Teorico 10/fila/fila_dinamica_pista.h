#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Aviao {
  int id;
  char nome[100];
  float combustivel;
} Aviao;

typedef struct Celula {
  Aviao dado;
  struct Celula *prox;
} Celula;

typedef struct Fila {
  Celula *inicio;
  Celula *fim;
  int tam;
} Fila;

// printa avião
void print_aviao(Aviao p) {
  printf("ID: %d, NOME: %s, COMBUSTIVEL: %0.2f\n", p.id, p.nome, p.combustivel);
}

// funçao para receber novo avião do usuasio
Aviao novo_aviao() {
  Aviao p;

  p.id = rand() % 1000;
  printf("Digite o nome do Aviao: ");
  scanf("%s", p.nome);
  fflush(stdin);
  printf("Digite a quantidade de combistivel do aviao: ");
  scanf("%f", &p.combustivel);

  return p;
}

// funçao para retornar aviao invalido
Aviao invalida_aviao() {
  Aviao p;

  p.id = -1;
  sprintf(p.nome, "Aviao: %d", p.id);
  p.combustivel = 0;

  return p;
}

// procedimento para cria fila
void create_fila(Fila *f) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->prox = NULL;

  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}

// ennfilar com prioridade de combustivel, os que possuem mais de 50 possuem a prioridade
bool enfila_prioridade(Fila *f, Aviao dado) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  if (nova == NULL)
    return false;
  nova->prox = NULL;
  nova->dado = dado;

  Celula *ant = f->inicio;

  while (ant->prox != NULL && ant->prox->dado.combustivel >= 50)
    ant = ant->prox;

  nova->prox = ant->prox;
  ant->prox = nova;

  if (nova->prox == NULL)
    f->fim = nova;

  f->tam++;

  return true;
}

// Enfilar
bool enfila(Fila *f, Aviao dado) {
  if (dado.combustivel >= 50)
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

  printf("\nQuantidade de avioes: %d\n", f->tam);
  while (tmp != NULL) {
    print_aviao(tmp->dado);
    tmp = tmp->prox;
  }
}

// função para desenfilar elemento e retornar ele
Aviao desenfila(Fila *f) {
  if (f->tam == 0) {
    return invalida_aviao();
  }

  Celula *tmp = f->inicio;
  f->inicio = f->inicio->prox;
  free(tmp);

  f->tam--;
  return f->inicio->dado;
}

#endif  // FILA_H_INCLUDED
