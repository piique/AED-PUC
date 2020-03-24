#include <stdio.h>

/*
    Faça um algoritmo que imprima um triangulo alinhado a direta, com n linhas, sendo n um
    número inteiro informado pelo usuário. No exemplo a seguir n = 5
*/

int main() {
    
    int num;

    printf("Digite um numero: ");
    scanf("%i", &num);

    for(int i = 1; i <= num; i++){
         for(int aux = 1; aux <= i; aux++){
             printf("*");
         }
        printf("\n");
    }

    return 0;

}