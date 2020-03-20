#include <stdio.h>
/*
    Crie um programa que leia o valor de 3 ângulos de um triângulo e escreva 
    se o triângulo é Acutângulo, Retângulo ou Obtusângulo
*/

int main() {

    // declaracao dos 3 angulos
    float ang1, ang2, ang3;
    
    printf("Digite os 3 angulos do triangulo: ");
    scanf("%f %f %f", &ang1, &ang2, &ang3);

    if(ang1 + ang2 + ang3 != 180){
        printf("Nao e um triangulo");
        return 0;
    }
    
    if (ang1 == 90 || ang2 == 90 || ang3 == 90){
        printf("Triangulo Retangulo");
    }else {
        if (ang1 > 90 || ang2 > 90 || ang3 > 90){
            printf("Triangulo Obtusangulo");
        }else {
            if(ang1 < 90 && ang2 < 90 && ang3 && 90) {
                printf("Triangulo Acutangulo");
            }
        }
    }

    return 0;
}
