#include "stdio.h"
#include "time.h"

int Random(int min, int max);
void buscaValor(int[][10]);

int main() {
  int a[10][10];

  // inicializa rand com timestamp atual para gerar numeros aleatorios a partir dele
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      a[i][j] = Random(15, 50);
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  buscaValor(a);

  return 0;
}

// gerar numero aleatorio em um intervalo de valor
int Random(int min, int max) {
  return (min + (rand() % ((max + 1) - min)));
}

// buscar valor na matriz e printa sua posição ou printa "Valor nao encontrado!"
void buscaValor(int matriz[][10]) {
  int retorno = -1, valor;
  printf("Digite um valor para ser procurado na matriz: ");
  scanf("%i", &valor);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (matriz[i][j] == valor) {
        printf("\nValor encontrado na posicao [%d, %d]", i, j);
        return;
      }
    }
  }

  printf("\nValor nao encontrado!");
}