#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//======================================
typedef struct Celula {
  int dado;
  struct Celula *prox;
} Celula;
//======================================
typedef struct Fila {
  Celula *inicio;
  Celula *fim;
  int tam;
} Fila;
//======================================
void create_fila(Fila *f) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->prox = NULL;

  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}

// Queue
bool enqueue(Fila *f, int dado) {
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
//======================================
void print_fila(Fila *f) {
  Celula *tmp = f->inicio->prox;

  printf("\nTamanho: %d\n", f->tam);
  while (tmp != NULL) {
    printf("%i\n", tmp->dado);
    tmp = tmp->prox;
  }
}
//======================================
int dequeue(Fila *f) {
  if (f->tam == 0) {
    return -1;
  }

  Celula *tmp = f->inicio;
  f->inicio = f->inicio->prox;
  free(tmp);

  f->tam--;
  return f->inicio->dado;
}

/*
Nome: Pedro Henrique Vila??a Valverde
Matricula: 704421

A complexidade desse algoritimo é sempre constante para todos os casos pois independente do tamanho das filas
eh utilizado a mesma quantidade de movimentações dos ponteiros. Complexidade O(1).

*/

// função criada para concatenanr f1 e f2 em uma terceira fila e retornar ponteiro dela
Fila *concatena_fila(Fila *f1, Fila *f2) {
  Fila *fila = (Fila *)malloc(sizeof(Fila));

  // copia referencia do inicio para nova fila
  fila->inicio = f1->inicio;

  // linka fim da fila com fim da f1
  fila->fim = f1->fim;

  // linka fim da fila com inicio da f2
  fila->fim->prox = f2->inicio->prox;

  // linka fim da fila com fim da f2
  fila->fim = f2->fim;

  // atualiza tamanho da fila com soma dos tamanhos da f1 e f2
  fila->tam = f1->tam + f2->tam;

  return fila;
}

int main() {
  Fila p1, p2;
  create_fila(&p1);
  create_fila(&p2);

  enqueue(&p1, 5);
  enqueue(&p1, 1);
  enqueue(&p1, 2);
  enqueue(&p1, 3);
  enqueue(&p1, 4);
  enqueue(&p1, 5);

  // print_fila(&p1);
  enqueue(&p2, 1);
  enqueue(&p2, 2);
  enqueue(&p2, 3);

  print_fila(concatena_fila(&p1, &p2));

  return 0;
}
