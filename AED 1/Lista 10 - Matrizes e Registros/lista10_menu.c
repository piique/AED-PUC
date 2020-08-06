#include <locale.h>  // no prompt: chcp 65001 - para funcionar formatação
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // limpar console: system("cls");
#include <time.h>

#define N 3
#define M 2
#define maxAleatorio 99

#ifdef WIN32
#define PAUSE 1
#else
#define PAUSE 0
#endif

// Declaração de funções
void questao1();
void questao2();
void questao3();
void questao4();
void questao5();
void questao6();
void questao7();
void questao8();
void questao9();
void questao10();

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
void copiaMatrix(float matriz[][M], float matrizDestino[][M], int n, int m);
void comparaMatriz(float matriz[][M], float segundaMatriz[][M], int n, int m);
int verificaOcorrencias(float matriz[][M], int n, int m, int k);
int linhaMaiorValor(float matriz[][M], int n, int m);
void qtdMaiorMedia(float matriz[][M], int n, int m);
void maiorAcimaDiagonal(float matriz[][M], int n, int m);
float diferencaMaiorAcimaAbaixo(float matriz[][M], int n, int m);
float printaColunaMatriz(float matriz[][M], int n, int m, int coluna);
void printMatrixTranposta(float matriz[][M], int n, int m);

// inicio questão 10
struct Jogada {
  int ordem;
  int x;
  int y;
};
void systemPause();
void systemClear();
void limpaLista(struct Jogada *lista);
int solicitaJogada(struct Jogada *lista);
int validaPosicao(struct Jogada *lista, int, int, int);
void printaTabuleiro(struct Jogada *lista);
void preencheJogadaPronta(struct Jogada *lista);
int verificaDiagonais(int tabuleiro[][8], int x, int y);
int validaVitoria(struct Jogada *lista, int tamanhoLista);
// fim questão 10

int main() {
  setlocale(LC_ALL, "Portuguese_Brasil");
  int opc = -1;
  while (opc != 0) {
    printf("-------------- MENU --------------");
    printf("\nEscolha uma das questões:  ");
    printf("\n 1    - Questao 1");
    printf("\n 2    - Questao 2");
    printf("\n 3    - Questao 3");
    printf("\n 4    - Questao 4");
    printf("\n 5    - Questao 5");
    printf("\n 6    - Questao 6");
    printf("\n 7    - Questao 7");
    printf("\n 8    - Questao 8");
    printf("\n 9    - Questao 9");
    printf("\n 10   - Questao 10");
    printf("\n 0    - Sair");
    printf("\n\nOpc: ");

    scanf("%i", &opc);

    switch (opc) {
      case 1:
        printf("\n\nQUESTAO 1\n");
        questao1();
        systemPause();
        break;

      case 2:
        printf("\n\nQUESTAO 2\n");
        questao2();
        systemPause();
        break;

      case 3:
        printf("\n\nQUESTAO 3\n");
        questao3();
        systemPause();
        break;

      case 4:
        printf("\n\nQUESTAO 4\n");
        questao4();
        systemPause();
        break;

      case 5:
        printf("\n\nQUESTAO 5\n");
        questao5();
        systemPause();
        break;

      case 6:
        printf("\n\nQUESTAO 6\n");
        questao6();
        systemPause();
        break;
      case 7:
        printf("\n\nQUESTAO 7\n");
        questao7();
        systemPause();
        break;

      case 8:
        printf("\n\nQUESTAO 8\n");
        questao8();
        systemPause();
        break;
      case 9:
        printf("\n\nQUESTAO 9\n");
        questao9();
        systemPause();
        break;

      case 10:
        printf("\n\nQUESTAO 10\n");
        questao10();
        systemPause();
        break;

      case 0:
        printf("Saindo...\n\n");
        return 0;
        break;

      default:
        printf("Escolha invalida! Precione enter para voltar ao menu.\n");
        systemPause();
    }
  }

  return 0;
}

void questao1() {
  int opc;
  float matriz[N][M], matrizCopia[N][M];

  printf("Digite 1 para preencher manualmente e 2 para automatico (): ");
  scanf("%i", &opc);
  preencheMatriz(matriz, N, M, opc);

  printf("\nMatriz de origem: \n");
  printMatriz(matriz, N, M);

  copiaMatrix(matriz, matrizCopia, N, M);

  printf("\nMatriz copiada: \n");
  printMatriz(matrizCopia, N, M);
}

void questao2() {
  float matriz[N][M], segundaMatriz[N][M];

  preencheMatriz(matriz, N, M, 0);
  printf("Matriz: \n");
  printMatriz(matriz, N, M);
  preencheMatriz(segundaMatriz, N, M, 1);
  comparaMatriz(matriz, segundaMatriz, N, M);
}

void questao3() {
  float matriz[N][M], k;
  preencheMatriz(matriz, N, M, 0);
  printf("Matriz: \n");
  printMatriz(matriz, N, M);
  printf("Digite um valor a ser procurado na matriz acima: ");
  scanf("%f", &k);
  printf("\nQuantidade de ocorrencias: %i\n", verificaOcorrencias(matriz, N, M, k));
}

void questao4() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  linhaMaiorValor(matriz, N, M);
}

void questao5() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  qtdMaiorMedia(matriz, N, M);
}

void questao6() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  maiorAcimaDiagonal(matriz, N, M);
}

void questao7() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  printf("\nDiferenca entre maior valor acima e maior valor abaixo da diagonal principal: %0.2f\n", diferencaMaiorAcimaAbaixo(matriz, N, M));
}

void questao8() {
  float matriz[N][M];
  int coluna;
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  printf("Digite o numero de uma coluna para saber a soma (1-%i): ", M);
  scanf("%i", &coluna);
  printf("Soma dos elementos da coluna: %0.2f\n", printaColunaMatriz(matriz, N, M, coluna));
}

void questao9() {
  float matriz[N][M];
  int coluna;
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);

  printMatrixTranposta(matriz, N, M);
}

void questao10() {
  setlocale(LC_ALL, "Portuguese_Brasil");

  int opc = -1;
  struct Jogada lista[8];

  printf("\n    Bem vindo ao Problema das 8 Rainhas\n");
  printf("  O problema das 8 Rainha consiste em colocar 8 Rainhas em tabuleiro de xadrez de forma que nenhuma rainha ataque a outra.\n\n");
  systemPause();

  while (opc != 0) {
    systemClear();
    limpaLista(lista);
    printaTabuleiro(lista);

    int qtdJogadas = solicitaJogada(lista);
    // preencheJogadaPronta(lista);

    printaTabuleiro(lista);
    // printf("Lista[0]: x=%i y=%i", lista[0].x, lista[0].y);
    if (validaVitoria(lista, qtdJogadas) == 0) {
      printf("\n\n\n\n\tA BATALHA EH GRANDE MAS A DERROTA EH CERTA!\n\n\t\tVOCE PERDEU, MAS NAO DESISTA, TENTE NOVAMENTE!!\n\n\n\n");
    }

    systemPause();
    systemClear();
    printf("Deseja continuar?\n 1 - Jogar Novamente\n 0 - Sair\n Opc: ");
    scanf("%i", &opc);
  }

  printf("\n\nObrigado por jogar o jogo! Volte sempre! :) \n\n");
}

/*
Descrição: recebe uma matrix e preenche com valores aleatorios entre 0 e 10
Entradas: matrix(float), seu tamanho e opc 0-preenchimento aleatorio 1-preenchimento manual
Saída: 
*/
void preencheMatriz(float matriz[][M], int n, int m, int opc) {
  // sizeof(vetor) / sizeof(vetor[0]);
  srand(time(NULL));

  if (opc == 1) {
    float value;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        printf("Matix[%i][%i]: ", i, j);
        scanf("%f", &value);
        matriz[i][j] = value;
      }
  } else {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        matriz[i][j] = (float)(rand() % (maxAleatorio + 1));
  }
}

/*
Descrição: recebe uma matrix e printa seus valores
Entradas: ponteiro de vetor e seu tamanho
Saída:
*/
void printMatriz(float matriz[][M], int n, int m) {
  // sizeof(vetor) / sizeof(vetor[0]);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%0.0f ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/*
Descrição: recebe duas matrizes e copia a primeira na segunda
Entradas: 2 matrizes e dois inteiros com as dimensoes das mesmas
Saída: 
*/
void copiaMatrix(float matriz[][M], float matrizDestino[][M], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrizDestino[i][j] = matriz[i][j];
    }
  }
}

/*
Descrição: recebe duas matrizes e copia a primeira na segunda
Entradas: 2 matrizes e dois inteiros com as dimensoes das mesmas
Saída: 
*/
void comparaMatriz(float matriz[][M], float segundaMatriz[][M], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matriz[i][j] != segundaMatriz[i][j]) {
        printf("\nMatrizes sao diferentes\n");
        return;
      }
    }
  }
  printf("\nMatrizes sao iguais\n");
}

/*
Descrição: procura quantas ocorrencias de k em matriz
Entradas: 1 matriz, dois inteiros com as dimensoes da mesma e o valor de k em float
Saída: quantas ocorrencias de k na matriz em inteiro
*/
int verificaOcorrencias(float matriz[][M], int n, int m, int k) {
  int ocorrencias = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matriz[i][j] == k) {
        ocorrencias++;
      }
    }
  }
  return ocorrencias;
}

/*
Descrição: procura na matriz o maior valor e imprime a linha do mesmo
Entradas: 1 matriz(float) e dois inteiros com as dimensoes da mesma
Saída: retorna em inteiro, a linha que o maior elemento esta localizado
*/
int linhaMaiorValor(float matriz[][M], int n, int m) {
  int linhaMaiorValor = 0;  // 0-false, 1-true
  float maiorValor = matriz[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matriz[i][j] > maiorValor) {
        maiorValor = matriz[i][j];
        linhaMaiorValor = i;
      }
    }
  }

  printf("\nLinha %i possui o maior valor", linhaMaiorValor);
  printf("\nMaior valor: %0.0f", maiorValor);
  printf("\nValores da linha: ");
  for (int i = 0; i < m; i++) {
    printf(" %0.0f", matriz[linhaMaiorValor][i]);
  }
  printf("\n");

  return linhaMaiorValor;
}

/*
Descrição: calcula e exiba quantos numeros sao maiores que o valor medio da matriz
Entradas: 1 matriz(float) e dois inteiros com as dimensoes da mesma
Saída: printa quais e quantos numeros sao maiores que o valor medio da matriz
*/
void qtdMaiorMedia(float matriz[][M], int n, int m) {
  float media, soma = 0;
  int qtdMaiorMedia = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      soma += matriz[i][j];
    }
  }
  media = soma / (n * m);

  printf("\nMedia: %0.2f", media);
  printf("\nNumeros maiores que a media: ");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matriz[i][j] > media) {
        qtdMaiorMedia++;
        printf(" %0.2f", matriz[i][j]);
      }
      soma += matriz[i][j];
    }
  }

  printf("\nQuantidade de numeros maiores que a media: %i", qtdMaiorMedia);
  printf("\n");
}

/*
Descrição: calcula e mostra o maior valor acima da diagonal principal da matriz (não considera a própria diagonal).
Entradas: 1 matriz(float) e dois inteiros com as dimensoes da mesma
Saída: printa qual o maior valor acima da diagonal principal da matriz sem considerar a mesma
*/
void maiorAcimaDiagonal(float matriz[][M], int n, int m) {
  if (n < 2 || m < 2) {
    printf("\nNao possui diagonal\n");
    return;
  }

  int auxj = 0;
  float maiorValor = matriz[0][1];  // declara o maior valor com o primeiro numero acima da diagonal

  printf("Numeros acima da diagonal principal: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > auxj) {
        printf("%0.2f | ", matriz[i][j]);
        if (matriz[i][j] > maiorValor)
          maiorValor = matriz[i][j];
        // printf("Matriz[%i][%i]: %0.2f\n", i, j, matriz[i][j]);
      }
    }
    auxj++;
  }

  printf("\nMaior valor acima da diagonal principal (sem considerar a propria diagonal): %0.f\n", maiorValor);
}

/*
Descrição: calcula e mostra a diferenca entre o maior valor acima e o maior abaixo da diagonal principal da matriz (não considera a própria diagonal).
Entradas: 1 matriz(float) e dois inteiros com as dimensoes da mesma
Saída: retorna a diferenca entre o maior numero acima da diagonal e o menor
*/
float diferencaMaiorAcimaAbaixo(float matriz[][M], int n, int m) {
  if (n < 2 || m < 2) {
    printf("\nNao possui diagonal\n");
    return;
  }

  int aux = 0;                            // utilizado para identificar a diagonal da matriz: [?][aux]
  float maiorValorAcima = matriz[0][1];   // declara o maior valor com o primeiro numero acima da diagonal
  float maiorValorAbaixo = matriz[1][0];  // declara o maior valor com o primeiro numero abaixo da diagonal

  // printf("Numeros acima da diagonal principal: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > aux) {
        if (matriz[i][j] > maiorValorAcima) {
          maiorValorAcima = matriz[i][j];
        }
      }
      if (j < aux) {
        if (matriz[i][j] > maiorValorAbaixo) {
          maiorValorAbaixo = matriz[i][j];
        }
      }
    }
    aux++;
  }

  printf("Maior valor acima : %0.0f", maiorValorAcima);
  printf("\nMaior valor abaixo : %0.0f\n", maiorValorAbaixo);
  // printf("\nDiferenca entre maior valor acima e maior valor abaixo: %0.2f\n", maiorValorAcima - maiorValorAbaixo);

  return maiorValorAcima - maiorValorAbaixo;
}

/*
Descrição: recebe uma matriz e calcula a soma dos elementos da coluna recebida
Entradas: 1 matriz(float), dois inteiros com as dimensoes da mesma e a coluna desejada
Saída: retorna em float a soma dos elementos
*/
float printaColunaMatriz(float matriz[][M], int n, int m, int coluna) {
  float soma = 0;

  // printf("Numeros acima da diagonal principal: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == coluna - 1)
        soma += matriz[i][j];
    }
  }

  return soma;
}

/*
Descrição: recebe uma matriz e printa sua trasposta
Entradas: 1 matriz(float), dois inteiros com as dimensoes da mesma
Saída: printa a matriz tranposta
*/
void printMatrixTranposta(float matriz[][M], int n, int m) {
  //cria a matriz transposta
  float transposta[m][n];

  // preenche e printa a matriz transposta
  printf("Matriz transposta[%i][%i]: \n", m, n);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      transposta[j][i] = matriz[i][j];
      printf("%0.0f ", j, i, transposta[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

// inicio funções questão 10

int solicitaJogada(struct Jogada *lista) {
  // solicita quantidade de jogadas
  int x, y, qtdJogadas = -1;
  printf("Quantidade de Rainhas que deseja colocar(2 a 8): ");
  scanf("%i", &qtdJogadas);
  while (qtdJogadas < 2 || qtdJogadas > 8) {
    printf("Quantidade invalida, apenas valores de 2 a 8: ");
    scanf("%i", &qtdJogadas);
  }

  for (int i = 0; i < qtdJogadas; i++) {
    printf("Digite a posicao da %iª rainha (x,y): ", i + 1);
    scanf("%i %i", &x, &y);

    while (x < 1 || x > 8 || y < 1 || y > 8) {
      printf("Apenas numeros de 1 a 8 aceito para as coordenadas x e y. Digite outra: ");
      scanf("%i %i", &x, &y);
    }

    while (!validaPosicao(lista, qtdJogadas, x, y)) {
      printf("Posicao ja ocupada! Digite outra: ");
      scanf("%i %i", &x, &y);
    }

    lista[i].ordem = i + 1;
    lista[i].x = x;
    lista[i].y = y;
    systemClear();
    printaTabuleiro(lista);
    // if (validaVitoria(lista, qtdJogadas)) {
    //   printf("Jogada valida");
    // }
  }

  return qtdJogadas;
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
  printf("    Y ^\n");
  printf("      | ---------------------------------\n");
  for (int y = 8; y > 0; y--) {
    printf("    %i | ", y);
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
  printf("        ------------------------------------- >\n");
  printf("          1   2   3   4   5   6   7   8      X\n\n\n");
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

// retorna 1 se tabuleiro valido
int validaVitoria(struct Jogada *lista, int tamanhoLista) {
  int tabuleiro[8][8];

  int validaLinha[8];   // quantidade de linhas possiveis
  int validaColuna[8];  // quantidade de colunas possiveis

  // preenche vetores de validacao e tabuleiro com 0
  for (int i = 8; i > 0; i--) {
    validaLinha[i - 1] = 0;
    validaColuna[i - 1] = 0;
    for (int j = 1; j <= 8; j++) {
      tabuleiro[i - 1][j - 1] = 0;
    }
  }

  // preenche os vetores de validacao em caso de ocorrencia e o tabuleiro com 1 quando rainha
  for (int k = 0; k < tamanhoLista; k++) {
    tabuleiro[lista[k].x - 1][lista[k].y - 1] = 1;
    validaColuna[lista[k].x - 1]++;
    validaLinha[lista[k].y - 1]++;
  }

  // valida as diagonais e os vetores de validacao (vertical e horizontal)
  for (int i = 8; i >= 1; i--) {
    if (validaColuna[i - 1] > 1)
      return 0;

    if (validaLinha[i - 1] > 1)
      return 0;
    // veridicaDiagonais retorna 1 se errado
    for (int j = 1; j <= 8; j++)
      if (tabuleiro[i - 1][j - 1] != 0)
        if (verificaDiagonais(tabuleiro, i - 1, j - 1))
          return 0;
  }

  printf("\n\n\tPARABENS!!! VC GANHOU!\n\n");

  return 1;
}

//verifica as 4 diagonais de uma determinada coordenada
int verificaDiagonais(int tabuleiro[][8], int x, int y) {
  // recebe tabuleiro preenchido com 0 em posições vazias e com 1 nas rainhas
  // logica para verificar existencia de diagonal
  int retorno = 0;
  int auxX = x;
  int auxY = y;

  // verifica diagonal Noroeste
  x--;
  y++;
  while (x >= 0 && y < 8) {
    if (tabuleiro[x][y]) {
      return 1;
    }
    x--;
    y++;
  }

  // verifica diagonal Nordeste
  x = auxX;
  y = auxY;
  x++;
  y++;
  while (x < 8 && y < 8) {
    if (tabuleiro[x][y]) {
      return 1;
    }
    x++;
    y++;
  }

  // verifica diagona Sudoeste
  x = auxX;
  y = auxY;
  x--;
  y--;
  while (x >= 0 && y >= 0) {
    if (tabuleiro[x][y]) {
      return 1;
    }
    x--;
    y--;
  }

  // verifica diagonal Sudeste
  x = auxX;
  y = auxY;
  x++;
  y--;
  while (x < 8 && y >= 0) {
    if (tabuleiro[x][y]) {
      return 1;
    }
    x++;
    y--;
  }

  // retorna 0 se todas as 4 diagonais forem validas
  return 0;
}

void limpaLista(struct Jogada *lista) {
  for (int i = 0; i < 8; i++) {
    lista[i].ordem = -1;
    lista[i].x = -1;
    lista[i].y = -1;
  }
}

void systemPause() {
  if (PAUSE == 1) {
    printf("Precione enter para continuar");
    system("pause");
  } else {
    system("read -p 'Precione enter para continuar' continuar");
  }
}

void systemClear() {
  if (PAUSE == 1) {
    system("cls");
  } else {
    system("clear");
  }
}