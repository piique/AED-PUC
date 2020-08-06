#include <stdio.h>
int main()
{

    float km_inicial, km_final, litros;

    printf("Digite a quilometragem inicial e final do carro\nKM Inicial: ");
    scanf("%f", &km_inicial);

    printf("KM Final: ");
    scanf("%f", &km_final);

    printf("Litros gastos no percurso: ");
    scanf("%f", &litros);

    printf("A media de consumo do carro foi de %0.2f: ", (km_final - km_inicial) / litros);

    return 0;
}
