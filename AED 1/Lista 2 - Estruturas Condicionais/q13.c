#include <stdio.h>
#include <math.h>

/*
    Acrescente no programa desenvolvido anteriormente a possibilidade do usuário digitar a
    forma de pagamento. O usuário digita um código (1 a 4) e o sistema mostra a opção de
    pagamento correspondente a esse código e aplica mais um desconto ao valor final da compra,
    como segue:
              Código  Forma de Pagamento      Desconto
                1        Dinheiro                5%
                2        Cartão Débito           3%
                3        Cartão Crédito          0%
                4        Boleto                  2%
    Utilize a estrutura de controle de fluxo switch-case

*/

int main() {

    int qtd_parafuso, forma_pagamento;
    float valor;
    
    printf("Quantidade de parafusos: ");
    scanf("%i", &qtd_parafuso);

    printf("Qual a forma de pagamento? \n 1 - Dinheiro\n 2 - Cartao Debito\n 3 - Cartao Credito\n 4 - Boleto\n Opcao: ");
    scanf("%i", &forma_pagamento);

    valor = qtd_parafuso * 0.5; // cada parafuso tem o valor de R$0,50

    if(qtd_parafuso < 0){
        printf("Valor invalido");
        return 0;
    } else if(qtd_parafuso > 100 && qtd_parafuso <= 200){
        valor = valor*0.90;
        // printf("Possui desconto de 10 porcento. Valor total: %0.2f", valor);
    }else if(qtd_parafuso <= 300){
        valor = valor*0.80;
        // printf("Possui desconto de 20 porcento. Valor total: %0.2f", valor);
    }else if(qtd_parafuso <= 400){
        valor = valor*0.70;
        // printf("Possui desconto de 30 porcento. Valor total: %0.2f", valor);
    }else {
        valor = valor*0.60;
        // printf("Possui desconto de 40 porcento. Valor total: %0.2f", valor);
    }


    switch (forma_pagamento){
        case 1:
            printf("Valor total da compra: %f", valor*95);
            break;
        case 2:
            printf("Valor total da compra: %f", valor*0.97);
            break;
        case 3:
            printf("Valor total da compra: %f", valor);
            break;
        case 4:
            printf("Valor total da compra: %f", valor*0.98);
            break;
    }

    return 0;
    
}
