#include <math.h>
#include <stdio.h>
#include <string.h>
/*
  Crie um programa que leia um arquivo TXT contendo em cada linha os valores de
  coordenadas X Y Z e retorne a soma das distâncias sequenciais entre os pontos. O nome do
  arquivo deverá ser informado pelo usuário.

  Formula para calcular distancias entre pontos: ver imagem1.jpg
*/

#define N 4

// definicao da struct de Ponto (coordenada)
struct Ponto {
  int x;
  int y;
  int z;
};

int preencheCoordenadas(char *, struct Ponto[]);
float somaDistanciaTotal(struct Ponto coordenada[]);

int main() {
  char nome_arquivo[100];
  struct Ponto coordenada[N];
  printf("Digite o nome do arquivo: ");
  scanf("%s", nome_arquivo);
  // strcpy(nome_arquivo, "arquivo.txt");

  if (preencheCoordenadas(nome_arquivo, coordenada)) {
    // printf("Qtd digitos: %i", count);
    printf("Distancia total entre os pontos: %0.2f\n", somaDistanciaTotal(coordenada));
  }
  return 0;
}

/*
Descrição: recebe o nome de um arquivo e um vetor de Ponto para preencher com base no arquivo
Entradas: char nome do arquivo e 1 vetor de Ponto
Saída: inteiro 0-erro ou 1
*/
int preencheCoordenadas(char *nome_arquivo, struct Ponto coordenada[]) {
  FILE *fp;
  if ((fp = fopen(nome_arquivo, "r")) != NULL) {
    printf("\nPontos: \n\n");
    for (int i = 0; i < N; i++) {
      fscanf(fp, "%i %i  %i", &coordenada[i].x, &coordenada[i].y, &coordenada[i].z);
      printf("Ponto[%i]: \n", i);
      printf("x: %i\n", coordenada[i].x);
      printf("y: %i\n", coordenada[i].y);
      printf("z: %i\n\n", coordenada[i].z);
    }
    fclose(fp);
    return 1;
  } else {
    printf("\nErro ao abrir arquivo!\n");
    return 0;
  }
}

/*
Descrição: recebe um vetor de Ponto e retorna a soma das distancias desses pontos
Entradas: 1 vetor de Ponto
Saída: float com valor da soma das distancias
*/
float somaDistanciaTotal(struct Ponto coordenada[]) {
  float soma = 0.0;
  float diferencaX, diferencaY, diferencaZ;
  // ver imagem1.jpg
  for (int i = 0; i < N - 1; i++) {
    diferencaX = (float)coordenada[i + 1].x - coordenada[i].x;
    diferencaY = (float)coordenada[i + 1].y - coordenada[i].y;
    diferencaZ = (float)coordenada[i + 1].z - coordenada[i].z;
    soma += pow((pow(diferencaX, 2) + pow(diferencaY, 2) + pow(diferencaZ, 2)), 0.5);
  }
  return soma;
}
