#include <stdio.h>
#include <stdlib.h>

#include "fila_dinamica.h"
// #include "fila_estatica.h"

int menu() {
  int opcao;
  printf("\n =====> FILA DE PROCESSOS <===== \n");
  printf("1 - Incluir novos processos na fila de processos\n");
  printf("2 - Retirar da fila de processos o processo com o maior tempo de espera\n");
  printf("3 - Imprimir o conteúdo da lista de processos.\n");
  printf("0 - Sair\n");
  printf("Digite a opcao desejada: ");

  scanf("%d", &opcao);

  return opcao;
}

// funçao para receber novo processo do usuario e retornar processo
Pessoa novo_processo() {
  Pessoa p;

  p.id = rand() % 1000;
  printf("Digite o nome do processo: ");
  scanf("%s", p.nome);
  printf("Digite o tempo de espera do processo: ");
  scanf("%i", &p.idade);
  fflush(stdin);

  return p;
}

// retira processo da filha
void retira_processo(Fila *fila) {
  Pessoa processo;
  int pior;
  processo = desenfila(fila);
  pior = processo.idade;  // tempo do processo
  enfila(fila, processo);

  for (int i = 0; i < fila->tam; i++) {
    if (processo.idade > pior) {
      pior = processo.idade;
    }
    processo = desenfila(fila);
    enfila(fila, processo);
  }

  printf("\nPior tempo: %i\n", pior);
  for (int i = 0; i < fila->tam; i++) {
    processo = desenfila(fila);
    if (processo.idade != pior) {
      enfila(fila, processo);
    } else {
      return;
    }
  }
}

int main(void) {
  int op, x;
  Fila fila;
  char buffer;
  Pessoa paux;
  create_fila(&fila);

  do {
    // system("clear");  //system("cls");
    op = menu();

    switch (op) {
      case 1:
        paux = novo_processo();
        if (enfila(&fila, paux)) {
          printf("\nNovo processo entrou na fila!\n");
        } else {
          printf("\nErro. Nenhum processo entrou na fila.\n");
        }
        break;
      case 2:
        retira_processo(&fila);
        break;
      case 3:
        printf("\n");
        print_processos(&fila);
        break;
    }

  } while (op != 0);

  return 0;
}
