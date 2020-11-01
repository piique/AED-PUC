#ifndef FILA2_H_INCLUDED
#define FILA2_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#define MAX 100

typedef struct Fila {
  Pessoa dados[MAX];
  int inicio, fim;
  int tam;
} Fila;

// cria fila
void create_fila(Fila *f) {
  f->inicio = 0;
  f->fim = 0;
  f->tam = 0;
}

// insere elementos em suas posiçoes corretas apos inserir nova pessoa prioritaria
bool insere_posicao(Fila *f, Pessoa dado, int index) {
  int id, idade;
  char nome[100];

  Pessoa aux;

  aux = f->dados[index];

  f->dados[index] = dado;

  f->fim = (f->fim + 1) % MAX;
  f->tam++;

  for (int i = index + 1; i <= f->fim; i++) {
    dado = f->dados[i];
    f->dados[i] = aux;
    aux = dado;
  }

  return true;
}

// ennfilar com prioridade
bool enfila_prioridade(Fila *f, Pessoa dado) {
  int pos = (f->inicio + 1) % MAX;
  for (int i = 0; i < f->tam; i++) {
    if (f->dados[pos].idade < 65) {
      return insere_posicao(f, dado, pos);
    }
    pos = (f->inicio + 1) % MAX;
  }

  return insere_posicao(f, dado, (f->inicio + 1) % MAX);
}

// Enfilar
bool enfila(Fila *f, Pessoa dado) {
  if ((f->fim + 1) % MAX == f->inicio)
    return false;

  if (dado.idade >= 65)
    return enfila_prioridade(f, dado);

  f->fim = (f->fim + 1) % MAX;
  f->dados[f->fim] = dado;
  f->tam++;

  return true;
}

// função para printar fila
void print_fila(Fila *f) {
  int pos = (f->inicio + 1) % MAX;

  for (int i = 0; i < f->tam; i++) {
    print_pessoa(f->dados[pos]);
    pos = (pos + 1) % MAX;
  }
}

// função para printar processos
void print_processos(Fila *f) {
  int pos = (f->inicio + 1) % MAX;

  for (int i = 0; i < f->tam; i++) {
    printf("ID: %i ; NOME: %s ; TEMPO: %i ;\n", f->dados[pos].id, f->dados[pos].nome, f->dados[pos].idade);
    pos = (pos + 1) % MAX;
  }
}

// função para desenfilar elemento e retornar ele
Pessoa desenfila(Fila *f) {
  if (f->tam == 0) {
    return invalida_pessoa();
  }

  f->inicio = (f->inicio + 1) % MAX;
  f->tam--;
  return f->dados[f->inicio];
}

#endif  // FILA_H_INCLUDED
