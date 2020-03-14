#include <stdio.h>
int main() {

    float altura, peso;
    
    printf("Digite a altura e o peso: ");
    scanf("%f %f", &altura, &peso);

    printf("O valor do IMC e: %0.2f", peso/(altura*altura));

    return 0;
    
}
