#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info_agencia
{
    char nome[30];
    float lat, longi;
    int tempo_s;
};

int main()
{
    int n = 2;
    printf("Digite a quantidade de agencias: ");
    scanf("%i", &n);
    struct info_agencia agencias[n];
    struct info_agencia agencia_paulo;

    printf("Digite o nome: ");
    scanf("%s", agencias[1].nome);
    fflush(stdin);

    // strcpy(nome, "pedro");
    // strcpy(agencia_pedro.nome, "alguma coisa");

    printf("Nome da agencia do pedro: %s", agencias[n - 1].nome);

    return 0;
}
