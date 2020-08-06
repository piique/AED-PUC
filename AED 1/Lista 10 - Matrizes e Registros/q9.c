#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 2
#define maxAleatorio 9

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
void printMatrixTranposta(float matriz[][M], int n, int m);

int main() {
  float matriz[N][M];
  int coluna;
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);

  printMatrixTranposta(matriz, N, M);

  return 0;
}

/*
Descrição: recebe uma matrix e preenche com valores aleatorios entre 0 e 10
Entradas: matrix e seu tamanho
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