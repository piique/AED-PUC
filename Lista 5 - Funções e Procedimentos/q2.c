#include <stdio.h>
/*
  Crie uma função que recebe 10 números como parâmetro de entrada, calcule e retorne e a
  média dos números.
*/

/*
Descrição: função que recebe 10 números e retorna a media
Entradas: 10 valores float
Saída: um valor float
*/
float media(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9, float n10){
  return (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10)/ 10;
}

void main(){

  float numero1 = 20.0,
        numero2 = 20.0,
        numero3 = 20.0,
        numero4 = 20.0,
        numero5 = 20.0,
        numero6 = 10.0,
        numero7 = 10.0,
        numero8 = 10.0,
        numero9 = 10.0,
        numero10 = 10.0;
  printf("\nMedia dos 10 numeros: %0.2f\n\n", media(numero1, numero2, numero3, numero4, numero5, numero6, numero7, numero8, numero9, numero10));

  return 0;

}