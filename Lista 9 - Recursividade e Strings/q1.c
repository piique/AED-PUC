#include <stdio.h>

int procuraNoVetor(int vetor[], int k, int tamanhoVetor);

int main()
{
  int vetor[5] = {1, 2, 3, 4, 5}, k = 6, resultado;

  resultado = procuraNoVetor(vetor, k, 5);

  if (resultado == -1)
  {
    printf("Nao foi encontrado o valor %i no vetor\n", k);
  }
  else
  {
    printf("O valor %i foi encontrado no vetor na posicao %i. Vetor[%i]: %i\n", k, resultado, k, resultado);
  }
  return 0;
}

/*
Descrição: retorna a posição em que k foi encontrado ou -1
Entradas: um vetor, seu tamanho e um valor a ser procurado 
Saída: retorna a posicao que k foi encontrada ou -1
*/
int procuraNoVetor(int vetor[], int k, int tamanhoVetor)
{
  if (vetor[tamanhoVetor - 1] == k || tamanhoVetor == 0)
  {
    return tamanhoVetor - 1;
  }
  return procuraNoVetor(vetor, k, --tamanhoVetor);
}