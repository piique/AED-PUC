#include <stdio.h>
#include <math.h>

/*
    Construa um algoritmo que leia dois pontos cartesianos (x1, y1, x2, y2) e calcule e mostre a
    distância entre esses dois pontos.

    Obs: formula = raiz((delta X)² + (delta Y)² )
*/

int main() {

    
    float x1, y1, x2, y2;
    
    printf("Digite a primeira coordenada (x, y): ");
    scanf("%f %f", &x1, &y1);

    printf("Digite a segunda coordenada (x, y): ");
    scanf("%f %f", &x2, &y2);

    printf("A distancia entre os pontos e: %f", pow( pow(x2-x1, 2) + pow(y1-y2, 2) ,0.5) );

    return 0;
    
}
