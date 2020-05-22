#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 3
#define maxAleatorio 9

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
void maiorAcimaDiagonal(float matriz[][M], int n, int m);

int main() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  maiorAcimaDiagonal(matriz, N, M);

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