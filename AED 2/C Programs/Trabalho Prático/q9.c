#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void zeraVetorChar(char v[], int n);
void zeraVetorInt(int v[], int n);
bool trabalharAnd(char v[], int variaveis[], int inicio, int final);
bool logicaBooleana(char v[], int variaveis[], int inicio, int final);
void trocaString(char str[], int inicio, int fim, char parteStr[]);
bool not(int value);
bool or (int v1, int v2);
bool or3(int v1, int v2, int v3);
bool and (int v1, int v2);
bool and3(int v1, int v2, int v3);

int main(void) {
  int N, variaveis[26];
  char v[500], operacao[3];

  int inicio, final;

  // string com input do usuario
  scanf("%i ", &N);
  // printf("Valor de N: %i\n", N);

  do {
    zeraVetorChar(v, 500);
    zeraVetorInt(variaveis, 26);

    // preenche variaveis em suas respectivas posicoes 0-A, 1-B, 2-C e etc
    for (int i = 0; i < N; i++) {
      scanf("%i ", &variaveis[i]);
    }

    // printf("Valor lido: %c\n", v[0]);

    if (logicaBooleana(v, variaveis, 0, 0))
      printf("SIM");  // true
    else
      printf("NAO");  //false

    // printf("Operacao: %s\n", operacao);
    // printf("Comeco do parenteses: %i\n", inicio);
    // printf("Final do parenteses: %i\n", final);

    scanf("%i ", &N);
    // printf("Valor de N: %i\n", N);
  } while (N != 0);

  return 0;
}

bool logicaBooleana(char v[], int variaveis[], int inicio, int final) {
  int count = 0, qtdTermos = 1, termos[1000];
  char operacao[3];

  // recebe e seleciona primeira string
  for (int i = inicio; true; i++) {
    fflush(stdin);
    scanf("%c", &v[i]);
    // printf("Valor lido: %c\n", v[i]);
    if (v[i] == '(' && count == 0) {
      inicio = i + 1;
      count++;
    } else if (v[i] == '(') {
      count--;
    } else if (v[i] == ')' && count == 1) {
      final = i - 1;
      break;
    } else if (v[i] == ')') {
      count++;
    }
  }

  v[final + 2] = '\0';

  count = 0;

  substituiVariaveis(v, variaveis);

  //para contar quantidade de termos
  for (int i = inicio; i <= final; i++) {
    if (v[i] == '(') {
      count--;
    } else if (v[i] == ')') {
      count++;
    } else if (v[i] == ',' && count == 0) {
      if (v[i - 2] == ')') {
        // printf("Chamada recursiva para termo menor");
        // logicaBooleana(v, variaveis, inicio, v[i - 2]);
      }
      qtdTermos++;
    }
  }

  if (final - inicio > qtdTermos) {
    printf("Qtd Termos: %i", qtdTermos);
  }

  // printf("String: %s\n", v);
  printf("Qtd Termos: %i\n", qtdTermos);

  if (v[inicio - 4] == 'a' && v[inicio - 3] == 'n' && v[inicio - 2] == 'd') {
    operacao[0] = 'a';
    operacao[1] = 'n';
    operacao[2] = 'd';
    operacao[3] = '\0';
    // return trabalharAnd(v, variaveis, inicio, final);
  } else if (v[inicio - 3] == 'o' && v[inicio - 2] == 'r') {
    operacao[0] = 'o';
    operacao[1] = 'r';
    operacao[2] = '\0';
    // chamada de funcao para or passando inicio, final e v
  } else if (v[inicio - 4] == 'n' && v[inicio - 3] == 'o' && v[inicio - 2] == 't') {
    if (not(variaveis[v[4] - 65])) {
      return true;
    } else {
      return false;
    }
  }

  return false;
}

bool trabalharAnd(char v[], int variaveis[], int inicio, int final) {
  int qtdTermos = 1;
  char aux[400];

  printf("Printando conteudo do AND: \n");

  for (int i = 0; i <= final - inicio; i++) {
    aux[i] = v[i + inicio];
    printf("%c", v[i + inicio]);
  }

  printf("\nAux:%s\n", aux);

  printf("\n");
}

// recebe valor booleano (0 ou 1) e retorna o valor negado
bool not(int value) {
  return value == 0;
}

// recebe vetor de char e seu tamanho para colocar o caracter 0 em todas as posicoes
void zeraVetorChar(char v[], int n) {
  for (int i = 0; i < n; i++) {
    v[i] = '0';
  }
}

// recebe vetor de int e seu tamanho para colocar 0 em todas as posicoes
void zeraVetorInt(int v[], int n) {
  for (int i = 0; i < n; i++) {
    v[i] = 0;
  }
}

// substitui as variaveis pelos seus valores em char ex: troca 'A' por '1' ou '0';
void substituiVariaveis(char v[], int variaveis[]) {
  for (int i = 0; i < strlen(v); i++) {
    if (v[i] >= 65 && v[i] <= 90) {
      v[i] = variaveis[v[i] - 65] + 48;
    }
  }
}

bool and (int v1, int v2) {
  return v1 == v2 && v1 == 1;
}

bool and3(int v1, int v2, int v3) {
  return v1 == v2 && v1 == v3 && v1 == 1;
}

bool or (int v1, int v2) {
  return v1 || v2;
}

bool or3(int v1, int v2, int v3) {
  return v1 || v2 || v3;
}

// recebe string, uma parte dela (inicio e fim) e uma parte de string para substituir no intenrvalo inicio - fim
void trocaString(char str[], int inicio, int fim, char parteStr[]) {
  int aux = 0;
  char newStr[strlen(str) - (fim - inicio) + strlen(parteStr)];  // nova string

  for (int i = 0; i < strlen(newStr); i++) {
    if (i > inicio && i < fim) {
      if (aux < strlen(parteStr)) {
        newStr[i] = parteStr[aux];
        aux++;
      } else {
        aux = fim + 1;
      }
    } else {
      newStr[i] = str[aux];
    }
  }

  for (int i = 0; i < strlen(newStr); i++) {
    str[i] = newStr[i];
  }
  str[strlen(newStr)] = '\0';
}

// 4
// 2

// pedro henrique vilaca
// pedro just

// just

// 2 0 0 and(not(A) , not(B))
// 2 0 1 and(not(A) , not(B))
// 3 0 0 0 and(or(A , B , not(C)) , or(B , C) , or(not(A) , C))
//0

// or(A, B)

// SIM
// NAO

// 4 4 4 7 8 8 10 10 10 260
