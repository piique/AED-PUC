#include <stdio.h>

struct Aluno {
  char nome[30];
  int idade;
};

int main() {
  FILE* fp;
  char texto[100];
  struct Aluno alunos[3];
  fp = fopen("arquivo.txt", "w");

  for (int i = 0; i < 3; i++) {
    printf("Aluno 1\n");
    printf("Nome: ");
    scanf("%s", alunos[i].nome);
    printf("Idade: ");
    scanf("%i", &alunos[i].idade);

    fprintf(fp, "%s - %i\n", alunos[i].nome, alunos[i].idade);
  }

  fclose(fp);
  return 0;
}
