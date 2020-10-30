#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// definição do tipo Carro
typedef struct Carro {
  int manobras;
  char placa[10];
} Carro;

// definição da Pilha para estacionamento
typedef struct Pilha {
  Carro dados[MAX];
  int topo;
} Pilha;

// declaração de funções e procedimentos
void create_pilha(Pilha *p);
bool push(Pilha *p, char *placa, int manobras);
Carro *pop(Pilha *p);
void print_estacionamento(Pilha *p);
bool buscar_carro(Pilha *p, char *placa);
void retirar_carro(Pilha *p, char *placa);

int main() {
  Pilha estacionamento;
  char ordem, placa[10];

  create_pilha(&estacionamento);

  printf("Para utilização do programa siga as instruções abaixo (comandos separados por espaco): \n");
  printf("Entrada de carro: E + placa do carro\n");
  printf("Saida de carro: S + placa do carro\n");
  printf("Mostrar estacionamento: M + 'MOSTRAR'\n");
  printf("Sair do programa: Q + 'SAIR'\n");
  printf("Digite a opcao: ");
  scanf("%c %s", &ordem, placa);
  fflush(stdin);

  while (ordem != 'Q') {
    switch (ordem) {
      case 'E':
        if (push(&estacionamento, placa, 0)) {
          printf("\nCarro de placa %s estacionado!\n", placa);
        } else {
          printf("\nNao foi possivel estacionar carro! Estacionamento lotado.\n");
        }
        break;
      case 'S':
        retirar_carro(&estacionamento, placa);
        break;
      case 'M':
        print_estacionamento(&estacionamento);
        break;

      default:
        printf("\nSaindo do programa!\n");
        return 0;
        break;
    }
    printf("\nDigite a opcao: ");
    scanf("\n%c %s", &ordem, placa);
    fflush(stdin);
  }
}

// funçao para criar pilha
void create_pilha(Pilha *p) {
  p->topo = 0;
}

// funçao para empilhar
bool push(Pilha *p, char *placa, int manobras) {
  if (p->topo == MAX) {
    // printf("\nPilha Cheia!\n");
    return false;
  }

  strcpy(p->dados[p->topo].placa, placa);
  p->dados[p->topo].manobras = manobras;
  p->topo++;
  return true;
}

// função para desempilhar elemento do topo e retornar ponteiro de carro
Carro *pop(Pilha *p) {
  if (p->topo == 0) {
    // printf("\nPilha Vazia!\n");
    return NULL;
  }

  // p->dados[p->topo].manobras--;
  p->topo--;
  return &p->dados[p->topo];
}

// procedimento para printar carros no estacionamento
void print_estacionamento(Pilha *p) {
  if (p->topo == 0) {
    printf("\nNenhum carro no estacionamento!\n");
    return;
  }
  printf("\nQuantidade de carros: %d\n", p->topo);
  printf("====Entrada/Saida do Estacionamento====\n");

  for (int i = p->topo - 1; i >= 0; i--)
    printf("%s\n", p->dados[i].placa);

  printf("====Inicio do Estacionamento====\n");
}

// busca por carro atraves da placa e retrna sua posicao na pilha
bool buscar_carro(Pilha *p, char *placa) {
  for (int i = p->topo - 1; i >= 0; i--) {
    if (strcmp(p->dados[i].placa, placa) == 0) {
      return true;
    }
  }

  return false;
}

void retirar_carro(Pilha *p, char *placa) {
  if (!buscar_carro(p, placa)) {
    printf("\nCarro não encontrado no estacionamento!\n");
    return;
  }

  Pilha aux;
  create_pilha(&aux);
  Carro carro;

  // for para tirar carro a carro ate encontrar o que precisa ser retirado
  // quando nao encontrado carro no top, retirar e colocar em pilha auxiliar, para retornar novamente posteriormente
  for (int i = p->topo - 1; i >= 0; i--) {
    if (strcmp(p->dados[i].placa, placa) == 0) {
      printf("Carro de placa '%s' manobrado %i vezes antes de ser retirado\n", placa, p->dados[i].manobras);
      pop(p);
    } else {
      carro = *(pop(p));
      push(&aux, carro.placa, ++carro.manobras);
    }
  }

  // coloca carros que nao sairam no estacionamento novamente
  for (int i = aux.topo - 1; i >= 0; i--) {
    carro = *pop(&aux);
    push(p, carro.placa, carro.manobras);
  }
}
