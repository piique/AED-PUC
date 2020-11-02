#ifndef LISTA1_H_INCLUDED
#define LISTA1_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "quicksort.h"
typedef struct Celula {
  Pessoa dado;
  struct Celula *prox;
} Celula;

typedef struct Lista {
  Celula *inicio;
  Celula *fim;
  int qtd;
} Lista;

void create_lista(Lista *l) {
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->prox = NULL;

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

  p.codigo = l->qtd + 1;

  nova->dado = p;
  nova->prox = NULL;

  l->fim->prox = nova;
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
    printf("\nProduto nao encontrado na lista!\n");
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

      free(tmp);
      l->qtd--;
      achou = true;
      break;
    }
  }

  if (achou)
    return true;
  else {
    printf("\nProduto nao encontrado na lista!\n");
    return false;
  }
}

void clonar(Lista *l, Lista *clonada) {
  create_lista(clonada);
  Celula *tmp = l->inicio->prox;
  Pessoa pessoa;

  while (tmp != NULL) {
    pessoa = tmp->dado;
    add_lista(clonada, pessoa);
    tmp = tmp->prox;
  }
}

void concatenar(Lista *l, Lista *l2, Lista *concatenada) {
  create_lista(concatenada);
  Celula *tmp = l2->inicio->prox;
  Pessoa pessoa;

  // clona lista 1 para concatenada
  clonar(l, concatenada);

  // junta lista 2 ao final da lista concatenada
  while (tmp != NULL) {
    pessoa = tmp->dado;
    add_lista(concatenada, pessoa);
    tmp = tmp->prox;
  }
}

void inverter(Lista *l) {
  Pessoa *dados = (Pessoa *)malloc(l->qtd * sizeof(Pessoa));
  Celula *tmp = l->inicio->prox;

  // copia dados da lista para vetor de Pessoas
  for (int i = 0; tmp != NULL; i++) {
    dados[i] = tmp->dado;
    tmp = tmp->prox;
  }

  tmp = l->inicio->prox;
  // copia dados de vetor de Pessoas para lista
  for (int i = l->qtd - 1; i >= 0; i--) {
    dados[i].codigo = l->qtd - i;
    tmp->dado = dados[i];
    tmp = tmp->prox;
  }

  free(dados);
}

void add_lista_ordenado(Lista *l, Pessoa p) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  if (nova == NULL) {
    printf("\nLista Cheia!\n");
    return;
  }

  Celula *tmp = l->inicio->prox;
  Celula aux;

  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    if (p.idade < tmp->dado.idade) {
      aux = *tmp;
      p.codigo = l->qtd + 1;

      tmp->dado = p;
      tmp->prox = nova;

      *nova = aux;
      l->qtd++;
      return;
    }
    tmp = tmp->prox;
  }

  p.codigo = l->qtd + 1;

  nova->dado = p;
  nova->prox = NULL;

  l->fim->prox = nova;
  l->fim = nova;
  l->qtd++;

  return;
}

Pessoa maior(Lista *l) {
  Celula *tmp = l->inicio->prox;
  Celula *maior = tmp;
  int maiorIdade = maior->dado.idade;
  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    if (tmp->dado.idade > maiorIdade) {
      maiorIdade = tmp->dado.idade;
      maior = tmp;
    }
  }

  return maior->dado;
}

int pesquisar(Lista *l, char *nome) {
  Celula *tmp;
  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    if (strcmp(tmp->dado.nome, nome) == 0) {
      return tmp->dado.codigo;
    }
  }

  return -1;
}

void ordena_alfabetica(Lista *l) {
  Pessoa *lista = (Pessoa *)malloc(l->qtd * sizeof(Pessoa));

  char tipo[10] = "nome";
  Celula *tmp;

  // copia dados da lista para uma lista de Pessoa
  int i = 0;
  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    lista[i] = tmp->dado;
    i++;
  }

  // ordena lista de Pessoa
  quicksort(lista, l->qtd, tipo);

  // copia lista de Pessoa ordenada para lista dinamica original
  i = 0;
  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    tmp->dado = lista[i];
    i++;
  }
}

void ordena_codigo(Lista *l) {
  Pessoa *lista = (Pessoa *)malloc(l->qtd * sizeof(Pessoa));
  char tipo[10] = "codigo";
  Celula *tmp;

  // copia dados da lista para uma lista de Pessoa
  int i = 0;
  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    lista[i] = tmp->dado;
    i++;
  }

  // ordena lista de Pessoa
  quicksort(lista, l->qtd, tipo);

  // copia lista de Pessoa ordenada para lista dinamica original
  i = 0;
  for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
    tmp->dado = lista[i];
    i++;
  }
}

#endif  // FILA_H_INCLUDED
