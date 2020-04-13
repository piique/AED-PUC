#include <stdio.h>

/*
    Calculadora com as quatro operações aritméticas básicas. Oferecer um menu ao usuário com
    as operações. Ler os dois operandos. Calcular e escrever o resultado.
*/

int main() {
    
    float num1, num2;
    int operador;

    printf("Escolha uma das opcoes abaixo\n 1 - Soma\n 2 - Subtracao\n 3 - Multiplicacao\n 4 - Divisao \nOpcao: ");
    scanf("%i", &operador);

    printf("Digite os dois numeros para realizar a operacao: ");
    scanf("%f %f", &num1, &num2);

    switch (operador){
        case 1: 
            printf("\n Resultado: %0.2f", num1+num2);
            break;
        case 2: 
            printf("\n Resultado: %0.2f", num1-num2);
            break;
        case 3: 
            printf("\n Resultado: %0.2f", num1 * num2);
            break;
        case 4: 
            printf("\n Resultado: %0.2f", num1/num2);
            break;
    }
    
    return 0;

}
