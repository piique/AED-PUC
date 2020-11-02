#include <stdio.h>
#include <string.h>

#include "lista_dupla.h"
#include "pessoa.h"

int menu() {
  int opcao = 0;
  printf("\n====> LISTA DE PESSOAS <=====\n");
  printf("1 - Listar Pessoas\n");
  printf("2 - Inserir nova Pessoa\n");
  printf("3 - Editar dados de uma Pessoa\n");
  printf("4 - Apagar uma Pessoa\n");
  printf("5 - Verificar tamanho lista\n");
  printf("6 - Pesquisar na lista\n");
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
        printf("\nPrintando lista: \n");
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
        printf("\nQuantidade de elementos na lista: %i\n", tamanho_lista(&lista));
        break;

      case 6:
        printf("\nDigite um nome para ser pesquisado: ");
        scanf("%s", nome);
        if (pesquisar(&lista, nome) != -1) {
          printf("\nPessoa encontrada!\n");
        } else {
          printf("\nPessoa nao encontrada!\n");
        }
        break;
    }
  } while (op != 0);

  return 0;
}
