#include <stdio.h>

// #include "pilha_estatica.h"
#include "pilha_dinamica.h"

/*
Alguns editores de texto permitem que algum caractere funcione como um "cancela-caractere", cujo efeito é o de cancelar o caractere anterior na linha que está sendo editada. Por exemplo, se '#' é o cancela-caractere, então a sequência de caracteres PEM##UB#C corresponde à sequência PUC. Outro comando encontrado em editores de texto é o "cancela-linha", cujo efeito é o de cancelar todos os caracteres anteriores na linha que está sendo editada. Neste exemplo vamos considerar '/' como o caractere cancela-linha. Finalmente, outro comando encontrado em editores de texto é o "salta-linha", cujo efeito é o de causar a impressão dos caracteres que pertencem à linha que está sendo editada, iniciando uma nova linha de impressão a partir do caractere imediatamente seguinte ao caractere salta-linha. Por exemplo, se `@' é o salta-linha, então a sequência de caracteres ICEI@PUCMINAS.@ corresponde às duas linhas abaixo:

ICEI

PUCMINAS.

Implemente um Editor de Texto (ET) que aceite os três comandos descritos acima. O ET deverá ler um caractere de cada vez do texto de entrada e produzir a impressão linha a linha, cada linha contendo no máximo 70 caracteres de impressão.

A seguir é sugerido um texto para testar o programa ET, cujas características permitem exercitar todas as partes importantes do programa.

Este et# um teste para o ET, o extraterrestre em C.@Acabamos de testar a capacidade de o ET saltar de linha, utilizando seus poderes extras (cuidado, pois agora vamos estourar a capacidade máxima da linha de impressão, que é de 70 caracteres.)@O k#cut#rso dh#e Estruturas de Dados II et# h#um cuu#rsh#o #x# x?@!#?!#+.@ Como et# bom n#nt#ao### r#ess#tt#ar mb#aa#triz#cull#ado nn#x#ele!/ Sera que este funciona/// O sinal? não### deve ficar! ~
*/

// declaraçao de proceimentos
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
