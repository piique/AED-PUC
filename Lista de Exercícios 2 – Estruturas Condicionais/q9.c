#include <stdio.h>

/*
    Calculadora com as quatro operações aritméticas básicas. Oferecer um menu ao usuário com
    as operações. Ler os dois operandos. Calcular e escrever o resultado.

    Retirado menu para realizar as operações diretamente.
*/

int main() {
    
    float num1, num2;
    char operador;

    printf("Digite a expressao: ");
    scanf("%f %c %f", &num1, &operador, &num2);

    switch (operador){
        case '+': 
            printf("\n Resultado: %0.2f", num1+num2);
            break;
        case '-': 
            printf("\n Resultado: %0.2f", num1-num2);
            break;
        case '*': 
            printf("\n Resultado: %0.2f", num1 * num2);
            break;
        case '/': 
            printf("\n Resultado: %0.2f", num1/num2);
            break;
    }
    
    return 0;

}
