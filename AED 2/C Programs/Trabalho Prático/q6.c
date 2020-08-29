#include <stdio.h>
#include <string.h>

// declaracao de funcoes
void zeraVetor(int v[], int n);
void ordenaVetor(char v[], int n);

int main(void) {
  int N, aux[26], maior;
  char v[200];

  // input para pegar quantidade de casos de testes a serem realizados
  scanf("%i", &N);
  // limpa buffer do teclado
  setbuf(stdin, NULL);

  for (int j = 0; j < N; j++) {
    v[0] = '\0';

    // input de string pegando espacos
    scanf("%[^\n]s", v);
    // limpa buffer do teclado
    setbuf(stdin, NULL);

    // zera vetor auxiliar
    zeraVetor(aux, 26);

    // chamada de função para ordenar o vetor de forma crescente
    ordenaVetor(v, strlen(v));

    // for para buscar letras com maior repeticao e armazenar no vetor aux em sua respectiva posicao
    // ex: a na posicao aux[0]++, para representnar a ocorrencia de uma letra a
    for (int i = 0; i < strlen(v); i++) {
      if (v[i] >= 97 && v[i] <= 122)
        aux[(int)v[i] - 97]++;
    }

    // for para buscar a maior quantidade de repeticoes no vetor aux e armazenar o numero na variavel maior
    maior = 0;
    for (int i = 0; i < 26; i++) {
      if (maior < aux[i])
        maior = aux[i];
    }

    // for para printar letras com maior repeticoes
    for (int i = 0; i < 26; i++) {
      if (maior == aux[i]) {
        // printa letra(s) com maior ocorrencia de acordo com a tabela ascii
        printf("%c", i + 97);
      }
    }
    printf("\n");
  }

  return 0;
}

// função utilizada para zerar todas as posicoes de um vetor v de tamanho n
void zeraVetor(int v[], int n) {
  for (int i = 0; i < n; i++) {
    v[i] = 0;
  }
}

// ordena vetor em ordem afabetica e transforma letras maiusculas em minusculas - metodo de ordenação bolha utilizado
void ordenaVetor(char v[], int n) {
  int aux;

  // coloca todas as letras em minuscula
  for (int i = 0; i < n; i++) {
    v[i] = tolower(v[i]);
  }

  // ordena de forma crescente através do metodo bolha
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i] > v[i + 1]) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }
}
