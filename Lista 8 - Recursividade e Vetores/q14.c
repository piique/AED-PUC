#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int *vetor, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("Digite um numero: ");
    scanf("%i", &vetor[i]);
  }
}

// ordena vetor atraves do metodo bolha
void ordenaVetor(int *vetor, int n)
{
  int aux;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  }
}

void buscaSegundoMenor(int *vetor, int n, int *segundoMenor)
{
  *segundoMenor = vetor[n - 1]; // coloca o maior valor na variavel segundoMenor
  for (int i = 1; i < n; i++)
  {
    if (vetor[i] < *segundoMenor && vetor[i] != vetor[0])
    {
      *segundoMenor = vetor[i];
    }
  }
}

int main()
{
  // declara variaveis
  int tamanhoVetor, segundoMenor;

  printf("Digite a quantidade de numeros: ");
  scanf("%i", &tamanhoVetor);
  if (tamanhoVetor <= 0)
  {
    printf("\nValor invalido!");
    return 0;
  }

  // declara o vetor
  int vetor[tamanhoVetor];

  // preenche o vetor
  preencheVetor(vetor, tamanhoVetor);

  // ordena o vetor de forma crescente
  ordenaVetor(vetor, tamanhoVetor);

  // busca o valor do segundo menor e armazena na variavel segundoMenor
  buscaSegundoMenor(vetor, tamanhoVetor, &segundoMenor);

  // printa o vetor
  for (int i = 0; i < tamanhoVetor; i++)
    printf("\nVetor[%i]: %i", i, vetor[i]);

  printf("\nMenor: %i", vetor[0]);
  printf("\nSegundo menor: %i", segundoMenor);

  return 0;
}