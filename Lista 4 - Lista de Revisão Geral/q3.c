#include <stdio.h>

int main()
{

  int i, num, count = 0, posicao;
  printf("\nDigite um numero inteiro positivo: ");
  scanf("%i", &i);
  num = i;

  if (i < 0)
  {
    printf("Valor invalido");
    return 0;
  }

  // conta quantos caractes possui o inteiro e salva em count
  while (i >= 1 || i <= -1)
  {
    i = i / 10;
    count++;
  }

  printf("\nDigite uma posicao de 1 ate %i: ", count);
  scanf("%i", &posicao);

  // testa se a posição existe no inteiro informado anteriormente
  if (posicao > 0 && posicao <= count)
  {

    // utilizando while
    // percorre o inteiro de traz pra frente
    while (count > 0)
    {

      // quando encontra a posicao, imprime o digito da mesma
      if (count == posicao)
      {
        printf("O digito na posicao %i e: %i", posicao, num % 10);
        count = 0;
      }
      else
      {
        num = num / 10;
        count--;
      }
    }

    // utilizando for
    /*
    for( ; count > 0; count--){
      if(count == posicao){
        printf("O digito na posicao %i e: %i", posicao, num%10);
        count = 0;
      }else {
        num = num/10;
      }
    }
    */
  }
  else
  {
    printf("\nValor invalido!");
  }

  return 0;
}