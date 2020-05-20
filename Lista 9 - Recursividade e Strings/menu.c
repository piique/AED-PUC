#include <locale.h>  // no prompt: chcp 65001 - para funcionar formatação
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // limpar console: system("cls");
#include <time.h>

#ifdef WIN32
#define PAUSE 1
#else
#define PAUSE 0
#endif

// Declaração de funções
void questao1();
void questao2_6();
void questao7();
void questao8();
void questao9();
void questao10();

void systemPause();
void preencheVetor(int *vetor, int tamanho);
void printaVetor(int vetor[], int tamanho);
int procuraNoVetor(int vetor[], int k, int tamanhoVetor);
int maxVetor(int vetor[], int tamanho);
int minVetor(int vetor[], int tamanho);
int somaVetor(int vetor[], int tamanho);
int multiplicaVetor(int vetor[], int tamanho);
float mediaVetor(int[], int);
float _mediaVetor(int[], int, int, int);

int main() {
  setlocale(LC_ALL, "Portuguese_Brasil");
  int opc = -1;
  while (opc != 0) {
    printf("------------------------------------ MENU ------------------------------------");
    printf("\nEscolha uma das questões:  ");
    printf("\n 1    - Questao 1");
    printf("\n 2-6  - Questoes de 2 a 6");
    printf("\n 7    - Questao 7");
    printf("\n 8    - Questao 8");
    printf("\n 9    - Questao 9");
    printf("\n 10   - Questao 10");
    printf("\n 0    - Sair");
    printf("\n\nOpc: ");

    scanf("%i", &opc);

    switch (opc) {
      case 1:
        printf("\n\nQUESTAO 1\n");
        questao1();
        break;

      case 2:
        printf("\n\nQUESTOES 2 a 6\n");
        questao2_6();
        break;

      case 3:
        printf("\n\nQUESTOES 2 a 6\n");
        questao2_6();
        break;

      case 4:
        printf("\n\nQUESTOES 2 a 6\n");
        questao2_6();
        break;

      case 5:
        printf("\n\nQUESTOES 2 a 6\n");
        questao2_6();
        break;

      case 6:
        printf("\n\nQUESTOES 2 a 6\n");
        questao2_6();
        break;
      case 7:
        break;

      case 8:
        break;
      case 9:
        break;

      case 10:
        break;

      case 0:
        printf("Saindo...\n\n");
        return 0;
        break;

      default:
        printf("Escolha invalida! Precione enter para voltar ao menu.\n");
        systemPause();
    }
  }

  return 0;
}

void questao1() {
  int vetor[5], k, resultado;

  preencheVetor(vetor, 5);
  printf("\nPrintando vetor...");
  printaVetor(vetor, 5);

  printf("Digite um valor a ser procurado no vetor acima: ");
  scanf("%i", &k);

  resultado = procuraNoVetor(vetor, k, 5);
  if (resultado == -1) {
    printf("Nao foi encontrado o valor %i no vetor\n", k);
  } else {
    printf("O valor %i foi encontrado no vetor na posicao %i. Vetor[%i]: %i\n", k, resultado, k, resultado);
  }

  printf("\nPrecione enter para voltar ao menu");
  systemPause();
}

void questao2_6() {
  // tamanho vetor = sizeof(vetor)/sizeof(vetor[0]);
  int tamanho = 5, vetor[5] = {2, 6, 4, 6, 2};
  // int tamanho = 5, vetor[tamanho];
  // preencheVetor(vetor, tamanho);
  printf("\nVetor gerado aleatoriamente: \n");
  printaVetor(vetor, tamanho);

  printf("Valor maximo do vetor: %i\n", maxVetor(vetor, tamanho));
  printf("Valor minimo do vetor: %i\n", minVetor(vetor, tamanho));
  printf("Valor da soma do vetor: %i\n", somaVetor(vetor, tamanho));
  printf("Valor do produto do vetor: %i\n", multiplicaVetor(vetor, tamanho));
  printf("Valor da media do vetor: %0.2f\n", mediaVetor(vetor, tamanho));

  printf("\nPrecione enter para voltar ao menu.");
  systemPause();
}

void questao7() {
}

void questao8() {
}

void questao9() {
}

void questao10() {
}

void systemPause() {
  if (PAUSE == 1)
    system("pause");
  else
    system("read -p '' continuar");
}

/*
Descrição: retorna a posição em que k foi encontrado ou -1
Entradas: um vetor, seu tamanho e um valor a ser procurado 
Saída: retorna a posicao que k foi encontrada ou -1
*/
int procuraNoVetor(int vetor[], int k, int tamanhoVetor) {
  if (vetor[tamanhoVetor - 1] == k || tamanhoVetor == 0) {
    return tamanhoVetor - 1;
  }
  return procuraNoVetor(vetor, k, --tamanhoVetor);
}

/*
Descrição: retorna o maior elemento do vetor de inteiro
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna o maior elemento do vetor
*/
int maxVetor(int vetor[], int tamanho) {
  int max;
  if (tamanho == 1) {
    max = vetor[0];
  } else {
    max = maxVetor(vetor, tamanho - 1);
    if (vetor[tamanho - 1] > max) {
      max = vetor[tamanho - 1];
    }
  }
  return max;
}

/*
Descrição: retorna o menor elemento do vetor de inteiro
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna o menor elemento do vetor
*/
int minVetor(int vetor[], int tamanho) {
  int min;
  if (tamanho == 1) {
    min = vetor[0];
  } else {
    min = minVetor(vetor, tamanho - 1);
    if (vetor[tamanho - 1] < min) {
      min = vetor[tamanho - 1];
    }
  }
  return min;
}

/*
Descrição: retorna a soma dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna a soma dos elementos
*/
int somaVetor(int vetor[], int tamanho) {
  if (tamanho == 1) {
    return vetor[tamanho - 1];
  }
  tamanho--;
  return vetor[tamanho] + somaVetor(vetor, tamanho);
}

/*
Descrição: retorna o produto dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna o produto dos elementos
*/
int multiplicaVetor(int vetor[], int tamanho) {
  if (tamanho == 1) {
    return vetor[tamanho - 1];
  }
  tamanho--;
  return vetor[tamanho] * multiplicaVetor(vetor, tamanho);
}

/*
Descrição: retorna a media dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro e seu tamanho
Saída: retorna a media dos elementos
*/
float mediaVetor(int vetor[], int tamanho) {
  return _mediaVetor(vetor, tamanho, 0, tamanho);
}

/*
Descrição: retorna a media dos elementos de um vetor de inteiros
Entradas: um vetor de inteiro, seu tamanho e a soma inicial
Saída: retorna a media dos elementos
*/
float _mediaVetor(int vetor[], int tamanho, int soma, int aux) {
  if (tamanho == 0)
    return (float)soma / (aux - 1);

  soma += vetor[tamanho - 1];
  return _mediaVetor(vetor, --tamanho, soma, aux);
}

/*
Descrição: recebe um vetor e preenche com valores aleatorios entre 0 e 10
Entradas: ponteiro de vetor e seu tamanho
Saída: retorna vetor por referencia
*/
void preencheVetor(int *vetor, int tamanho) {
  // sizeof(vetor) / sizeof(vetor[0]);
  printf("...Preenchendo vetor\n");
  srand(time(NULL));
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % 11;  // numeros aleatorios entre 0 e 10
  }
}

/*
Descrição: recebe um vetor inteiro e printa seus valores
Entradas: ponteiro de vetor e seu tamanho
Saída: nao possui
*/
void printaVetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("Vetor[%i]: %i  \n", i, vetor[i]);
  }
  printf("\n");
}
