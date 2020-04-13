#include <stdio.h>
/*
    Construa um algoritmo que, a partir do peso e altura informados pelo usuário, calcule e
    apresente o IMC de uma pessoa e a sua classificação.
*/

int main() 
{
    float altura, peso, imc;
    
    printf("Digite a altura e o peso: ");
    scanf("%f %f", &altura, &peso);
    imc = peso/(altura*altura);
    printf("O valor do IMC e: %0.2f\n", imc);

    if(imc < 18.5){
        printf("Classificacao: abaixo do peso");
    }else {
        if(imc >= 18.6 && imc <= 24.9){
            printf("Classificacao: peso ideal, parabens!");
        }else {
            if(imc >= 25.0 && imc <= 29.9){
                printf("Classificacao: Levemente acima do peso");
            }else {
                if(imc >= 30 && imc < 40){
                    printf("Classificacao: Obesidade grau I");
                }else {
                    if(imc > 40){
                        printf("Classificacao: Obesidade grau II (severa)");
                    }else {
                        printf("Classificacao: Obesidade III (morbida)");
                    }
                }
            }
        }
    }

    return 0;
}