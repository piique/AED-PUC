#include <stdio.h>

/*
    Crie um algoritmo que leia um número real (float) e mostre sua parte inteira e sua parte
    fracionária.
*/

int main() {

    float num;
    
    printf("Digite um numero: ");
    scanf("%f", &num);

    printf("Parte inteira: %i\n", (int) num );
    printf("Parte fracionaria: %f\n", num - (int) num );
    return 0;
    
}
