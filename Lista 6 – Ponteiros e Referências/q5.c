#include <stdio.h>

void deslocaEsquerda(int *a, int *b, int *c, int *d, int *e);

/*
Descrição: Printar endereço de memoria de cada tipo de variavel e mostrar quantos bytes cada um ocupa.
Entradas: Não possui entrada
Saída: Não possui saida
*/
void main()
{
  char A = 'A';
  int B = 10;
  float C = 10.0;
  double D = 10.0;
  printf("\n\nO endereco do char A e %p . Essa variavel ocupa %d bytes.\n", &A, sizeof(A));
  printf("O endereco do int B e %p . Essa variavel ocupa %d bytes.\n", &B, sizeof(B));
  printf("O endereco do float C e %p . Essa variavel ocupa %d bytes.\n", &C, sizeof(C));
  printf("O endereco do double D e %p . Essa variavel ocupa %d bytes.\n\n", &D, sizeof(D));
}