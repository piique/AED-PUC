#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h> // limpar console: system("cls");
#include <locale.h> // no prompt: chcp 65001 - para funcionar formatação

// declaração de funções
void maiorEMenor(float n1, float n2, float n3, float *min, float *max);
void media3(float n1, float n2, float n3, float *media);
void nand(int n1, int n2, int *result);
void deslocaEsquerda(int *n1, int *n2, int *n3, int *n4, int *n5);
void descreveVariaveis();

int main()
{
  setlocale(LC_ALL, "Portuguese_Brasil");
  int testando = 0; // testando - 1;
  int opc = -1;
  float n1, n2, n3, maior, menor, media;    // questões 1 e 2
  int num1, num2, num3, num4, num5, result; // questões 3 e 4

  while (opc != 0)
  {
    system("cls");
    printf("------------------------------------ MENU ------------------------------------");
    printf("\nEscolha uma das questões:  ");
    printf("\n 1 - Retornar maior e menor elemento por referencia");
    printf("\n 2 - Calcular media usando parametros por referencia");
    printf("\n 3 - Receber A e B e retornar o valor verdade de ⌐ (A ^ B)");
    printf("\n 4 - Deslocar valores para esquerda: a=5, b=9, c=1, d=6, e=19 para a=19, b=5, c=9, d=1, e=6");
    printf("\n 5 - Mostra o  valor, endereco e tamanho na memoria para os principais tipos de variavel");
    printf("\n 6 - Relatorio da observacao do trecho de codigo passado na questao");
    printf("\n 0 - Sair");
    printf("\n\nOpc: ");

    scanf("%i", &opc);

    switch (opc)
    {
    case 1:
      printf("Digite 3 numeros: ");
      scanf("%f %f %f", &n1, &n2, &n3);
      maiorEMenor(n1, n2, n3, &menor, &maior);
      printf("\nMair elemento: %0.2f\nMenor elemento: %0.2f \n", maior, menor);
      break;
    case 2:
      printf("\nDigite 3 numeros: ");
      scanf("%f %f %f", &n1, &n2, &n3);
      media3(n1, n2, n3, &media);

      printf("\nMedia: %0.2f\n\n", media);
      break;

    case 3:
      do
      {
        printf("Digite 2 valores booleanos (0 ou 1): ");
        scanf("%i %i", &num1, &num2);
        if ((num1 == 0 || num1 == 1) && (num2 == 0 || num2 == 1))
        {
          nand(num1, num2, &result);
          printf("\n%i nand %i: %i\n\n", num1, num2, result);
        }
        else
        {
          printf("Numeros digitados devem ser 0 ou 1! Tente novamente\n\n");
        }
      } while ((num1 != 0 && num1 != 1) || (num2 != 0 && num2 != 1));
      break;

    case 4:
      num1 = 5;
      num2 = 9;
      num3 = 1;
      num4 = 6;
      num5 = 19;
      if (!testando)
      {
        printf("\nDigite 5 numeros: ");
        scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);
      }
      deslocaEsquerda(&num1, &num2, &num3, &num4, &num5);
      break;

    case 5:
      descreveVariaveis();
      break;

    case 6:
      printf("Observo que as saidas permanecem a mesma ao mudar as funcoes. Na funcao misterio 2, nao eh atribuindo um valor para y deixando o mesmo com lixo de memoria (um ponteiro apontando para o ultimo inteiro declarado.) ");
      break;

    case 0:
      printf("Saindo...");
      return 0;
      break;

    default:
      printf("Escolha invalida! Tecle enter para voltar ao menu.\n");
    }
    printf("\nTecle Enter para continuar...\n");
    getch();
  }

  return 0;
}

/*
Descrição: recebe 3 numeros e 2 ponteiros para retornar o maior e menor valor recebido.
Entradas: 3 float e 2 ponteiros apontanto para float
Saída: Não possui saida, valor alterado por referencia
*/
void maiorEMenor(float n1, float n2, float n3, float *min, float *max)
{
  *max = n1;
  *min = n1;
  // maior elemento
  if (n1 > n2)
  {
    *max = n1;
  }
  else
  {
    *max = n2;
  }
  if (n3 > *max)
  {
    *max = n3;
  }

  // menor elemento
  if (n1 < n2)
  {
    *min = n1;
  }
  else
  {
    *min = n1;
  }
  if (n3 < *min)
  {
    *min = n3;
  }
}

/*
Descrição: recebe 3 numeros e 1 ponteiro para retornar a media
Entradas: 3 float e 1 ponteiros apontanto para float
Saída: Não possui saida, valor alterado por referencia
*/
void media3(float n1, float n2, float n3, float *media)
{
  *media = (n1 + n2 + n3) / 3;
}

/*
Descrição: recebe 2 valores booleanos (int 0 e 1) e 1 ponteiro para retornanr a operação ⌐ (A ^ B).
Entradas: 2 valores inteiros e um endereço de memoria
Saída: Não possui saida, valor alterado por referencia
*/
void nand(int n1, int n2, int *result)
{
  if (!(n1 && n2))
  {
    *result = 1;
  }
  else
  {
    *result = 0;
  }
}

/*
Descrição: recebe 5 valores inteiros e desloca seus valores de forma circular para esquerda.
Entradas: 5 endereços de memoria
Saída: Não possui saida, valor alterado por referencia
*/
void deslocaEsquerda(int *a, int *b, int *c, int *d, int *e)
{
  int antigoA = *a, antigoB = *b, antigoC = *c, antigoD = *d, antigoE = *e;
  *a = antigoE;
  *b = antigoA;
  *c = antigoB;
  *d = antigoC;
  *e = antigoD;

  printf("NOME_VARIAVEL | ENDERECO  | VALOR ANTIGO | VALOR  NOVO\n");
  printf("    a         | %p  |       %i      |     %i\n", a, antigoA, *a);
  printf("    b         | %p  |       %i      |     %i\n", b, antigoB, *b);
  printf("    c         | %p  |       %i      |     %i\n", c, antigoC, *c);
  printf("    d         | %p  |       %i      |     %i\n", d, antigoD, *d);
  printf("    e         | %p  |       %i      |     %i\n", e, antigoE, *e);
}

/*
Descrição: Printar endereço de memoria de cada tipo de variavel e mostrar quantos bytes cada um ocupa.
Entradas: Não possui entrada
Saída: Não possui saida, valor alterado por referencia
*/

void descreveVariaveis()
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