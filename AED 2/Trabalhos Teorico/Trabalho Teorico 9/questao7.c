#include <stdio.h>
#include <stdlib.h>

// calculadora que retorna valor atraves de ponteiro
int *calculadora(int n1, int n2, int operador, int *resultado) {
  switch (operador) {
    case 1:
      *resultado = n1 + n2;
      break;

    case 2:
      *resultado = n1 - n2;
      break;

    case 3:
      *resultado = n1 * n2;
      break;

    case 4:
      *resultado = n1 / n2;
      break;
  }
  return resultado;
}

int main() {
  int n1, n2, operador;
  int *resultado;

  printf("Digite o valor do primeiro numero: ");
  scanf("%i", &n1);
  printf("Digite o valor do segundo numero: ");
  scanf("%i", &n2);
  printf("\nEscolha uma das opcoes abaixo: \n");
  printf("1 - soma\n");
  printf("2 - subtracao\n");
  printf("3 - multiplicacao\n");
  printf("4 - divisao\n");
  printf("Opcao: ");
  scanf("%i", &operador);

  calculadora(n1, n2, operador, resultado);

  printf("Resultado da operacao: %i", *resultado);

  return 0;
}
