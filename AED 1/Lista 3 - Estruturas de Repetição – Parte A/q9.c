#include <stdio.h>

/*
    Faça um algoritmo que imprima um triangulo alinhado a direta, com n linhas, sendo n um
    número inteiro informado pelo usuário. No exemplo a seguir n = 5
*/

int main() {
    
    int num, i, aux, sum = 1;

    printf("Digite um numero: ");
    scanf("%i", &num);

    // quantidade de linhas, cada rodada do for passa por uma linha
    for(i = 1; i <= num; i++){
        
        for(aux = 1; aux <= i; aux++){
            printf("%i ", sum++);
        }

        printf("\n");
    }

    return 0;

}