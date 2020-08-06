#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define M 2
#define maxAleatorio 99

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
int verificaOcorrencias(float matriz[][M], int n, int m, int k);

int main() {
  float matriz[N][M], k;
  preencheMatriz(matriz, N, M, 0);
  printf("Matriz: \n");
  printMatriz(matriz, N, M);
  printf("Digite um valor a ser procurado na matriz acima: ");
  scanf("%f", &k);
  printf("\nQuantidade de ocorrencias: %i\n", verificaOcorrencias(matriz, N, M, k));

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