/*
  Neste exercício você deverá criar um sistema em C++ usando Programação Orientada a
  objetos para cadastro de alunos. O sistema deverá oferecer as opções:
  
  a) Cadastrar aluno (utilize um vetor de N alunos)
  b) Lista alunos
  c) Cadastro de notas dos alunos por disciplina (utilize um vetor de M disciplinas por aluno)
  d) Exibir as notas de um aluno
  e) Mostrar o aluno com a maior nota

*/

#include <stdlib.h>  // limpar console: system("cls");
#ifdef WIN32
#define PAUSE 1
#else
#define PAUSE 0
#endif

#include <iostream>
#include <string>
using namespace std;

#define N 2  // quantidade de alunos
#define M 2  // quantidade de disciplinas

// definição das funções e classes utilizadas durante o programa
class Disciplina;
class Aluno;

void systemPause();
void systemClear();
void cadastrarAlunos(Aluno alunos[], Disciplina disciplinas[], int *alunos_cadastrados, int *disciplinas_cadastradas);
void cadastrarDisciplinas(Disciplina disciplinas[], int *disciplinas_cadastradas);
void listarAlunos(Aluno alunos[], int *alunos_cadastrados);
void cadastrarNotas(Aluno alunos[], Disciplina disciplinas[], int alunos_cadastrados, int disciplinas_cadastradas);
void exibirNotasAluno(Aluno alunos[], int alunos_cadastrados);
void alunoMaiorNota(Aluno alunos[], int alunos_cadastrados);

//  Classe Disciplina
class Disciplina {
 private:
  int codigo;
  std::string nome;
  float nota;

 public:
  // construtor
  Disciplina() {
    codigo = 0;
    nome = " ";
    nota = 0;
  }

  // construtor com sobrecarga
  Disciplina(int codigo, char nome[], float nota) {
    this->codigo = 0;
    this->nome = nome;
    this->nota = nota;
  }

  // lista o codigo e nome da disciplina
  void listar() {
    cout << "\nDisciplina " << codigo << endl;
    cout << "Nome: " << nome << endl;
  }

  // exibe a nota da disciplina
  void exibir() {
    cout << nome << " - Nota: " << nota << endl;
  }

  void setCodigo(int codigo) {
    this->codigo = codigo;
  }

  void setNome(std::string nome) {
    this->nome = nome;
  }

  void setNota(float nota) {
    this->nota = nota;
  }

  int getCodigo() {
    return codigo;
  }

  std::string getNome() {
    return nome;
  }

  float getNota() {
    return nota;
  }
};

//  Classe Aluno
class Aluno {
 private:
  int matricula;
  std::string nome;
  std::string email;
  Disciplina disciplinas[M];  // vetor de disciplinas
  int qtdDisciplinas;         // contar quantas disciplinas ja foram relacionadas ao aluno

 public:
  Aluno() {
    this->matricula = 0;
    this->nome = " ";
    this->email = " ";
    this->qtdDisciplinas = 0;
  }

  Aluno(int matricula, std::string nome, std::string email, Disciplina disciplina) {
    this->matricula = matricula;
    this->nome = nome;
    this->email = email;
    this->qtdDisciplinas = 0;
    setDisciplina(disciplina);
  }

  // lista informações do aluno
  void listar() {
    cout << "-------------------------------" << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "-------------------------------" << endl;
  }

  // exibe informações do aluno e suas disciplinas
  void exibir() {
    cout << "-------------------------------";
    cout << "\nAluno " << matricula << endl;
    cout << "Nome: " << nome << endl;
    for (int i = 0; i < qtdDisciplinas; i++) {
      disciplinas[i].exibir();
    }
    cout << "-------------------------------" << endl;
  }

  void setNota(int codigoMateria, float nota) {
    for (int i = 0; i < qtdDisciplinas; i++) {
      if (disciplinas[i].getCodigo() == codigoMateria) {
        disciplinas[i].setNota(nota);
      }
    }
  }

  void setMatricula(int matricula) {
    this->matricula = matricula;
  }

  void setNome(std::string nome) {
    this->nome = nome;
  }

  void setEmail(std::string email) {
    this->email = email;
  }

  void setDisciplina(Disciplina disciplina) {
    if (qtdDisciplinas >= M) {
      cout << "Limite maximo de disciplinas por aluno atingida";
      return;
    }
    this->disciplinas[qtdDisciplinas].setNome(disciplina.getNome());
    this->disciplinas[qtdDisciplinas].setCodigo(disciplina.getCodigo());
    this->disciplinas[qtdDisciplinas].setNome(disciplina.getNome());
    qtdDisciplinas++;
  }

  int getMatricula() {
    return matricula;
  }

  std::string getNome() {
    return nome;
  }

  std::string getEmail() {
    return email;
  }

  // retorna a nota da materia recebida como parametro (codigo)
  float getNotaMateria(int codigoMateria) {
    for (int i = 0; i < qtdDisciplinas; i++) {
      if (disciplinas[i].getCodigo() == codigoMateria) {
        return disciplinas[i].getNota();
      }
    }
  }

  // retorna a maior nota do aluno em todas as disciplinas
  float getMaiorNota() {
    float maiorNota = disciplinas[0].getNota();
    for (int i = 1; i < qtdDisciplinas; i++) {
      if (disciplinas[i].getNota() > maiorNota) {
        maiorNota = disciplinas[i].getNota();
      }
    }
    return maiorNota;
  }

  // sobrecarga do metodo anterior
  // retorna por referencia a nota, o nome da disciplina e o nome do aluno com maior nota
  void getMaiorNota(float *maiorNota, std::string *nomeDisciplina, std::string *nomeAluno) {
    *maiorNota = disciplinas[0].getNota();
    *nomeDisciplina = disciplinas[0].getNome();
    *nomeAluno = this->getNome();
    for (int i = 1; i < qtdDisciplinas; i++) {
      if (disciplinas[i].getNota() > *maiorNota) {
        *maiorNota = disciplinas[i].getNota();
        *nomeDisciplina = disciplinas[i].getNome();
        *nomeAluno = this->getNome();
      }
    }
  }
};

int main() {
  Aluno alunos[N];
  Disciplina disciplinas[M];
  int alunos_cadastrados = 0;
  int disciplinas_cadastradas = 0;

  int opc = 1;

  while (opc != 0) {
    systemClear();
    cout << "--------------Menu--------------" << endl;
    cout << "1 - Cadastrar alunos" << endl;
    cout << "2 - Cadastrar disciplina" << endl;
    cout << "3 - Listar alunos" << endl;
    cout << "4 - Cadastrar notas" << endl;
    cout << "5 - Exibir notas de um aluno" << endl;
    cout << "6 - Aluno com maior nota" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opc: ";
    cin >> opc;

    switch (opc) {
      case 1:
        cadastrarAlunos(alunos, disciplinas, &alunos_cadastrados, &disciplinas_cadastradas);
        break;
      case 2:
        cadastrarDisciplinas(disciplinas, &disciplinas_cadastradas);
        break;
      case 3:
        listarAlunos(alunos, &alunos_cadastrados);
        break;
      case 4:
        cadastrarNotas(alunos, disciplinas, alunos_cadastrados, disciplinas_cadastradas);
        break;
      case 5:
        exibirNotasAluno(alunos, alunos_cadastrados);
        break;
      case 6:
        alunoMaiorNota(alunos, alunos_cadastrados);
      case 0:
        break;
      default:
        cout << "Opção invalida!";
        systemPause();
        break;
    }
  }
  return 0;
}

// cadastra os alunos no sistema (necessario cadastrar disciplinas anteriormente). Cadastro realizado apenas uma vez
void cadastrarAlunos(Aluno alunos[], Disciplina disciplinas[], int *alunos_cadastrados, int *disciplinas_cadastradas) {
  systemClear();
  if (*alunos_cadastrados > 0) {
    cout << "Alunos ja cadastrados!" << endl;
    systemPause();
    return;
  }

  if (*disciplinas_cadastradas <= 0) {
    cout << "Cadastre as disciplinas antes de cadastrar os alunos!" << endl;
    systemPause();
    return;
  }

  std::string nomes;
  int matricula;
  for (int i = 0; i < N; i++) {
    cout << "Cadastrando Aluno " << i + 1 << endl;
    cout << "Matricula: ";
    cin >> matricula;
    alunos[i].setMatricula(matricula);
    cout << "Nome: ";
    cin >> nomes;
    alunos[i].setNome(nomes);
    cout << "Email: ";
    cin >> nomes;
    alunos[i].setEmail(nomes);
    for (int j = 0; j < *disciplinas_cadastradas; j++) {
      alunos[i].setDisciplina(disciplinas[j]);
    }
    *alunos_cadastrados += 1;
  }
}

// cadastra disciplinas no sistema (cadastro de disciplinas realizado apenas uma vez)
void cadastrarDisciplinas(Disciplina disciplinas[], int *disciplinas_cadastradas) {
  systemClear();
  if (*disciplinas_cadastradas > 0) {
    cout << "Disciplinas ja cadastradas!" << endl;
    systemPause();
    return;
  }
  std::string nome;
  int codigo;
  cout << "Cadastrando Disciplinas " << endl;
  for (int i = 0; i < N; i++) {
    cout << i + 1 << "ª Disciplina" << endl;
    cout << "Codigo: ";
    cin >> codigo;
    cout << "Nome: ";
    cin >> nome;

    disciplinas[i].setNome(nome);
    disciplinas[i].setCodigo(codigo);
    *disciplinas_cadastradas += 1;
  }
}

// lista todos os alunos cadastrados no sistema
void listarAlunos(Aluno alunos[], int *alunos_cadastrados) {
  systemClear();
  cout << "Alunos Cadastrados" << endl;
  for (int i = 0; i < *alunos_cadastrados; i++) {
    alunos[i].listar();
  }
  cout << endl;
  systemPause();
}

// cadastra notas para os alunos
void cadastrarNotas(Aluno alunos[], Disciplina disciplinas[], int alunos_cadastrados, int disciplinas_cadastradas) {
  systemClear();
  // valida se existem alunos cadastrados
  if (alunos_cadastrados <= 0) {
    cout << "Nenhum aluno cadastrado" << endl;
    systemPause();
    return;
  }

  // valida se existesm disciplinas cadastradas
  if (disciplinas_cadastradas <= 0) {
    cout << "Nenhuma disciplina cadastrada" << endl;
    systemPause();
    return;
  }

  int codigoDisciplina;
  float nota;

  cout << "Qual disciplina (codigo) deseja cadastrar notas? ";
  cin >> codigoDisciplina;

  // for para buscar o nome da disciplina de acordo com seu codigo
  for (int i = 0; i <= disciplinas_cadastradas; i++) {
    if (disciplinas[i].getCodigo() == codigoDisciplina) {
      cout << "\nCadastrando notas para a disciplina " << disciplinas[i].getNome() << endl;
    }
  }

  // for para settar nota dos alunos para determinada disciplina
  for (int i = 0; i < alunos_cadastrados; i++) {
    cout << "Qual a nota do aluno(a) " << alunos[i].getNome() << "? ";
    cin >> nota;
    alunos[i].setNota(codigoDisciplina, nota);
  }
}

// exibe as notas de um aluno de acordo com a matricula
void exibirNotasAluno(Aluno alunos[], int alunos_cadastrados) {
  systemClear();
  if (alunos_cadastrados <= 0) {
    cout << "Nenhum aluno cadastrado ainda!" << endl;
    systemPause();
    return;
  }

  int matricula;
  cout << "Digite a matricula do aluno para pesquisar as notas: ";
  cin >> matricula;

  for (int i = 0; i < alunos_cadastrados; i++) {
    if (alunos[i].getMatricula() == matricula) {
      alunos[i].exibir();
    }
  }
  systemPause();
}

// exibe o aluno com maior nota, em qual materia e com quantos pontos
void alunoMaiorNota(Aluno alunos[], int alunos_cadastrados) {
  systemClear();
  float maiorNota;
  std::string nomeDisciplina;
  std::string nomeAluno;

  alunos[0].getMaiorNota(&maiorNota, &nomeDisciplina, &nomeAluno);

  for (int i = 1; i < alunos_cadastrados; i++) {
    if (alunos[i].getMaiorNota() > maiorNota) {
      alunos[i].getMaiorNota(&maiorNota, &nomeDisciplina, &nomeAluno);
    }
  }
  if (maiorNota <= 0) {
    cout << "Nao houveram lancamentos de notas ate o momento" << endl;
  } else {
    cout << "A maior nota foi do aluno " << nomeAluno;
    cout << " na disciplina " << nomeDisciplina << ": " << maiorNota << " pontos" << endl;
  }
  systemPause();
}

// procedimento utilizado para pausar execução do sistema
void systemPause() {
  if (PAUSE == 1) {
    printf("Precione enter para continuar");
    system("pause");
  } else {
    system("read -p 'Precione enter para continuar' continuar");
  }
}

// procedimento utilizado para limpar console
void systemClear() {
  if (PAUSE == 1) {
    system("cls");
  } else {
    system("clear");
  }
}
