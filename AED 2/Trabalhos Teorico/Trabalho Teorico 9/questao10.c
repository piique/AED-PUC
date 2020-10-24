#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definiçao do tipo Produto
typedef struct {
  int codigo;
  char descricao[100];
  float valor;
} Produto;

// cadastrar produto novo
void cadastrar(Produto *vetor, int *qtdProdutos) {
  vetor += *qtdProdutos;
  printf("Codigo do produto: ");
  scanf("%i", &vetor->codigo);
  fflush(stdin);
  printf("Descricao do produto: ");
  scanf("%s", vetor->descricao);
  fflush(stdin);
  printf("Valor do produto: ");
  scanf("%f", &vetor->valor);
  fflush(stdin);
  *qtdProdutos = *qtdProdutos + 1;
  printf("Produto cadastrado!");
}

// excluir produto
void excluir(Produto *vetor, int *qtdProdutos) {
  if (*qtdProdutos == 0) {
    printf("\nNão existe produto para ser excluido!\n");
    return;
  }

  int codigo_excluido, codigo;
  char descricao[100];
  float valor;

  printf("Qual codigo do produtudo deseja excluir: ");
  scanf("%i", &codigo);

  for (int i = 0; i < *qtdProdutos; i++) {
    if ((vetor + i)->codigo == codigo) {
      *qtdProdutos = *qtdProdutos - 1;

      // salva valores do ultimo elemento da lista
      codigo = (vetor + *qtdProdutos)->codigo;
      strcpy(descricao, (vetor + *qtdProdutos)->descricao);
      valor = (vetor + *qtdProdutos)->valor;

      // coloca o elemento excluido na ultima posicao
      (vetor + *qtdProdutos)->codigo = codigo_excluido;
      strcpy((vetor + *qtdProdutos)->descricao, (vetor + i)->descricao);
      (vetor + *qtdProdutos)->valor = (vetor + i)->valor;

      // coloca o ultimo elemento na posicao do excluido
      (vetor + i)->codigo = codigo;
      strcpy((vetor + i)->descricao, descricao);
      (vetor + i)->valor = valor;
    }
  }
}

// exibe todos os produtos
void exibirTodos(Produto *vetor, int qtdCadastrados) {
  if (qtdCadastrados == 0) {
    printf("\nNao existe produto cadastrado!\n");
  }

  printf("\nTODOS OS PRODUTOS CADASTRADOS: \n");
  for (int i = 0; i < qtdCadastrados; i++) {
    printf("\n------------------------------\n");
    printf("Codigo do produto: %i\n", vetor->codigo);
    printf("Descricao: %s\n", vetor->descricao);
    printf("Valor: %f\n", vetor->valor);
    printf("------------------------------\n");
    vetor++;
  }
}

int main() {
  int qtdTotalProdutos, qtdProdudos = 0, opc;
  // int *x = (int *)malloc(coluna * sizeof(int));

  printf("Digite a quantidade maxima de produtos no sistema: ");
  scanf("%i", &qtdTotalProdutos);

  // alocaçao dinamica para quantidade de produtos no sistema
  Produto *vetor = malloc(qtdTotalProdutos * sizeof(Produto));

  // menu
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

    switch (opc) {
      case 1:
        if (qtdProdudos < qtdTotalProdutos) {
          cadastrar(vetor, &qtdProdudos);
        } else {
          printf("Limite de produtos atingido.");
        }
        break;
      case 2:
        excluir(vetor, &qtdProdudos);
        break;
      case 3:
        excluir(vetor, &qtdProdudos);
        break;
      case 4:
        exibirTodos(vetor, qtdProdudos);
        break;
      case 5:
        printf("\nQuantidade de produtos cadastrados: %i\n", qtdProdudos);
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
