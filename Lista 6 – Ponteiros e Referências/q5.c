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
  float C = 12.0;
  double D = 14.0;

  char *Ap = &A;
  int *Bp = &B;
  float *Cp = &C;
  double *Dp = &D;

  printf("\n\nO endereco do char A e %p . Essa variavel ocupa %d bytes.\n", &A, sizeof(A));
  printf("O endereco do int B e %p . Essa variavel ocupa %d bytes.\n", &B, sizeof(B));
  printf("O endereco do float C e %p . Essa variavel ocupa %d bytes.\n", &C, sizeof(C));
  printf("O endereco do double D e %p . Essa variavel ocupa %d bytes.\n\n", &D, sizeof(D));

  printf("\nO endereco do char *A e %p . Essa variavel ocupa %d bytes.\n", &Ap, sizeof(Ap));
  printf("O endereco do int *B e %p . Essa variavel ocupa %d bytes.\n", &Bp, sizeof(Bp));
  printf("O endereco do float *C e %p . Essa variavel ocupa %d bytes.\n", &Cp, sizeof(Cp));
  printf("O endereco do double *D e %p . Essa variavel ocupa %d bytes.\n\n", &Dp, sizeof(Dp));
}