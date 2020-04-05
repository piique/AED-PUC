#include <stdio.h>


int main() {
  
  int opc = 0, l;

  printf("Digite a quantidade de elementos a serem exibidos da serie Fibonacci: ");
  scanf("%i", &l);
  printf("Qual opcaoo deseja utilizar? \n 1 - Normal (rapido)\n 2 - Utilizando funcao recursiva (lento) \n Escolha: ");
  scanf("%i", &opc);
  if(opc == 1){
    imprimeSeqFib(l);
  }else if (opc == 2){
    imprimeFibRecursivamente(l);
  }else {
    printf("Opcao invalida");
  }
  
  return 0;
}

void imprimeSeqFib(int l){
  // declaração de variaveis
  int penultimo = 0, ultimo = 0, atual = 0, count = 0;

  // valida se numero inserido é valido
  if(l > 0){
    // if para verificar se possui apenas uma posição e printar as primeiras (primeira e segunda)
    if(l == 1){
      printf("%i", atual);
      count = 1;
    }else { 
      printf("%i %i ", ultimo, ultimo+1);
      ultimo++;
      count = 2;
    }

    // while utilizado para printar os numeros da sequencia a partir da terceira posição
    while(l > count){
      atual = penultimo+ultimo;
      printf("%i ", atual);
      penultimo = ultimo;
      ultimo = atual;
      count++;
    }
  }else {
    printf("Valor invalido");
  }
}

// utilização de recursividade
void imprimeFibRecursivamente(int l) {
  int aux = 0;
  while ( l > aux ){
    printf("%d ", fib(aux));
    aux++;
  }
}

// função que recebe uma posiçao e retorna o valor correspondente em relação à sequencia de Fibonacci
int fib (int n) {
  if ( n < 2 ) {
    return n;
  }
  else {
    return fib(n - 1) + fib(n - 2);
  }
}