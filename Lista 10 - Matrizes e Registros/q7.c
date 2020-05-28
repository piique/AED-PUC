#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 3
#define maxAleatorio 9

void preencheMatriz(float[][M], int, int, int opc);
void printMatriz(float[][M], int, int);
float diferencaMaiorAcimaAbaixo(float matriz[][M], int n, int m);

int main() {
  float matriz[N][M];
  preencheMatriz(matriz, N, M, 0);
  printf("\nMatriz[%i][%i] gerada aleatoriamente: \n", N, M);
  printMatriz(matriz, N, M);
  printf("\nDiferenca entre maior valor acima e maior valor abaixo da diagonal principal: %0.2f\n", diferencaMaiorAcimaAbaixo(matriz, N, M));

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