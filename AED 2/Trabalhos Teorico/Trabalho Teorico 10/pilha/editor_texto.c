#include <stdio.h>

#include "pilha_dinamica.h"
// #include "pilha_estatica.h"

// declaraçao de procedimentos
void inverter_pilha(Pilha* pilha);
void print_linha(Pilha* linha);
void iniciaLinha(char* letra);

int main() {
  char letra;

  // realiza laço de repetição até input apresentar quebra de linha
  do {
    iniciaLinha(&letra);
  } while (letra != '\n');

  return 0;
}

// realiza operações de uma linha
void iniciaLinha(char* letra) {
  // cria uma pilha para a linha
  Pilha linha;
  int count = 0;

  create_pilha(&linha);

  while (count <= 70) {
    // recebe linha
    scanf("%c", letra);
    count++;

    if (*letra == '\n') {
      print_linha(&linha);
      return;
    } else if (*letra == '/') {
      return;
    } else if (*letra == '@') {
      push(&linha, '\n');
      print_linha(&linha);
      return;
    } else if (*letra == '#') {
      pop(&linha);
    } else {
      push(&linha, *letra);
    }
  }
  // quando estourar o limite de 70 caracteres imprime linha e começa outra
  push(&linha, '\n');
  print_linha(&linha);
}

// procedimento para inverter valores de uma pilha
void inverter_pilha(Pilha* pilha) {
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

// printa pilha apos inverte-la
void print_linha(Pilha* linha) {
  inverter_pilha(linha);
  print_pilha_clean(linha);
}
