#include <stdio.h>
/*
    Faça um programa que leia um ponto cartesiano (dois valores numéricos X e Y)
    e mostre em qual quadrante o ponto se encontra.
*/
int main() {
    
    float x, y;

    printf("Digite os valores das coordenadas\n X: ");
    scanf("%f", &x);
    fflush(stdin);

    printf("Y: ");
    scanf("%f", &y);
    
    if (x > 0) {
        if(y > 0){
            printf("Quadrante 1");
        } else {
            printf("Quadrante 4");
        }
    } else {
        if (y > 0){
            printf("Quadrante 2");
        } else{
            printf("Quadrante 3");
        }
    }
    
    return 0;

}
