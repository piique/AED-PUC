#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int procuraNoVetor(int vetor[], int k, int tamanhoVetor);
void preencheVetor(int *vetor, int tamanho);
void printaVetor(int vetor[], int tamanho);

int main() {
  int vetor[5], k, resultado;

  preencheVetor(vetor, 5);
  printaVetor(vetor, 5);

  printf("Digite um valor a ser procurado no vetor acima: ");
  scanf("%i", &k);

  resultado = procuraNoVetor(vetor, k, 5);
  if (resultado == -1) {
    printf("Nao foi encontrado o valor %i no vetor\n", k);
  } else {
    printf("O valor %i foi encontrado no vetor na posicao %i. Vetor[%i]: %i\n", k, resultado, k, resultado);
  }
  return 0;
}

/*
Descrição: retorna a posição em que k foi encontrado ou -1
Entradas: um vetor, seu tamanho e um valor a ser procurado 
Saída: retorna a posicao que k foi encontrada ou -1
*/
int procuraNoVetor(int vetor[], int k, int tamanhoVetor) {
  if (vetor[tamanhoVetor - 1] == k || tamanhoVetor == 0) {
    return tamanhoVetor - 1;
  }
  return procuraNoVetor(vetor, k, --tamanhoVetor);
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
