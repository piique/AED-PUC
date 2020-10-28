#include <stdio.h>
#include <time.h>

// #include "pilha_dinamica.h"
#include "pilha_estatica.h"

// declaração de metodos
void clonar(Pilha* original, Pilha* pilha_clonada);
void concatenar(Pilha*, Pilha*, Pilha* pilha_concatenada);
void inverter(Pilha*);
void ordenar(Pilha*);
void RetiraImpares(Pilha*);

int main(void) {
  Pilha pilha;

  Pilha pilha_clonada;

  Pilha pilha_concatenada;

  create_pilha(&pilha);

  // preenche pilha com letras aleatorias
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    push(&pilha, 65 + (rand() % (91 - 65)));  // letras maiusculas aleatorias 65 a 90
  }

  printf("\n\nPilha original aleatoria: ");
  print_pilha(&pilha);

  clonar(&pilha, &pilha_clonada);
  printf("\n\nPilha clonada da original: ");
  print_pilha(&pilha_clonada);

  concatenar(&pilha, &pilha_clonada, &pilha_concatenada);
  printf("\n\nPilha concatenada (original + clonada): ");
  print_pilha(&pilha_concatenada);

  inverter(&pilha);
  printf("\n\nPilha original invertida: ");
  print_pilha(&pilha);

  ordenar(&pilha);
  printf("\n\nPilha original ordenada: ");
  print_pilha(&pilha);

  RetiraImpares(&pilha);
  printf("\n\nPilha original sem numeros impares: ");
  print_pilha(&pilha);

  return 0;
}

// procedimento para clonar pilha e retornar uma nova (funciona para ambas as versoes de pilha (dinamica e estatica))
void clonar(Pilha* original, Pilha* pilha_clonada) {
  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  if (!is_empty(pilha_clonada)) {
    create_pilha(pilha_clonada);
  }

  // desempilha pilha original e empilha em aux
  char value = pop(original);
  while (value != -1) {
    push(&pilha_aux, value);
    value = pop(original);
  }

  // desempilha pilha aux e empilha em original e clonada
  value = pop(&pilha_aux);
  while (value != -1) {
    push(pilha_clonada, value);
    push(original, value);
    value = pop(&pilha_aux);
  }
}

// procedimento para concatenar duas pilhas em uma terceira
void concatenar(Pilha* primeira_pilha, Pilha* segunda_pilha, Pilha* pilha_concatenada) {
  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  if (!is_empty(pilha_concatenada)) {
    create_pilha(pilha_concatenada);
  }

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

// procedimento para inverter valores de uma pilha
void inverter(Pilha* pilha) {
  Pilha pilha_invertida;
  create_pilha(&pilha_invertida);
  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  // desempilha pilha e empilha em pilha invertida
  char value = pop(pilha);
  while (value != -1) {
    push(&pilha_invertida, value);
    value = pop(pilha);
  }

  // desempilha pilha invertida e empilha em pilha aux
  value = pop(&pilha_invertida);
  while (value != -1) {
    push(&pilha_aux, value);
    value = pop(&pilha_invertida);
  }

  // desempilha pilha aux e empilha em pilha original
  value = pop(&pilha_aux);
  while (value != -1) {
    push(pilha, value);
    value = pop(&pilha_aux);
  }
}

// procedimento para ordenar pilha
void ordenar(Pilha* pilha) {
  // realiza chamada do procedimento nos arquivos das pilhas
  sort_stack(pilha);
}

void RetiraImpares(Pilha* pilha) {
  Pilha pilha_aux;
  create_pilha(&pilha_aux);

  // desempilha pilha e empilha em pilha aux apenas valores pares
  char value = pop(pilha);
  while (value != -1) {
    if (value % 2 == 0) {
      push(&pilha_aux, value);
    }
    value = pop(pilha);
  }

  // desempilha pilha aux e empilha em pilha original
  value = pop(&pilha_aux);
  while (value != -1) {
    push(pilha, value);
    value = pop(&pilha_aux);
  }
}
