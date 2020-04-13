#include <stdio.h>
/*
    Algoritimo criado para validar datas no formato DD/MM/YYYY
*/


int main() 
{
    int dia, mes, ano;
    int bissexto = 0; // 0 - não bissexto, 1 - bissexto

    printf("Digite a data no formato DD/MM/YYYY: ");
    scanf("%i/%i/%i", &dia, &mes, &ano);
    fflush(stdin);

    // valida dia
    if (dia < 0 || dia > 31) {
        printf("Dia invalido");
        return 0;
    }
    
    //valida mes
    if (mes < 0 || mes > 12) {
        printf("Mes invalido");
        return 0;
    }

    //valida ano
    if(ano < 0 && ano > 9999) {
        printf("Ano inválido");
        return 0;
    }

    // ano bissexto = 1 / ano nao bissexto = 0
    // trecho de codigo que valida se o ano é bissexto e coloca 1 em caso afirmativo
    if (ano % 400 == 0) { 
        bissexto = 1;
    } else {
        if(ano%4 == 0 && ano%100!=0) {
            bissexto = 1;
        }
    }

    // valida mes de fevereiro
    if (mes == 2 && dia > (bissexto == 1 ? 29 : 28) ){
        printf("Data invalida");
        return 0;
    } else {
        // valida meses com 30 dias (os de 31 dias ja foram validados no começo - linha 17)
        if(mes == 4 || mes == 6 || mes == 9|| mes == 11 && ( mes > 30) ){
            printf("Mes invalido");
            return 0;
        }
    }

    printf("\n Data valida");
    return 0;
}