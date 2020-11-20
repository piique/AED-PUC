#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// zera todas as posições do vetor
void zera_vetor(int *v) {
  for (int i = 0; i < 100; i++)
    v[i] = 0;
}

// verifica qual tipo de estrutura utilizado
void verificaEstrutura(char n) {
  int vetor[100];
  int operacao, num;
  int primeiro_entrar, primeiro_sair;
  int ultimo_entrar, ultimo_sair;
  zera_vetor(vetor);
  for (int i = 0; i < (int)n; i++) {
    scanf("%i %i\n", &operacao, &num);
    switch (operacao) {
      case 1:
        if (i == 0) {
          primeiro_entrar = num;
        }
        ultimo_entrar = num;
        vetor[num]++;
        break;
      case 2:
        if (num == primeiro_entrar) {
          primeiro_sair = num;
        }
        ultimo_sair = num;
        vetor[num]--;
        break;
    }
  }

  if (primeiro_entrar == primeiro_sair) {
    printf("stack\n");
  } else if (primeiro_entrar == ultimo_sair) {
    printf("queue\n");
  } else {
    printf("impossible\n");
  }
}

int main() {
  char numero;
  do {
    scanf("%c", &numero);
    verificaEstrutura(numero);
  } while (numero != '\n');
}
