#include <stdio.h>
/*
    Algoritimo criado para validar senha
*/
int main()
{

    float passworld;

    printf("Digite a senha: ");
    scanf("%f", &passworld);
    while (passworld != 5555){
        printf("Senha incorreta. Tente novamente\nSenha: ");
        scanf("%f", &passworld);
        fflush(stdin);
    }

    if(passworld == 5555)
        printf("Senha correta - ACESSO LIBERADO");

    return 0;
}
