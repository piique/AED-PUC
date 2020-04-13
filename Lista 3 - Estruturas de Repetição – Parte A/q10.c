#include <stdio.h>
#include <stdlib.h> // necessário para as funções rand() e srand()
#include <time.h> //necessário para pegar tempo atual

/*
    Construa um algoritmo que gere 100 números aleatórios entre 1 e 100, mostre a soma e a
    média dos números gerados.
*/

int main()
{
    
    int soma = 0, num;
    float media;

    printf("\nGerando 10 valores aleatorios entre 0 e 100: ");
    
    // seta o valor de inicio da rand com a quantidade de segundos da data de 1 de janeiro de 1970 até a data atual do sistema.
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        // ao dividir um numero por 101 e pegar seu resto, o maior resto possivel é 100
        num = rand() % 101;
        soma += num;
        printf("%d ", num);
        
    }

    printf("\n\nSoma: %i", soma);
    printf("\nMedia: %0.2f\n\n", soma/10.0);

    return 0;
}