#ifndef LISTA1_H_INCLUDED
#define LISTA1_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula {
  int dado;
  struct Celula *prox;
} Celula;

typedef struct Lista {
  Celula *inicio;
  Celula *fim;
  int qtd;
} Lista;

// procedimento para inicializar lista
void create_lista(Lista *l) {
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->prox = NULL;

  l->inicio = tmp;
  l->fim = tmp;
  l->qtd = 0;
}

// função para adicionar novo elemento na lista
bool add_lista(Lista *l, int p) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));

  if (nova == NULL) {
    printf("\nLista Cheia!\n");
    return false;
  }

  nova->dado = p;
  nova->prox = NULL;

  l->fim->prox = nova;
  l->fim = nova;
  l->qtd++;

  return true;
}

// procedimento para printar conteudo da lista
void print_lista(Lista *l) {
  Celula *tmp = l->inicio->prox;

  while (tmp != NULL) {
    printf("%i\n", tmp->dado);
    tmp = tmp->prox;
  }
}

Lista *merge(Lista *l1, Lista *l2) {
  Lista *final = (Lista *)malloc(sizeof(Lista));
  Celula *ptr_l1 = (Celula *)malloc(sizeof(Celula));
  Celula *ptr_l2 = (Celula *)malloc(sizeof(Celula));
  ptr_l1 = l1->inicio->prox;
  ptr_l2 = l2->inicio->prox;

  create_lista(final);
  for (int i = 0; i < (l1->qtd + l2->qtd); i++) {
    if (i % 2 == 0 && ptr_l1 != NULL) {
      // insere elemento da primeira na final
      add_lista(final, ptr_l1->dado);
      ptr_l1 = ptr_l1->prox;
    } else if (ptr_l2 != NULL) {
      // insere elemento da segunda na final
      add_lista(final, ptr_l2->dado);
      ptr_l2 = ptr_l2->prox;
    } else {
      add_lista(final, ptr_l1->dado);
      ptr_l1 = ptr_l1->prox;
    }
  }

  return final;
}

int main() {
  Lista l1, l2;

  create_lista(&l1);
  create_lista(&l2);

  int tam1, tam2;
  Celula aux;

  scanf("%i %i", &tam1, &tam2);
  for (int i = 0; i < tam1; i++) {
    scanf("%i\n", &aux.dado);
    add_lista(&l1, aux.dado);
  }

  for (int i = 0; i < tam1; i++) {
    scanf("%i\n", &aux.dado);
    add_lista(&l2, aux.dado);
  }

  printf("Lista 1:\n");
  print_lista(&l1);
  printf("Lista 2:\n");
  print_lista(&l2);

  printf("Lista intercalada:\n");
  print_lista(merge(&l1, &l2));
  return 0;
}

#endif  // FILA_H_INCLUDED
