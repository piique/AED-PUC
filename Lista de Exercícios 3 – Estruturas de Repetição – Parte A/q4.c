#include <stdio.h>
/*
    Crie uma nova versão para o programa anterior, de forma que o limite inferior e limite
    superior sejam valores lidos. Utilize a estrutura de repetição FOR.

*/
int main()
{

    int num_max, num_min, soma = 0;

    printf("Digite o limite maximo e minimo respectivamente: ");
    scanf("%i %i", &num_max, &num_min);
    
    // i - index
    for( ; num_max >= num_min ; num_max--){
        soma += num_max;
        printf("%i\n", num_max);
    }

    printf("Soma total: %i", soma);

    return 0;

}
