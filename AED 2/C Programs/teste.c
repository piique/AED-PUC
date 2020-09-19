#include <stdio.h>
#include <string.h>

void insercao(int vet[], int n) {
  int movi = 0, aux = 0;
  int comp = 0;
  for (int j = 1; j < n; j++) {
    int temp = vet[j];
    printf("Houve movimentacao de %i(Temp) para vet[%i]\n", temp, j);
    movi++;
    int i;
    comp++;
    for (i = j - 1; i >= 0 && vet[i] > temp; i--) {
      vet[i + 1] = vet[i];
      printf("Houve movimentacao da posicao vet[%i] para a posicao vet[%i]\n", i + 1, i);
      movi++;
      aux++;
      if (aux > 1) {
        comp++;
      }
    }
    vet[i + 1] = temp;
    printf("Houve movimentacao de vet[%i] para Temp\n", i + 1);
    movi++;
  }
  printf("O total de movimentação %i \n", movi);
  printf("O total de comparação %i \n", comp);
}

int main(void) {
  // int vet[18] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
  // int vet[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
  int vet[18] = {18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  insercao(vet, 18);
  for (int i = 0; i < 18; i++) {
    printf("%d ", vet[i]);
  }
  return 0;
}
