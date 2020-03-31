#include <stdio.h>
int main() 
{
    float largura, comprimento, area;

    //primeiro comodo
    printf("Digite a largura e o comprimento do primeiro comodo: ");
    scanf("%f %f", &largura, &comprimento);
    area = largura * comprimento;
    printf("\nArea do primeiro comodo: %0.2f\n", area);

    //segundo comodo 
    printf("\nDigite a largura e o comprimento do segundo comodo: ");
    scanf("%f %f", &largura, &comprimento);
    area += largura * comprimento;
    printf("\nArea do segundo comodo: %0.2f\n", largura*comprimento);

    //terceiro comodo 
    printf("\nDigite a largura e o comprimento do terceiro comodo: ");
    scanf("%f %f", &largura, &comprimento);
    area += largura * comprimento;
    printf("\nArea do segundo comodo: %0.2f\n", largura*comprimento);

    //area total
    printf("\nArea total dos 3 comodos: %0.2f", area);

    return 0;
}