/*
Nome: Pedro Henrique Vilaça Valverde
Matricula: 704421

Analise de complexidade é feita ao observar as operações de push e pop que são feitas de a cordo com
a quantidade de elementos presentes na fila, logo, O(n).

O pior caso é quando o elemento procurado está no começo. Desempilhar e empilhar todos os elementos 2 vezes. Movimentações: (n*2)
O melhor caso é quando o elemento procurado está no topo. Desempilhar o elemento 1 vez. Movimentações: (1)

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// celular para armazenar vetor de char
typedef struct Celula {
  // char string[100];
  char dado;
  struct Celula *prox;
} Celula;

// definição da Pilha
typedef struct Pilha {
  Celula *topo;
  int tam;
} Pilha;

// procedimento para criar pilha
void create_pilha(Pilha *p) {
  p->topo = NULL;
  p->tam = 0;
}

// funçao para empilhar
bool push(Pilha *p, char dado) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));

  // verifica se pilha está cheia
  if (nova == NULL) {
    // printf("\nPilha Cheia!\n");
    return false;
  }

  nova->dado = dado;

  nova->prox = p->topo;
  p->topo = nova;
  p->tam++;
  return true;
}

// função para desempilhar elemento do topo
char pop(Pilha *p) {
  if (p->tam == 0) {
    return -1;
  }

  int dado = p->topo->dado;

  Celula *tmp = p->topo;
  p->topo = p->topo->prox;
  free(tmp);

  p->tam--;
  return dado;
}

bool is_empty(Pilha *p) {
  return p->tam == 0;
}

int extrairdapilha(Pilha *p, int x) {
  Pilha aux;
  create_pilha(&aux);
  int retorno = -1;

  // desempilha primeira pilha e empilha em aux ate achar elemento
  char value;
  while (!is_empty_pilha(p)) {
    value = pop(p);
    if (value == x) {
      retorno = x;
      break;
    }
    push(&aux, value);
  }

  // desempilhar aux e empilha em primeira pilha
  while (!is_empty_pilha(&aux)) {
    value = pop(&aux);
    push(p, value);
  }

  // retorna valor caso tenha sido encontrado
  return retorno;
}

void concatenar(Pilha *primeira_pilha, Pilha *segunda_pilha, Pilha *pilha_concatenada) {
  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  // desempilha primeira pilha toda e empilha em aux
  char value = pop(primeira_pilha);
  while (value != -1) {
    push(&pilha_aux, value);
    value = pop(primeira_pilha);
  }

  // desempilhar aux e empilha em primeira pilha e em pilha final
  value = pop(&pilha_aux);
  while (value != -1) {
    push(pilha_concatenada, value);
    push(primeira_pilha, value);
    value = pop(&pilha_aux);
  }

  // desempilha segunda pilha toda e empilha em aux
  value = pop(segunda_pilha);
  while (value != -1) {
    push(&pilha_aux, value);
    value = pop(segunda_pilha);
  }

  // desempilha aux e empilha em primeira pilha e em pilha final
  value = pop(&pilha_aux);
  while (value != -1) {
    push(pilha_concatenada, value);
    push(segunda_pilha, value);
    value = pop(&pilha_aux);
  }
}

int main(void) {
  int qtd;
  char string[1000], letra, aux;
  scanf("%i", &qtd);

  for (int i = 0; i < qtd; i++) {
    fflush(stdin);
    scanf("%s", string);
    verificaString(string);
  }
}

// // verifica parenteses
// void verificaParenteses(char *string) {
//   Pilha pilha;
//   create_pilha(&pilha);

//   printf("\nVALIDADOR PARENTESES\n");
//   printf("Digite uma expressao: ");
//   scanf("%s", string);

//   int len = strlen(string);

//   for (int i = 0; i < len; i++) {
//     if (string[i] == '(') {
//       push(&pilha, string[i]);
//     } else if (string[i] == ')') {
//       if (pop(&pilha) == -1) {
//         printf("\nExpressão Matemática Incorreta\n");
//         return;
//       }
//     }
//   }
//   if (is_empty(&pilha)) {
//     printf("\nExpressão Matemática Correta\n");
//   } else {
//     printf("\nExpressão Matemática Incorreta\n");
//   }
// }
