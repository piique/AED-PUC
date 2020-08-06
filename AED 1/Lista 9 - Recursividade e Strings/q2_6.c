#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *vetor, int tamanho);
void printaVetor(int vetor[], int tamanho);
int maxVetor(int vetor[], int tamanho);
int minVetor(int vetor[], int tamanho);
int somaVetor(int vetor[], int tamanho);
int multiplicaVetor(int vetor[], int tamanho);
float mediaVetor(int[], int);
float _mediaVetor(int[], int, int, int);

int main() {
  // tamanho vetor = sizeof(vetor)/sizeof(vetor[0]);
  int tamanho = 5, vetor[5] = {2, 6, 4, 6, 2};
  // int tamanho = 5, vetor[tamanho];
  // preencheVetor(vetor, tamanho);
  printf("Vetor gerado aleatoriamente: ");
  printaVetor(vetor, tamanho);

  printf("Valor maximo do vetor: %i\n", maxVetor(vetor, tamanho));
  printf("Valor minimo do vetor: %i\n", minVetor(vetor, tamanho));
  printf("Valor da soma do vetor: %i\n", somaVetor(vetor, tamanho));
  printf("Valor do produto do vetor: %i\n", multiplicaVetor(vetor, tamanho));
  printf("Valor da media do vetor: %0.2f\n", mediaVetor(vetor, tamanho));

  return 0;
}

/*
Descrição: retorna o maior elemento do vetor de inteiro
Entradas: um vetor de inteiro e seu tamanho
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
Descrição: retorna o menor elemento do vetor de inteiro
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna o menor elemento do vetor
*/
int minVetor(int vetor[], int tamanho) {
  int min;
  if (tamanho == 1) {
    min = vetor[0];
  } else {
    min = minVetor(vetor, tamanho - 1);
    if (vetor[tamanho - 1] < min) {
      min = vetor[tamanho - 1];
    }
  }
  return min;
}

/*
Descrição: retorna a soma dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna a soma dos elementos
*/
int somaVetor(int vetor[], int tamanho) {
  if (tamanho == 1) {
    return vetor[tamanho - 1];
  }
  tamanho--;
  return vetor[tamanho] + somaVetor(vetor, tamanho);
}

/*
Descrição: retorna o produto dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna o produto dos elementos
*/
int multiplicaVetor(int vetor[], int tamanho) {
  if (tamanho == 1) {
    return vetor[tamanho - 1];
  }
  tamanho--;
  return vetor[tamanho] * multiplicaVetor(vetor, tamanho);
}

/*
Descrição: retorna a media dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna a media dos elementos
*/
float mediaVetor(int vetor[], int tamanho) {
  return _mediaVetor(vetor, tamanho, 0, tamanho);
}

/*
Descrição: retorna a media dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro, seu tamanho e a soma inicial
Saída: retorna a media dos elementos
*/
float _mediaVetor(int vetor[], int tamanho, int soma, int aux) {
  if (tamanho == 0)
    return (float)soma / (aux - 1);

  soma += vetor[tamanho - 1];
  return _mediaVetor(vetor, --tamanho, soma, aux);
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
