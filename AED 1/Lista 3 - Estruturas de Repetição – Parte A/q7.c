#include <stdio.h>
/*
    Calcular e escrever a idade média de uma turma de n alunos, sendo n um valor lido.
*/

int main() 
{
    
    int qtd_alunos, idade, idade_total = 0;

    printf("Quantidade de alunos na sala: ");
    scanf("%i", &qtd_alunos);
    if(qtd_alunos < 0)
        return 0;

    for (int i = 0; i < qtd_alunos; i++){
        printf("Idade do aluno %i: ", i + 1);
        scanf("%i", &idade);
        idade_total += idade;
    }
    
    printf("Media de idade da turma e: %f", idade_total/(float)qtd_alunos);

    return 0;
}