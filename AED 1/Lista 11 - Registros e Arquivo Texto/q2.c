#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#define PAUSE 1
#else
#define PAUSE 0
#endif

struct Aluno {
  int matricula;
  char nome[50];
  int idade;
  char telefone[30];
  float renda;
  float nota;
};

void systemPause();
void systemClear();
struct Aluno alunoMaiorNota(struct Aluno alunos[], int n);
float mediaNota(struct Aluno alunos[], int n);
float mediaRenda(struct Aluno alunos[], int n);
void preencheAluno(struct Aluno alunos[], int n);
void printaTodosAlunos(struct Aluno alunos[], int n);
void printaAluno(struct Aluno aluno);
void procuraAlunoMatricula(struct Aluno alunos[], int n, int matricula);
void salvaAlunosEmArquivo(struct Aluno alunos[], int n);
void buscaAlunosEmArquivo(struct Aluno alunos[], int n, char nome_arquivo[]);
void linhasArquivo(int* n, char nome_arquivo[]);

int main() {
  // quantidade de alunos
  int n, opcMenu = -1, opc = -1;
  int matricula;  // usada para buscar aluno por matricula
  char nome_arquivo[50];

  // vetor de Aluno com n posições
  while (opc != 1 && opc != 2) {
    printf("Deseja cadastrar alunos ou buscar em backup(arquivo)?\n");
    printf("1 - Cadastrar alunos\n");
    printf("2 - Buscar alunos em arquivo\n");
    scanf("%i", &opc);
  }
  if (opc == 1) {
    printf("Digite a quantidade de alunos: ");
    scanf("%i", &n);
  } else if (opc == 2) {
    linhasArquivo(&n, &nome_arquivo);
  }

  struct Aluno alunos[n];

  if (opc == 1) {
    preencheAluno(alunos, n);
  } else if (opc == 2) {
    buscaAlunosEmArquivo(alunos, n, nome_arquivo);
  }

  while (opcMenu != 0) {
    systemClear();
    printf("-------------- MENU --------------");
    printf("\nEscolha uma das questões:  ");
    printf("\n 1 - Mostrar todos os Alunos");
    printf("\n 2 - Mostrar aluno por matricula");
    printf("\n 3 - Mostrar renda media");
    printf("\n 4 - Mostrar nota media");
    printf("\n 5 - Mostrar aluno com maior nota");
    printf("\n 6 - Salvar alunos em arquivo");
    printf("\n 7 - Buscar alunos de arquivo");
    printf("\n 0 - Sair");
    printf("\n\nOpc: ");
    scanf("%i", &opcMenu);

    switch (opcMenu) {
      case 1:
        printaTodosAlunos(alunos, n);
        break;

      case 2:
        printf("Digite a matricula: ");
        scanf(" %i", &matricula);
        procuraAlunoMatricula(alunos, n, matricula);
        break;

      case 3:
        printf("Media das rendas dos alunos: %0.2f\n", mediaRenda(alunos, n));
        break;

      case 4:
        printf("Media das notas dos alunos: %0.2f\n", mediaNota(alunos, n));
        break;

      case 5:
        printf("Aluno com maior nota: \n");
        printaAluno(alunoMaiorNota(alunos, n));
        break;

      case 6:
        salvaAlunosEmArquivo(alunos, n);
        break;

      case 7:
        printf("Digite o nome do arquivo: ");
        scanf(" %s", nome_arquivo);
        fflush(stdin);
        buscaAlunosEmArquivo(alunos, n, nome_arquivo);
        break;

      case 0:
        printf("Saindo...\n\n");
        systemClear();
        return 0;
        break;

      default:
        printf("Escolha invalida! Precione enter para voltar ao menu.\n");
    }
    systemPause();
  }

  return 0;
}

/*
Descrição: pausa o sistema pedindo para pressione enter para continuar
Entradas: void
Saída: void
*/
void systemPause() {
  if (PAUSE == 1) {
    printf("Pressione enter para continuar");
    system("pause");
  } else {
    system("read -p 'Precione enter para continuar' continuar");
  }
}

/*
Descrição: limpa console
Entradas: void
Saída: void
*/
void systemClear() {
  if (PAUSE == 1) {
    system("cls");
  } else {
    system("clear");
  }
}

/*
Descrição: recebe vetor de alunos e seu tamanho e busca e retorna o aluno de maior nota
Entradas: vetor de struct Aluno e seu tamanho em inteiro
Saída: struct Aluno com aluno de maior nota
*/
struct Aluno alunoMaiorNota(struct Aluno alunos[], int n) {
  float maiorNota = alunos[n - 1].nota;
  int alunoMaiorNota = n - 1;

  for (int i = 0; i < n; i++) {
    if (alunos[i].nota > maiorNota) {
      alunoMaiorNota = i;
      maiorNota = alunos[i].nota;
    }
  }

  return alunos[alunoMaiorNota];
}

/*
Descrição: retorna media das notas dos alunos
Entradas: vetor de struct Aluno e seu tamanho em inteiro
Saída: float com a media das notas
*/
float mediaNota(struct Aluno alunos[], int n) {
  float media, soma = 0;
  for (int i = 0; i < n; i++) {
    soma += alunos[i].nota;
  }
  media = soma / n;
  return media;
}

/*
Descrição: retorna a renda media dos alunos
Entradas: vetor de struct Aluno e seu tamanho em inteiro
Saída: float com a media da renda
*/
float mediaRenda(struct Aluno alunos[], int n) {
  float media, soma = 0;
  for (int i = 0; i < n; i++) {
    soma += alunos[i].renda;
  }
  media = soma / n;
  return media;
}

/*
Descrição: preenche o vetor do tipo Aluno com inputs do usuario
Entradas: vetor de struct Aluno e seu tamanho em inteiro
Saída: altera por referencia o vetor de Alunos preenchidos
*/
void preencheAluno(struct Aluno alunos[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Preencha os dados do aluno %i \n", i + 1);
    printf("Digite a matricula: ");
    scanf(" %i", &alunos[i].matricula);
    printf("Digite o nome: ");
    scanf(" %[^\n]s", alunos[i].nome);
    fflush(stdin);
    printf("Digite a idade: ");
    scanf(" %i", &alunos[i].idade);
    printf("Digite o telefone: ");
    scanf(" %[^\n]s", alunos[i].telefone);
    fflush(stdin);
    printf("Digite a renda: ");
    scanf(" %f", &alunos[i].renda);
    fflush(stdin);
    printf("Digite a nota: ");
    scanf(" %f", &alunos[i].nota);
    fflush(stdin);
    printf("\n");
  }
}

/*
Descrição: printa todos os alunos do vetor de Aluno
Entradas: vetor de struct Aluno e seu tamanho em inteiro
Saída: printa os alunos na tela
*/
void printaTodosAlunos(struct Aluno alunos[], int n) {
  printf("\nPrintando alunos: \n");
  for (int i = 0; i < n; i++) {
    printf("----------- Aluno %i --------------\n", i + 1);
    printf("Matricula: %i\n", alunos[i].matricula);
    printf("Nome: %s\n", alunos[i].nome);
    printf("Idade: %i\n", alunos[i].idade);
    printf("Telefone: %s\n", alunos[i].telefone);
    printf("Renda: %0.2f\n", alunos[i].renda);
    printf("Nota: %0.2f\n", alunos[i].nota);
    printf("-----------------------------------\n");
  }
}

/*
Descrição: recebe e printa um Aluno
Entradas: struct Aluno
Saída: printa as informações do aluno recebido na tela
*/
void printaAluno(struct Aluno aluno) {
  printf("------------ Aluno ------------\n");
  printf("Matricula: %i\n", aluno.matricula);
  printf("Nome: %s\n", aluno.nome);
  printf("Idade: %i\n", aluno.idade);
  printf("Telefone: %s\n", aluno.telefone);
  printf("Renda: %0.2f\n", aluno.renda);
  printf("Nota: %0.2f\n", aluno.nota);
  printf("-------------------------------\n");
}

/*
Descrição: busca por um aluno atraves da matricula no vetor de Aluno 
Entradas: vetor de struct Aluno, seu tamanho em inteiro e o numero da matricula em inteiro
Saída: printa o primeiro aluno encontrado que possui a mesma matricula passada
*/
void procuraAlunoMatricula(struct Aluno alunos[], int n, int matricula) {
  for (int i = 0; i < n; i++) {
    if (alunos[i].matricula == matricula) {
      printaAluno(alunos[i]);
      return;
    }
  }
}

/*
Descrição: recebe vetor de struct Aluno e salva os alunos em um arquivo
Entradas: vetor de struct Aluno e seu tamanho em inteiro
Saída: printa os alunos no arquivo
*/
void salvaAlunosEmArquivo(struct Aluno alunos[], int n) {
  FILE* fp;
  char nome_arquivo[50];
  printf("Digite o nome do arquivo: ");
  scanf(" %s", nome_arquivo);

  fp = fopen(nome_arquivo, "w");

  if (fp != NULL) {
    for (int i = 0; i < n; i++) {
      fprintf(fp, "Matricula: %i", alunos[i].matricula);
      fprintf(fp, "\tNome: %s", alunos[i].nome);
      fprintf(fp, "\tIdade: %i", alunos[i].idade);
      fprintf(fp, "\tTelefone: %s", alunos[i].telefone);
      fprintf(fp, "\tRenda: %f", alunos[i].renda);
      fprintf(fp, "\tNota: %f\n", alunos[i].nota);
    }

  } else {
    printf("\nErro ao abrir arquivo!\n");
    return;
  }
  fclose(fp);
  printf("\nAlunos salvos no arquivo %s\n", nome_arquivo);
}

/*
Descrição: busca todos os alunos do arquivo e salva eles no vetor de Aluno
Entradas: vetor de struct Aluno, seu tamanho em inteiro e o nome do arquivo a ser buscado
Saída: printa na tela mensagem de erro ou de sucesso
*/
void buscaAlunosEmArquivo(struct Aluno alunos[], int n, char nome_arquivo[]) {
  FILE* fp;

  fp = fopen(nome_arquivo, "r");

  if (fp != NULL) {
    for (int i = 0; i < n; i++) {
      fscanf(fp, "Matricula: %i", &alunos[i].matricula);
      fscanf(fp, "\tNome: %s", &alunos[i].nome);
      fscanf(fp, "\tIdade: %i", &alunos[i].idade);
      fscanf(fp, "\tTelefone: %s", &alunos[i].telefone);
      fscanf(fp, "\tRenda: %f", &alunos[i].renda);
      fscanf(fp, "\tNota: %f\n", &alunos[i].nota);
    }

  } else {
    printf("\nErro ao abrir arquivo!\n");
    return;
  }
  fclose(fp);
  printf("\nAlunos salvos no arquivo %s\n", nome_arquivo);
}

/*
Descrição: busca a quantidade de linhas de um determinado arquivo
Entradas: ponteiro de inteiro e nome de arquivo char
Saída: salva a quantidade de linhas do arquivo em n através de referencia
*/
void linhasArquivo(int* n, char nome_arquivo[]) {
  FILE* arq;
  char c, letra = '\n';
  int linhas = 0;

  printf("Digite o nome do arquivo: ");
  scanf(" %s", nome_arquivo);
  fflush(stdin);

  arq = fopen("teste.txt", "r");
  //Lendo o arquivo 1 por 1
  while (fread(&c, sizeof(char), 1, arq)) {
    if (c == letra) {
      linhas++;
    }
  }
  fclose(arq);
  // printf("\nLinhas: %i\n", linhas);
  *n = linhas;
}
