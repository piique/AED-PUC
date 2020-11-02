#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
  int codigo;
  char nome[100];
  int idade;
} Pessoa;

void print_pessoa(Pessoa p) {
  printf("codigo: %d, nome: %s, idade: %d\n",
         p.codigo, p.nome, p.idade);
}

Pessoa novo_pessoa() {
  Pessoa p;
  sprintf(p.nome, "Pessoa %d", p.codigo);
  printf("Digite o nome da pessoa: ");
  scanf("%s", p.nome);
  fflush(stdin);
  printf("Digite a idade da pessoa: ");
  scanf("%i", &p.idade);
  return p;
}

#endif  // PESSOA_H_INCLUDED
