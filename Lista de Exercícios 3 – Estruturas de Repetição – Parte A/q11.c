#include <stdio.h>
#include <math.h>

/*
    . Faça um algoritmo que encontre o menor número inteiro e positivo N que satisfaça,
    simultaneamente, às relações:
    • Resto da divisão de N por 3 = 2
    • Resto da divisão de N por 5 = 3
    • Resto da divisão de N por 7 = 4
*/

int main() {

    int i = 0;

    while (i != -1) {
        if(i%3 == 2 && i%5 == 3 && i%7==4){
            printf("Numero que atende as condicoes e: %i", i);
            i = -2;
        }
        
        i++;
    }
    
    return 0;
}
