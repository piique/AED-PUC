#include <stdio.h>
int main() {

    float capital_inicial, juros, capital_total;
    int meses;

    printf("Digite o capital inicial, a taxa de juros ao mes e a quantidade de meses: ");
    scanf("%f %f %i", &capital_inicial, &juros, &meses);

    juros = juros/100;
    capital_total = capital_inicial;

    for(int i = 0; i <= meses; i++) {
        capital_total += juros*capital_total;
    }

    printf("\nO valor total acumulado e : %0.2f\nO valor total de juros e: %0.2f", capital_total, capital_total-capital_inicial);

    return 0;
    
}