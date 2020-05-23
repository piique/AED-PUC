#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 2
#define maxAleatorio 99

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);

int main() {
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