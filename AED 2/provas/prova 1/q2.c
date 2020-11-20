#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaração função
char* somente_consoante(char* v, int n);

int main(void) {
  // declaração vetor
  char v[10000];

  // input usuario
  scanf(" %[^\n]s\n", v);

  // tamanho vetor
  int n = strlen(v);

  // chamada de função e atribuição de resultado em ponteiro
  char* aux = somente_consoante(v, n);

  // printa novo vetor
  printf("%s", aux);

  // limpa memoria alocada
  free(aux);

  return 0;
}

// função que recebe vetor de char e seu tamnho e retorna ponteiro para vetor com as consoantes
char* somente_consoante(char* v, int n) {
  // aloca dinamicamente memoria para novo vetor
  char* newV = malloc(n * sizeof(char));
  int aux = 0;

  // for para percorrer e preencher novo vetor com consoantes
  for (int i = 0; i < n; i++) {
    // verifica se é letra
    if ((v[i] >= 65 && v[i] <= 90) || (v[i] >= 97 && v[i] <= 122)) {
      // verifica se é consoante
      if (v[i] != 'A' && v[i] != 'E' && v[i] != 'I' && v[i] != 'O' && v[i] != 'U' && v[i] != 'a' && v[i] != 'e' && v[i] != 'i' && v[i] != 'o' && v[i] != 'u') {
        newV[aux++] = v[i];
      }
    }
  }
  newV[aux] = '\0';
  return newV;
}