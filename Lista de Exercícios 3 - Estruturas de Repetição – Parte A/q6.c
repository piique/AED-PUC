#include <stdio.h>

/*
    Faça um algoritmo que a tabulada relativa ao número 9 e seus multiplicando de 0 a 100.
    Exemplo:
    9 x 0 = 0
    9 x 1 = 9
    9 x 2 = 18
    ...
    9 x 100 = 900
*/

int main() {

    // num: numero da tabuada, i: index para multiplicar com o num
    int num = 9, i=0;

    // Utilizando for 
    for (i = 0; i<= 100; i++){
        printf("%i x %i = %i\n", num, i, num*i);
    }

    // Utilizando while
    // while (i<=100){
    //     printf("%i x %i = %i\n", num, i, num*i);
    //     i++;
    // }

    return 0;

}
