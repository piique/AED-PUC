#include <stdio.h>
/*
    Algoritimo verificador de paridade de numeros
*/
int main()
{

    int num;

    printf("Digite um numero inteiro positivo: ");
    scanf("%i", &num);

    // verifica se numero e par
    if (num > 0) {
        if (num % 2 == 0)
        {
            printf("Numero par");
        }
        else
        {
            printf("Numero impar");
        }
    }
    else {
        printf("Numero invalido");
    }

    return 0;
}
