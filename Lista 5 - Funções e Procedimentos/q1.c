#include <stdio.h>
// Crie uma função que recebe três números e retorne o elemento do meio.

/*
Descrição: função que recebe 3 números e retorna o do meio
Entradas: 3 valores float
Saída: um valor float
*/
float returnMiddleElement(float n1, float n2, float n3) {
  return n2;
}


int main() {
  
  float numero1 = 2.0,
        numero2 = 3.0,
        numero3 = 4.0;

  printf("\nNumero do meio: %0.2f\n\n", returnMiddleElement(numero1, numero2, numero3));

  return 0;
}