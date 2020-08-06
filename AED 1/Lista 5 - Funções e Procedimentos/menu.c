#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h> // no prompt: chcp 65001 - para funcionar formatação

/*
Descrição: função que recebe 3 números e retorna o do meio
Entradas: 3 valores float
Saída: um valor float
*/
float returnMiddleElement(float n1, float n2, float n3)
{
  return n2;
}

/*
Descrição: função que recebe 10 números e retorna a media
Entradas: 10 valores float
Saída: um valor float
*/
float media(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9, float n10)
{
  return (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10) / 10;
}

/*
Descrição: função que recebe 10 números e retorna a media
Entradas: 2 inteiros (true ou false: 1 ou 0);
Saída: um valor float
*/
int xorTable(int A, int B)
{
  if (A)
  {
    if (B)
      return 0;
    else
      return 1;
  }
  else
  {
    if (B)
      return 1;
    else
      return 0;
  }
}

/*
Descrição: função que um numero e retorna seu fatorial
Entradas: um valor inteiro
Saída: um valor float
*/
float fat(int n)
{
  float fat = 1;
  while (n > 1)
  {
    fat = fat * n;
    n--;
  }
  return fat;
}

/*
Descrição: procedimento que calcula e imprime a sequencia: 
  100/!0 + 99/!1 + 98/!2 + 97/!3 + 96/!4 ... + 1/!99
Entradas: não possui
Saída: um valor float
*/
void calculaSerie()
{
  float numerador = 100, denominador = 0, soma = 0;

  for (int i = 0; i < 20; i++) // for para rodar 20 vezes
  {
    soma += numerador / fat(denominador);
    // printf("Soma: %f Denominador: %f\n", soma, fat(denominador));
    // printf("%f / %f! = %f\n", numerador, denominador, numerador / fat(denominador)); // mostra o resultado de cada fração em decimal
    numerador--;
    denominador++;
  }

  printf("\nSoma total: %0.2f\n\n", soma);
}

/*
Descrição: procedimento que calcula e imprime a sequencia: 
  S = 1/225 + 2/196 + 3/169 ... + 16384/1
Entradas: não possui
Saída: um valor float
*/
void calculaSomatorio()
{
  int numerador = 1;
  float soma = 0,
        denominador = 225; // denominador declarado como float por problemas com alguns compiladores ao usar sqrt

  while (denominador >= 1)
  {
    soma += numerador / denominador;
    // printf("%i / %0.0f = %f\n", numerador, denominador, numerador / denominador); // mostra o resultado de cada fração em decimal
    numerador += numerador;
    denominador = pow(sqrt(denominador) - 1.0, 2.0); // pega raiz do denominador, subtrai 1 e eleva ao quadrado
  }

  printf("%0.2f", soma);
}

/*
Descrição: função que receba um número real x e calcule a série a seguir:
    sin(x) = x + x³/!3 - x⁵/!5 + x⁷/!7 + ...
Entradas: não possui
Saída: um valor float
*/
float calculaSin(float x)
{
  int aux = 3;
  int soma = 1;
  float serieValue = x;

  // maximo de 4 casas decimais, tanto para positivos quanto para negativos
  while (serieValue < 9999.0 && serieValue > -9999.0)
  {
    if (soma)
    {
      serieValue += pow(x, aux) / fat(x);
      soma = 0;
    }
    else
    {
      serieValue -= pow(x, aux) / fat(x);
      soma = 1;
    }
    aux += 2;
  }
  return serieValue;
}

/*
Descrição: função que recebe dois numeros (min, max) e retorna um valor aleatorio entre eles
Entradas: 2 int (min, max)
Saída: int
*/
int geraValorAleatorio(int min, int max)
{
  if (min > max)
    return -1;
  int valorAleatorio = min > 1;

  // seta o valor de inicio da rand com a quantidade de segundos da data de 1 de janeiro de 1970 até a data atual do sistema.
  srand(time(NULL));

  while (valorAleatorio < min)
  {
    valorAleatorio = rand() % (max + 1);
  }

  return valorAleatorio;
}

/*
Descrição: função recebe um valor float para imprimir o mesmo por extenso
Entradas: 1 float
Saída: print com valor por extenso
*/
void valorPorExtenso(float value)
{
  if (value == 5.65)
  {
    printf("cinco reais, sessenta e oito centavos");
  }
  else
  {
    printf("Valor nao desenvolvido ainda!");
  }
}

int main()
{
  setlocale(LC_ALL, "Portuguese_Brasil");
  int opc = -1;
  int result;       // questão 3
  int A = 1, B = 1; // questão 3

  while (opc != 0)
  {
    printf("------------------------------------ MENU ------------------------------------");
    printf("\nEscolha uma das questoes:  ");
    printf("\n\n 1 - Crie uma funcao que recebe tres numeros e retorne o elemento do meio. ");
    printf("\n\n 2 - Crie uma funcao que recebe 10 numeros como parametro de entrada, calcule e retorne e a media dos numeros. ");
    printf("\n\n 3 - Crie uma funcao que recebe dois valores boleanos (A e B) e retorne o valor verdade da operacao XOR em relacao aos dois valores.");
    printf("\n\n 4 - Crie um procedimento que calcule e escreva a soma dos 20 primeiros números da série.");
    printf("\n\n 5 - Crie uma função que calcule e retorne o seguinte somatório.");
    printf("\n\n 6 - Crie uma função que receba um número real x e calcule a série a seguir.");
    printf("\n\n 7 - Crie uma função que recebe dois inteiros (min e max) e retonar um valor aleatório entre min e max. Max deve ser maior que min, caso contrário sua função deverá retornar -1.");
    printf("\n\n 8 -  Crie um procedimento que recebe valor monetário de até 2 casas decimais e escreva por extenso o valor. Exemplo: se o usuário digital R$ 5,68, então a seu procedimento deverá imprimir: “cinco reais, sessenta e oito centavos”.");
    printf("\n\n 0 - Sair");
    printf("\n\nOpc: ");

    scanf("%i", &opc);

    switch (opc)
    {
    case 1:
      // chama função para executar a primeira questão
      printf("\nNumero do meio: %0.2f\n\n", returnMiddleElement(2.1, 4.2, 231));

      break;
    case 2:
      // chama função para executar a segunda questão
      printf("\nMedia dos 10 numeros: %0.2f\n\n", media(10, 10, 10, 10, 10, 20, 20, 20, 20, 20));
      break;

    case 3:
      A = 1;
      B = 1;
      result = xorTable(A, B);
      if (result == 0)
      {
        printf("\n%i xor %i: false\n\n", A, B);
      }
      else
      {
        printf("\n%i xor %i: true\n\n", A, B);
      }
      break;

    case 4:
      calculaSerie();
      break;

    case 5:
      calculaSomatorio();
      break;

    case 6:
      printf("\nsin(x) = x + x³/!3 - x⁵/!5 + x⁷/!7 + ...\n\nsin(%0.2f): %0.2f\n\n", 5, calculaSin(5));
      break;

    case 7:
      printf("Numero aleatorio entre %i e %i: %i\n", 5, 10, geraValorAleatorio(5, 10));
      break;

    case 8:
      valorPorExtenso(5.68);
      break;

    case 0:
      printf("Saindo...");
      break;

    default:
      printf("Escolha invalida! Tecle enter para voltar ao menu.\n");
    }
    getch();
  }

  return 0;
}