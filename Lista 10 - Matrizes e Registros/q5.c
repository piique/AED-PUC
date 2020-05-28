#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 4
#define maxAleatorio 99

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
void qtdMaiorMedia(float matriz[][M], int n, int m);

int main() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  qtdMaiorMedia(matriz, N, M);

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