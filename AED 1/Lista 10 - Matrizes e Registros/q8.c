#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 3
#define maxAleatorio 9

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
float printaColunaMatriz(float matriz[][M], int n, int m, int coluna);

int main() {
  float matriz[N][M];
  int coluna;
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  printf("Digite o numero de uma coluna para saber a soma (1-%i): ", M);
  scanf("%i", &coluna);
  printf("Soma dos elementos da coluna: %0.2f\n", printaColunaMatriz(matriz, N, M, coluna));

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