#include <stdio.h>
int main() {

    float graus;
    printf("Digite os graus Celsius para serem convertidos em Farenheit: ");
    scanf("%f", &graus);

    printf("Valor convertido: %0.2f", (graus* (9.0/5.0) ) + 32 );
    
    return 0;

}
