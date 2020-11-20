#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definiçao do tipo Produto
typedef struct {
  int codigo;
  char descricao[100];
  float valor;
} Produto;

void cadastrarProduto(Produto *lista, int qtdProdutos) {
  printf("\nDigite o codigto: \n");
  scanf("%i", &(lista + qtdProdutos)->codigo);
  fflush(stdin);

  printf("Digite a descricao: \n");
  scanf("%s", (lista + qtdProdutos)->descricao);
  fflush(stdin);

  printf("Valor: \n");
  scanf("%f", &(lista + qtdProdutos)->valor);
  fflush(stdin);
}

void exibirTodos(Produto *lista, int qtdProdutos) {
  printf("\nPRODUTOS CADASTRADOS: \n");
  for (int i = 0; i < qtdProdutos; i++) {
    if ((lista + i)->codigo != -1) {
      printf("\n----------------------------\n");
      printf("Codigo: %i\n", (lista + i)->codigo);
      printf("Descicao: %s\n", (lista + i)->descricao);
      printf("Codigo: %f\n", (lista + i)->valor);
      printf("\n----------------------------\n");
    }
  }
}

void editarProduto(Produto *lista, int qtdProdutos) {
  int codigo;

  printf("\nDigite o produto que deseja editar: ");
  scanf("%i", &codigo);

  for (int i = 0; i < qtdProdutos; i++) {
    if ((lista + i)->codigo == codigo) {
      printf("Digite a nova descrição do produto: ");
      scanf("%s", (lista + i)->descricao);

      printf("Digite o novo valor do produto: ");
      scanf("%f", &(lista + i)->valor);
      printf("\nProduto alterado!\n");
      return;
    }
  }
  printf("\nProduto nao encontrado!\n");
}

void excluirProduto(Produto *lista, int *qtdProdutos) {
  if (*qtdProdutos <= 1) {
    *qtdProdutos = 0;
    return;
  }

  int codigo;

  printf("Digite o codigo de produto que deseja excluir: ");
  scanf("%i", &codigo);
}

int main() {
  // int lista[10];
  // lista[0] = 2;
  int n, qtdProdutos = 0, opc;
  printf("Digita ai sua puta: ");
  scanf("%i", &n);

  // // Produto lista[n];
  Produto *lista = malloc(n * sizeof(Produto));

  //cadastro de produto
  // lista[0].codigo = 5;
  (lista + 0)->codigo = 5;

  // strcpy(lista[0].descricao, "Descriçao do primeiro produto");
  strcpy((lista + 0)->descricao, "Descriçao do primeiro produto");

  // lista[0]->valor = 12.5;
  (lista + 0)->valor = 12.5;

  // menu topzera
  do {
    printf("\n--------------Menu--------------\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Editar Produto\n");
    printf("3 - Excluir Produto\n");
    printf("4 - Exibir Todos Produtos\n");
    printf("5 - Exibir Quantidade de Produtos\n");
    printf("0 - Sair\n");
    printf("Opc: ");
    scanf("%i", &opc);
    fflush(stdin);

    switch (opc) {
      case 1:
        if (qtdProdutos < n) {
          cadastrarProduto(lista, qtdProdutos);
          qtdProdutos++;
        } else {
          printf("\nLimite de produtos atingido.\n");
        }
        break;
      case 2:
        editarProduto(lista, qtdProdutos);
        break;
      case 3:
        excluirProduto(lista, &qtdProdutos);
        break;
      case 4:
        exibirTodos(lista, qtdProdutos);
        break;
      case 5:
        printf("\nQuantidade de produtos cadastrados: %i\n", qtdProdutos);
        break;
      case 0:
        break;
      default:
        printf("\nOpcao invalida!\n");
        break;
    }

  } while (opc != 0);
  return 0;
}

// int main() {
//   // declaração de variaveis
//   int qtdTotalProdutos, qtdProdudos = 0, opc;

//   printf("Digite a quantidade maxima de produtos no sistema: ");
//   scanf("%i", &qtdTotalProdutos);

//   // alocaçao dinamica para quantidade de produtos no sistema
//   Produto *vetor = malloc(qtdTotalProdutos * sizeof(Produto));

//   // menu
//   do {
//     printf("\n--------------Menu--------------\n");
//     printf("1 - Cadastrar Produto\n");
//     printf("2 - Editar Produto\n");
//     printf("3 - Excluir Produto\n");
//     printf("4 - Exibir Todos Produtos\n");
//     printf("5 - Exibir Quantidade de Produtos\n");
//     printf("0 - Sair\n");
//     printf("Opc: ");
//     scanf("%i", &opc);

//     switch (opc) {
//       case 1:
//         if (qtdProdudos < qtdTotalProdutos) {
//           cadastrar(vetor, &qtdProdudos);
//         } else {
//           printf("Limite de produtos atingido.");
//         }
//         break;
//       case 2:
//         excluir(vetor, &qtdProdudos);
//         break;
//       case 3:
//         excluir(vetor, &qtdProdudos);
//         break;
//       case 4:
//         exibirTodos(vetor, qtdProdudos);
//         break;
//       case 5:
//         printf("\nQuantidade de produtos cadastrados: %i\n", qtdProdudos);
//         break;
//       case 0:
//         break;
//       default:
//         printf("\nOpcao invalida!\n");
//         break;
//     }

//   } while (opc != 0);

//   return 0;
// }
