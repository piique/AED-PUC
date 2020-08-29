#include <stdio.h>

int main(void) {
  char v[400] = {"and(not(A) , not(B))"};
  int variaveis[26];

  substituiVariaveis(v, variaveis);
  // printf("\nValor da nova  string: %s\n", v);
  return 0;
}

void substituiVariaveis(char v[], int variaveis[]) {
  char aux[500];
  int count = 0, aux = 0;

  // for para trocar variaveis pelo seu valor e copiar string v para aux
  for (int i = 0; i < strlen(v); i++) {
    if (v[i] != ' ') {
      aux[count] = v[i];
      count++;
    }
    if (i == strlen(v)) {
      aux[count] = '\0';
      break;
    }
  }
  printf("\nValor da nova  string: %s\n", aux);

  for (int i = 0; i < strlen(v); i++) {
    if (aux[i] >= 65 && aux[i] <= 90) {
      aux[i] = variaveis[aux[i] - 65] + 48;
    }
    if (i == strlen(v) - count) {
      aux[i] = '\0';
    }
  }

  // for para retirar os espacos vazios da string v
  // for (int i = 0; i < strlen(v); i++) {
  //   if (aux[i] == ' ') {
  //     count++;
  //     v[i - 1] = aux[i];
  //   } else {
  //     v[i] = aux[i];
  //   }
  // }
}
