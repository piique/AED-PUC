#include <stdio.h>
#include <string.h>

// #include "lista_estatica.h"
#include "lista_dinamica.h"
#include "pessoa.h"

int menu() {
  int opcao = 0;
  printf("\n====> LISTA DE PESSOAS <=====\n");
  printf("1 - Listar Pessoas\n");
  printf("2 - Inserir nova Pessoa\n");
  printf("3 - Editar dados de uma Pessoa\n");
  printf("4 - Apagar uma Pessoa\n");
  printf("5 - Clonar lista\n");
  printf("6 - Concatenar lista\n");
  printf("7 - Inverter lista\n");
  printf("8 - Inserir ordenado (idade)\n");
  printf("9 - Pessoa com maior idade\n");
  printf("10 - Pesquisar pessoa\n");
  printf("11 - Ordenar em ordem alfabetica (nome)\n");
  printf("12 - Ordenar em ordem crescente (codigo)\n");
  printf("0 - Sair\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);

  return opcao;
}

int main(void) {
  // CRIA A LISTA DE PESSOAS
  Lista lista, lista_clonada, lista_concatenado;
  Pessoa paux;
  int op = 0, codigo;
  char nome[100];

  create_lista(&lista);

  do {
    op = menu();

    switch (op) {
      case 1:
        print_lista(&lista);
        break;

      case 2:
        paux = novo_pessoa();
        add_lista(&lista, paux);
        break;

      case 3:
        printf("\nDigite o codigo da pessoa: ");
        scanf("%d", &codigo);
        paux = novo_pessoa();
        paux.codigo = codigo;
        update_lista(&lista, paux);
        break;

      case 4:
        printf("\nDigite o codigo da pessoa: ");
        scanf("%d", &codigo);
        delete_lista(&lista, codigo);
        break;

      case 5:
        clonar(&lista, &lista_clonada);
        printf("\nLista clonada: \n");
        print_lista(&lista_clonada);
        break;

      case 6:
        concatenar(&lista, &lista_clonada, &lista_concatenado);
        printf("\nLista concatenada: \n");
        print_lista(&lista_concatenado);
        break;

      case 7:
        inverter(&lista);
        printf("\nLista invertida: \n");
        print_lista(&lista);
        break;

      case 8:
        paux = novo_pessoa();
        add_lista_ordenado(&lista, paux);
        break;

      case 9:
        printf("\nPessoa com maior idade: \n");
        print_pessoa(maior(&lista));
        break;

      case 10:
        printf("\nDigite um nome para ser pesquisado: ");
        scanf("%s", nome);
        if (pesquisar(&lista, nome) != -1) {
          printf("\nPessoa encontrada!\n");
        } else {
          printf("\nPessoa nao encontrada!\n");
        }
        break;

      case 11:
        ordena_alfabetica(&lista);
        printf("\nLista ordenada: \n");
        print_lista(&lista);
        break;

      case 12:
        ordena_codigo(&lista);
        printf("\nLista ordenada: \n");
        print_lista(&lista);
        break;
    }
  } while (op != 0);

  return 0;
}
