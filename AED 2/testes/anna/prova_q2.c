#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetor(int valor);
void printaVetor(int vetor[], int tamanho);
void ordenaVetor(int v[], int n);

int main() {
  int tamanho;
  srand(time(NULL));

  printf("Digite um tamanho: ");
  scanf("%i", &tamanho);

  int *vetor = criaVetor(tamanho);

  printf("\nVetor gerado: ");
  // printa vetor gerado aleatoriamente de tamanho tamanho
  printaVetor(vetor, tamanho);

  // ordena vetor com metodo bolha
  ordenaVetor(vetor, tamanho);

  printf("\nVetor ordenado de forma decrescente: ");
  // printa vetor ordenado de forma decrescente
  printaVetor(vetor, tamanho);

  free(vetor);

  return 0;
}

// printando vetor
void printaVetor(int vetor[], int tamanho) {
  printf("\n");
  for (int i = 0; i < tamanho; i++) {
    printf("%i ", vetor[i]);
  }

  printf("\n");
}

// cria vetor e retorna ponteiro para ele
int *criaVetor(int tamanho) {
  int *vetor = (int *)malloc(tamanho * sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    vetor[i] = (1 + (rand() % ((15 + 1) - 1)));
  }

  return vetor;
}

// realiza ordenação do vetor através do método bolha
void ordenaVetor(int v[], int n) {
  int aux;
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i] < v[i + 1]) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }
}