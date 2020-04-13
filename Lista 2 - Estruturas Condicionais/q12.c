#include <stdio.h>
#include <math.h>

/*
    Sabe-se que um cliente pode obter descontos ao comparar parafusos em uma loja. O preço de
    cada parafuso é R$ 0,50, e os seguintes descontos podem ser aplicados:
                    
                    Quantidades de Parafusos Desconto
                    Entre 101 e 200 10%
                    Entre 201 e 300 20%
                    Entre 301 e 400 30%
                    Acima de 401 40% (desconto máximo)
                    
    Construa um algoritmo que recebe o número de parafusos desejados pelo cliente e
    informados pelo usuário e determina o valor total da compra. Caso a quantidade seja menor
    ou igual a zero, o sistema deverá mostrar uma mensagem informando que a quantidade é
    inválida.
*/

int main() {

    int qtd_parafuso;
    float valor, desconto;
    
    printf("Quantidade de parafusos: ");
    scanf("%i", &qtd_parafuso);

    valor = qtd_parafuso * 0.5; // cada parafuso tem o valor de R$0,50

    if(qtd_parafuso < 0){
        printf("Valor invalido");
    } else if(qtd_parafuso <= 100){
        printf("Nao possui desconto. Valor total: %0.2f", valor);
    }else if(qtd_parafuso <= 200){
        printf("Possui desconto de 10 porcento. Valor total: %0.2f", valor*0.90);
    }else if(qtd_parafuso <= 300){
        printf("Possui desconto de 20 porcento. Valor total: %0.2f", valor*0.80);
    }else if(qtd_parafuso <= 400){
        printf("Possui desconto de 30 porcento. Valor total: %0.2f", valor*0.70);
    }else {
        printf("Possui desconto de 40 porcento. Valor total: %0.2f", valor*0.60);
    }

    return 0;
    
}
