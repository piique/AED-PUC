#include <stdio.h>

// função para realizar troca e printar cada movimentação da mesma
void swap(int menor, int i, int array[]) {
  int aux = array[i];
  printf("Troca %i\n", i + 1);
  printf("aux = array[%i](%i)\n", i, array[i]);

  printf("array[%i](%i) = array[%i](%i)\n", i, array[i], menor, array[menor]);
  array[i] = array[menor];

  printf("array[%i](%i) = aux(%i)\n\n", menor, array[menor], aux);
  array[menor] = aux;
}

int main(void) {
  int n = 18, movimentacoes = 0, comparacoes = 0;
  int array[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

  for (int i = 0; i < (n - 1); i++) {
    int menor = i;
    for (int j = (i + 1); j < n; j++) {
      comparacoes++;
      // printando comparações
      printf("%i: %i > %i\n", comparacoes, array[menor], array[j]);  // decomentar linha para printar comparações realizadas
      if (array[menor] > array[j]) {
        menor = j;
      }
    }
    // printf("Movimentacao %i: ", movimentacoes + 1);
    swap(menor, i, array);
    movimentacoes += 3;
  }

  printf("Trocas totais: %i\n", movimentacoes / 3);
  printf("Movimentacoes totais: %i\n", movimentacoes);
  printf("Comparacoes totais: %i\n", comparacoes);

  return 0;
}
