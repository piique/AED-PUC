#include <stdio.h>

struct Aluno {
  char nome[30];
  int idade;
};

int main() {
  FILE* fp;
  char texto[100];
  struct Aluno alunos[3];
  fp = fopen("arquivo.txt", "r");

  for (int i = 0; i < 3; i++) {
    fscanf(fp, "%s - %i\n", alunos[i].nome, &alunos[i].idade);
  }

  for (int i = 0; i < 3; i++) {
    printf("-----------------------\n");
    printf("Aluno %i\n", i + 1);
    printf("Idade: %i\n", alunos[i].idade);
    printf("Nome: %s\n", alunos[i].nome);
    // printf("-----------------------\n");
  }

  fclose(fp);
  return 0;
}
