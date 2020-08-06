#include <stdio.h>
/*
    Construa um programa que escreva na tela do monitor de vídeo os números inteiros de dez
    até um (ordem decrescente). Utilize estrutura de repetição com teste no início (while). Mostre
    o valor da soma dos números.
*/
int main()
{

    int num = 10, soma = 0;

    while(num > 0) {
        soma += num;
        printf("%i\n", num--);
    }

    printf("Soma total: %i", soma);

    return 0;
}
