#include <stdio.h>

int procuraNoVetor(int vetor[], int k, int tamanhoVetor);

int main()
{
  int vetor[5] = {1, 2, 3, 4, 5}, k = 6, resultado;

  resultado = procuraNoVetor(vetor, k, 5);

  if (resultado == -1)
  {
    printf("Nao foi encontrado o valor %i no vetor", k);
  }
  else
  {
    printf("O valor %i foi encontrado no vetor na posicao %i. Vetor[%i]: %i", k, resultado, k, resultado);
  }
  getch();
  return 0;
}

int procuraNoVetor(int vetor[], int k, int tamanhoVetor)
{
  if (vetor[tamanhoVetor - 1] == k || tamanhoVetor == 0)
  {
    return tamanhoVetor - 1;
  }
  return procuraNoVetor(vetor, k, --tamanhoVetor);
}