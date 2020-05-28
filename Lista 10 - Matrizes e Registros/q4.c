#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define M 3
#define maxAleatorio 99

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
int linhaMaiorValor(float matriz[][M], int n, int m);

int main() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  linhaMaiorValor(matriz, N, M);

  return 0;
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
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%0.0f ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
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