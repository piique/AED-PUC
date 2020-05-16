#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *vetor, int tamanho);
void printaVetor(int vetor[], int tamanho);

int vec_len(int *vec) {
  int c = -1;
  while (*(vec++)) c++;
  return c;
}
int maxVetor(int vetor[], int tamanho);

int main() {
  // tamanho vetor = sizeof(vetor)/sizeof(vetor[0]);
  int tamanho = 5, vetor[tamanho], max;
  preencheVetor(vetor, tamanho);
  printaVetor(vetor, tamanho);

  printf("Valor maximo do vetor: %i\n", maxVetor(vetor, tamanho));

  return 0;
}

/*
Descrição: retorna o maior elemento do vetor
Entradas: um vetor e seu tamanho
Saída: retorna o maior elemento do vetor
*/
int maxVetor(int vetor[], int tamanho) {
  int max;
  if (tamanho == 1) {
    max = vetor[0];
  } else {
    max = maxVetor(vetor, tamanho - 1);
    if (vetor[tamanho - 1] > max) {
      max = vetor[tamanho - 1];
    }
  }
  return max;
}

/*
Descrição: recebe um vetor e preenche com valores aleatorios entre 0 e 10
Entradas: ponteiro de vetor e seu tamanho
Saída: retorna vetor por referencia
*/
void preencheVetor(int *vetor, int tamanho) {
  // sizeof(vetor) / sizeof(vetor[0]);
  srand(time(NULL));
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % 11;  // numeros aleatorios entre 0 e 10
  }
}

/*
Descrição: recebe um vetor inteiro e printa seus valores
Entradas: ponteiro de vetor e seu tamanho
Saída: nao possui
*/
void printaVetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("\nVetor[%i]: %i  ", i, vetor[i]);
  }
  printf("\n\n");
}