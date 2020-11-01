#include <stdio.h>
#include <stdlib.h>

#include "fila_dinamica.h"
// #include "fila_estatica.h"
#include "pessoa.h"
#include "quicksort.h"

/*
FILA DE PESSOAS
PESSOA (ID, NOME, IDADE)
CRUD - criar, enfileirar, desenfileirar, tamanho, listar, destroy
*/

int menu() {
  int opcao;
  printf("\n =====> FILA DE ATENDIMENTO <===== \n");
  printf("1 - Entrar na fila\n");
  printf("2 - Verificar a fila\n");
  printf("3 - Chamar o próximo da fila\n");
  printf("4 - Clonar fila\n");
  printf("5 - Mostrar fila clonada\n");
  printf("6 - Concatenar e mostrar\n");
  printf("7 - Inverter e mostrar\n");
  printf("8 - Ordenar e mostrar\n");
  printf("0 - Sair\n");
  printf("Digite a opcao desejada: ");

  scanf("%d", &opcao);

  return opcao;
}

// procedimento para realizar a clonagem da pilha tanto para estatica quanto para dinamica
void clonar(Fila *fila, Fila *fila_clonada) {
  Pessoa dado;

  for (int i = 0; i < fila->tam; i++) {
    dado = desenfila(fila);
    enfila(fila_clonada, dado);
    enfila(fila, dado);
  }
}

// procedimento para realizar a concatenação da pilha tanto para estatica quanto para dinamica
void concatenar(Fila *fila, Fila *fila_2, Fila *fila_concatenada) {
  Pessoa dado;

  // copia primeira fila para fila concatenada
  clonar(fila, fila_concatenada);

  // copia segunda fila para fila concatenada
  for (int i = 0; i < fila_2->tam; i++) {
    dado = desenfila(fila_2);
    enfila(fila_concatenada, dado);
    enfila(fila_2, dado);
  }
}

// procedimento para inverter a orde dos elementos através do auxilio de um vetor de Pessoas tanto para fila dinamica quanto estatica
void inverter(Fila *f, Fila *invertida) {
  Pessoa *dados = (Pessoa *)malloc(f->tam * sizeof(Pessoa));

  // for para salvar dados em vetor de Pessoa
  for (int i = 0; i < f->tam; i++) {
    dados[i] = desenfila(f);
    enfila(f, dados[i]);
  }

  // for para enfileirar dados na fila a partir do ultimo elemento de dados
  for (int i = f->tam - 1; i >= 0; i--) {
    enfila(invertida, dados[i]);
  }
  // libera memoria alocada para dados
  free(dados);
}

// ordena fila por ordem de idade (mais velhos primeiro)
void ordena(Fila *f) {
  Pessoa *dados = (Pessoa *)malloc(f->tam * sizeof(Pessoa));
  int len = f->tam;
  // for para salvar dados em vetor de Pessoa
  for (int i = 0; i < len; i++) {
    dados[i] = desenfila(f);
  }

  // ordena vetor de dados
  quicksort(dados, len);

  // insere elementos do vetor de dados na fila novamente na ordem contraria da ordenação
  for (int i = len - 1; i >= 0; i--) {
    enfila(f, dados[i]);
  }

  // libera memoria alocada
  free(dados);
}

int main(void) {
  int op, x;
  Fila fila, fila_clonada, fila_concatenada, fila_invertida;
  char buffer;
  Pessoa paux;
  create_fila(&fila);
  create_fila(&fila_clonada);
  create_fila(&fila_concatenada);
  create_fila(&fila_invertida);

  do {
    // system("clear");  //system("cls");
    op = menu();

    switch (op) {
      case 1:
        paux = nova_pessoa();
        if (enfila(&fila, paux)) {
          printf("\nNova pessoa entrou na fila!\n");
        } else {
          printf("\nErro. Nenhuma pessoa entrou na fila.\n");
        }
        break;
      case 2:
        printf("\n");
        print_fila(&fila);
        break;
      case 3:
        paux = desenfila(&fila);
        print_pessoa(paux);
      case 4:
        clonar(&fila, &fila_clonada);
        printf("\nFila clonada: \n");
        print_fila(&fila_clonada);
        break;
      case 5:
        printf("\nFila clonada: \n");
        print_fila(&fila_clonada);
      case 6:
        concatenar(&fila, &fila_clonada, &fila_concatenada);
        printf("\nFila concatenada: \n");
        print_fila(&fila_concatenada);
        break;
      case 7:
        inverter(&fila, &fila_invertida);
        printf("\nFila Invertida: \n");
        print_fila(&fila_invertida);
        break;
      case 8:
        ordena(&fila);
        printf("\nFila Ordenada: \n");
        print_fila(&fila);
        break;
    }

  } while (op != 0);

  return 0;
}
