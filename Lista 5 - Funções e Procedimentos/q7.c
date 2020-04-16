#include <stdio.h>
#include <math.h>
#include <time.h> //necessário para pegar tempo atual

/*
  Crie uma função que recebe dois inteiros (min e max) e retonar um valor aleatório entre min e
  max. Max deve ser maior que min, caso contrário sua função deverá retornar -1.
*/

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

int main()
{
  int min = 5, max = 10;

  printf("Numero aleatorio entre %i e %i: %i\n", min, max, geraValorAleatorio(min, max));

  return 0;
}
