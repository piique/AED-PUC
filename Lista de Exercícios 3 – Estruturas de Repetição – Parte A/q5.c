#include <stdio.h>

/*
    Calculadora com as quatro operações aritméticas básicas. Oferecer um menu ao usuário com
    as operações. Ler os dois operandos. Calcular e escrever o resultado.
*/

int main() {
    
    float num1, num2;
    int operador = 0;

    while (operador != 5){
        printf("\n--------MENU--------\n\n 1 - Soma\n 2 - Subtracao\n 3 - Multiplicacao\n 4 - Divisao \n 5 - Sair\n\nOpcao: ");
        scanf("%i", &operador);


        if(operador != 5){
            printf("Digite os dois numeros para realizar a operacao: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (operador){
            case 1: 
                printf("\n Soma de %f com %f = %0.2f \n\n", num1, num2, num1+num2);
                break;
            case 2: 
                printf("\n Subtracao de %f com %f = %0.2f \n\n", num1, num2, num1-num2);
                break;
            case 3: 
                printf("\n Multiplicacao de %f com %f = %0.2f \n\n", num1, num2, num1 * num2);
                break;
            case 4: 
                printf("\n Divisao de %f com %f = %0.2f \n\n", num1, num2, num1/num2);
                break;
            case 5: 
                printf("\nnSaindo...");
                break;
            default:
                printf("Opcao invalida. Tente novamente!\n");
        }

    }
    
    return 0;

}
