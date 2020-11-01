#include "pessoa.h"

// PROCEDIMENTO PARA TROCAR DOIS ELEMENTOS DO VETOR
void swap(Pessoa *i, Pessoa *j) {
  Pessoa temp = *i;
  *i = *j;
  *j = temp;
}

void quicksortRec(Pessoa *array, int esq, int dir) {
  int i = esq, j = dir;
  int pivo = array[(dir + esq) / 2].idade;
  while (i <= j) {
    while (array[i].idade < pivo) i++;
    while (array[j].idade > pivo) j--;
    if (i <= j) {
      swap(array + i, array + j);
      i++;
      j--;
    }
  }
  if (esq < j) quicksortRec(array, esq, j);
  if (i < dir) quicksortRec(array, i, dir);
}

void quicksort(Pessoa *array, int n) {
  quicksortRec(array, 0, n - 1);
}
