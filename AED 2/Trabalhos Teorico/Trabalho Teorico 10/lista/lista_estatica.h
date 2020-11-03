#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "quicksort.h"

#define QTD_MAX 40

typedef struct Lista {
  Pessoa *dados;
  int MAX;
  int qtd;
} Lista;

// procedimento para inicializar lista
void create_lista(Lista *l) {
  l->MAX = QTD_MAX;
  l->dados = (Pessoa *)malloc(QTD_MAX * sizeof(Pessoa));
  l->qtd = 0;
}

// função para adicionar novo elemento na lista
bool add_lista(Lista *l, Pessoa p) {
  if (l->qtd == l->MAX) {
    printf("\nLista cheia!\n");
    return false;
  }

  p.codigo = l->qtd + 1;

  l->dados[l->qtd++] = p;

  return true;
}

// procedimento para printar conteudo da lista
void print_lista(Lista *l) {
  for (int i = 0; i < l->qtd; i++)
    print_pessoa(l->dados[i]);
}

// função para atualizar dados de um elemento da lista
bool update_lista(Lista *l, Pessoa p) {
  if (p.codigo <= 0 || p.codigo > l->qtd) {
    printf("Pessoa nao encontrada na lista");
    return false;
  }

  l->dados[p.codigo - 1] = p;
  return true;
}

// função para deletar elemento da lista pelo codigo
bool delete_lista(Lista *l, int codigo) {
  if (codigo <= 0 || codigo > l->qtd) {
    printf("Pessoa nao encontrada na lista");
    return false;
  }

  for (int i = codigo; i < l->qtd; i++) {
    l->dados[i - 1] = l->dados[i];
    l->dados[i - 1].codigo--;
  }

  l->qtd--;
  return true;
}

// procedimento para clonar uma lista em outra
void clonar(Lista *l, Lista *clonada) {
  create_lista(clonada);
  Pessoa pessoa;

  for (int i = 0; i < l->qtd; i++) {
    pessoa = l->dados[i];
    add_lista(clonada, pessoa);
  }
}

// procedimento para concatenar duas listas em uma terceira
void concatenar(Lista *l, Lista *l2, Lista *concatenada) {
  create_lista(concatenada);
  Pessoa pessoa;

  // clona lista 1 para concatenada
  clonar(l, concatenada);

  // junta lista 2 ao final da lista concatenada
  for (int i = 0; i < l->qtd; i++) {
    pessoa = l2->dados[i];
    add_lista(concatenada, pessoa);
  }
}

// procedimento para inverter elementos da lista
void inverter(Lista *l) {
  Lista clone;

  create_lista(&clone);

  clonar(l, &clone);

  for (int i = 0; i < l->qtd; i++) {
    clone.dados[l->qtd - i - 1].codigo = i + 1;
    l->dados[i] = clone.dados[l->qtd - i - 1];
  }
}

// adiciona novo elemento na lista em sua posição já ordenada
void add_lista_ordenado(Lista *l, Pessoa p) {
  if (l->qtd == l->MAX) {
    printf("\nLista cheia!\n");
    return;
  }
  int index = 0;
  Pessoa aux, tmp;

  for (int i = 0; i < l->qtd; i++) {
    if (p.idade > l->dados[i].idade) {
      index = i + 1;
    }
  }

  p.codigo = index + 1;
  l->qtd++;

  aux = l->dados[index];
  l->dados[index] = p;

  for (int i = index + 1; i < l->qtd; i++) {
    tmp = l->dados[i];
    l->dados[i] = aux;
    aux = l->dados[i + 1];
  }

  return;
}

// função para pegar maior pessoa da lista
Pessoa maior(Lista *l) {
  Pessoa maiorPessoa = l->dados[0];
  int maiorIdade = maiorPessoa.idade;

  for (int i = 1; i < l->qtd; i++) {
    if (l->dados[i].idade > maiorIdade) {
      maiorIdade = l->dados[i].idade;
      maiorPessoa = l->dados[i];
    }
  }

  return maiorPessoa;
}

// função para pesquisar e retornar codigo caso exista ou -1
int pesquisar(Lista *l, char *nome) {
  for (int i = 1; i < l->qtd; i++) {
    if (strcmp(l->dados[i].nome, nome) == 0) {
      return l->dados[i].codigo;
    }
  }

  return -1;
}

// metodo para ordenar por ordem alfabetica
void ordena_alfabetica(Lista *l) {
  char tipo[10] = "nome";
  quicksort(l->dados, l->qtd, tipo);
}

// metodo para ordenar através do codigo
void ordena_codigo(Lista *l) {
  char tipo[10] = "codigo";
  quicksort(l->dados, l->qtd, tipo);
}

#endif  // FILA_H_INCLUDED
