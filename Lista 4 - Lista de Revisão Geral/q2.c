#include <stdio.h>

void main(){

  int i;
  printf("Digite um numero inteiro para ser invertido: ");
  scanf("%i", &i);

  while ( i >= 1 || i <= -1 ){
    printf("%d", i%10);
    i = i/10;
  }

}