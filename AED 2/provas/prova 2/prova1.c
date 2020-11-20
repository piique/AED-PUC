#include <fila_dinamica.h>
#include <stdio.h>

int size_fila(Fila *f) {
  return 5;
}

int extrairdafila(Fila *f, int x) {
  Celula *ant = (Celula *)malloc(sizeof(Celula));
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  ant = f->inicio;  // anterior
  tmp = ant->prox;  // primeiro

  while (tmp != NULL) {
    if (tmp->dado == x) {
      if (tmp->prox == NULL) {
        f->fim = ant;
      }
      ant->prox = tmp->prox;
      free(tmp);
      free(ant);
      f->tam--;
      return x;
    }
    ant = tmp;
    tmp = tmp->prox;
  }
  free(tmp);
  free(ant);
  return x;
}

// int extrairdafila(Fila *f, int x) {
//   Celula *tmp = (Celula *)malloc(sizeof(Celula));
//   tmp = f->inicio;

//   for (int i = 0; i < size_fila(f); i++) {
//     // troca proximo elemento com atual e aponta proximo como 2 a frente
//     if (tmp->dado == x) {
//       tmp->dado = tmp->prox->dado;
//       tmp->prox = tmp->prox->prox;
//       return x;
//       free(tmp);
//     }
//   }
//   return -1;
//   free(tmp);
// }

// adiciona novo elemento na lista em sua posição já ordenada
// void add_lista_ordenado(Lista *l, Pagina p) {
//   Celula *nova = (Celula *)malloc(sizeof(Celula));
//   if (nova == NULL) {
//     printf("\nLista Cheia!\n");
//     return;
//   }

//   Celula *tmp = l->inicio->prox;
//   Celula aux;

//   for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox) {
//     if (p.url < tmp->dado.url) {
//       aux = *tmp;
//       p.codigo = l->qtd + 1;

//       tmp->dado = p;
//       tmp->prox = nova;

//       *nova = aux;
//       l->qtd++;
//       return;
//     }
//     tmp = tmp->prox;
//   }

//   p.codigo = l->qtd + 1;

//   nova->dado = p;
//   nova->prox = NULL;

//   l->fim->prox = nova;
//   l->fim = nova;
//   l->qtd++;

//   return;
// }
