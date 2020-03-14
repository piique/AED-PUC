#include <stdio.h>
int main() {
    
    float salario, aumento;

    printf("Digite o salário atual e o percentual de reajuste: ");
    scanf("%f %f", &salario, &aumento);
    
    printf("\nO novo salario do funcionario e: %0.2f\n", salario + (salario * aumento/100));
    
    return 0;

}
