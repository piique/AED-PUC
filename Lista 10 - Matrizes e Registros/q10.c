#include <stdio.h>

struct Jogada {
  int ordem;
  int x;
  int y;
};

void solicitaJogada(struct Jogada *lista, int tamanhoLista);
int validaPosicao(struct Jogada *lista, int, int, int);
void printaTabuleiro(struct Jogada *lista);
void preencheJogadaPronta(struct Jogada *lista);

void solicitaJogada(struct Jogada *lista, int tamanhoLista) {
  int x, y;
  for (int i = 0; i < tamanhoLista; i++) {
    printf("Digite a posicao da %iª rainha (x,y): ", i + 1);
    scanf("%i %i", &x, &y);

    while (x < 1 || x > 8 || y < 1 || y > 8) {
      printf("Apenas numeros de 1 a 8 aceito para as coordenadas x e y. Digite outra: ");
      scanf("%i %i", &x, &y);
    }

    while (!validaPosicao(lista, tamanhoLista, x, y)) {
      printf("Posicao ja preenchida! Digite outra: ");
      scanf("%i %i", &x, &y);
    }

    lista[i].ordem = i;
    lista[i].x = x;
    lista[i].y = y;
    printaTabuleiro(lista);

    printf("Lista[%i]: x=%i y=%i\n", i, lista[0].x, lista[0].y);
  }
}

int validaPosicao(struct Jogada *lista, int tamanhoLista, int x, int y) {
  for (int i = 0; i < tamanhoLista; i++) {
    if (lista[i].x == x && lista[i].y == y) {
      return 0;
    }
  }
  return 1;
}

void printaTabuleiro(struct Jogada *lista) {
  // tabuleiro de 8x8
  int aux = 0;
  printf("  ---------------------------------\n");
  for (int y = 8; y > 0; y--) {
    printf("%i ", y);
    for (int x = 1; x <= 8; x++) {
      for (int k = 0; k < 8; k++) {
        if (lista[k].x == x && lista[k].y == y) {
          printf("| R ");
          aux = 1;
        }
      }
      if (aux == 1) {
        aux = 0;
      } else {
        printf("|   ");
      }
    }
    printf("|\n");
    // printf("   --- --- --- --- --- --- --- --- \n");
  }
  printf("  ---------------------------------\n");
  printf("    1   2   3   4   5   6   7   8\n");
}

void preencheJogadaPronta(struct Jogada *lista) {
  lista[0].x = 1;
  lista[0].y = 4;

  lista[1].x = 2;
  lista[1].y = 2;

  lista[2].x = 3;
  lista[2].y = 7;

  lista[3].x = 4;
  lista[3].y = 3;

  lista[4].x = 5;
  lista[4].y = 6;

  lista[5].x = 6;
  lista[5].y = 8;

  lista[6].x = 7;
  lista[6].y = 5;

  lista[7].x = 8;
  lista[7].y = 1;
}

int validaVitoria(struct Jogada *lista, int tamanhoLista) {
  int vitoria = 1;
  int tabuleiro[8][8];

  int validaLinha[8];   // quantidade de linhas possiveis
  int validaColuna[8];  // quantidade de colunas possiveis
  // int validaDiagonal[26];  // 26 diagonais em uma matriz 8x8
  int vetor[tamanhoLista];

  // preenche vetores de validacao com 0 em todas as posicoes
  for (int i = 8; i > 0; i--) {
    validaLinha[i] = 0;
    validaColuna[i] = 0;
    for (int j = 1; j <= 8; j++) {
      tabuleiro[i - 1][j - 1] = 0;
    }
  }

  // preenche os vetores de validacao em caso de ocorrencia e o tabuleiro
  for (int k = 0; k < tamanhoLista; k++) {
    tabuleiro[lista[k].x - 1][lista[k].y - 1] = 1;
    validaColuna[lista[k].x - 1]++;
    validaLinha[lista[k].y - 1]++;
  }

  // valida os vetores de validacao
  for (int i = 0; i < 8; i++) {
    printf("Valida Coluna[%i]: %i\n", i + 1, validaColuna[i]);
    if (validaColuna[i] > 1) {
      vitoria = 0;
    }
  }
  for (int i = 0; i < 8; i++) {
    printf("Valida Linha[%i]: %i\n", i + 1, validaLinha[i]);
    if (validaLinha[i] > 1) {
      vitoria = 0;
    }
  }

  for (int i = 8; i >= 1; i--) {
    for (int j = 1; j <= 8; j++) {
      if (tabuleiro[i - 1][j - 1]) {
        // veridicaDiagonais retorna 1 se errado
        if (verificaDiagonais(tabuleiro, i - 1, j - 1)) {
          vitoria = 0;
        }
      }
    }
  }

  printf("Retorno: %s\n", vitoria == 0 ? "perdeu" : "ganhou");

  return vitoria;
}

int verificaDiagonais(int tabuleiro[][8], int x, int y) {
  // recebe tabuleiro preenchido com 0 em posições vazias e com 1 nas rainhas
  // logica para verificar existencia de diagonal
  int retorno = 0;
  int auxX = x;
  int auxY = y;

  // verifica diagonal Noroeste
  while (x + 1 < 9 && y + 1 > 0) {
    if (tabuleiro[x - 1, y - 1]) {
      return 1;
    }
    x++;
    y--;
  }

  x = auxX;
  y = auxY;
  // verifica diagonal Nordeste
  while (x + 1 > 0 && y + 1 > 0) {
    if (tabuleiro[x - 1, y - 1]) {
      return 1;
    }
    x--;
    y--;
  }

  x = auxX;
  y = auxY;
  // verifica diagona Sudoeste
  while (x + 1 < 9 && y + 1 < 9) {
    if (tabuleiro[x - 1, y - 1]) {
      return 1;
    }
    x++;
    y++;
  }

  x = auxX;
  y = auxY;
  // verifica diagonal Sudeste
  while (x + 1 > 0 && y + 1 < 9) {
    if (tabuleiro[x - 1, y - 1]) {
      return 1;
    }
    x--;
    y++;
  }
}

int main() {
  printf("\nBem vindo ao Problema das 8 Rainhas\n");

  struct Jogada lista[8];
  int qtdJogadas = -1;

  // solicita quantidade de jogadas
  /*
  printf("Qual a quantidade de jogadas desejadas(2 a 8): ");
  scanf("%i", &qtdJogadas);
  while (qtdJogadas <= 2 || qtdJogadas > 8) {
    printf("Quantidade invalida, apenans valores de 2 a 8: ");
    scanf("%i", &qtdJogadas);
  }
  */
  qtdJogadas = 2;

  // solicitaJogada(lista, qtdJogadas);
  preencheJogadaPronta(lista);

  printaTabuleiro(lista);
  // printf("Lista[0]: x=%i y=%i", lista[0].x, lista[0].y);

  validaVitoria(lista, qtdJogadas);
  return 0;
}