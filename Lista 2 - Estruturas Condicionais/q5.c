#include <stdio.h>
#include <stdlib.h>
/*
    Crie um programa que leia um caracter (tipo char) e mostre se:
    - É uma letra do alfabeto maiúscula
    - É uma letra do alfabeto minúscula
    - É um número inteiro entre 0 e 9.
    - Caracter diferente das opções anteriores.
*/

int main()
{ 

    char letra;
    int int_letra;

    printf("Digite um caractere para analise: ");
    scanf("%c", &letra);

    int_letra = letra;

    // numeros baseados na tabela ASCII
    if (int_letra >= 65 && int_letra<=90){
        printf("Letra maiuscula.");
    } else if (int_letra >= 97 && int_letra<= 122) {
        printf("Letra minuscula.");
    } else if (int_letra >= 48 && int_letra<= 57) {
        printf("Digito numerico.");
    } else {
        printf("Nao se enquadra em nenhuma descricao.");
    }

    return 0;
}
