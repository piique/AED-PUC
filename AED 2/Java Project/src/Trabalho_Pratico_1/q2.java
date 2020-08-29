package Trabalho_Pratico_1;

import java.util.Scanner;

public class q2 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N, menorValor, menorPosicao;
    int X[] = new int[1000];

    // recebe quantidade de numeros que serao recebidos
    N = in.nextInt();

    // preenche vetor
    for (int i = 0; i < N; i++) {
      X[i] = in.nextInt();
    }

    in.close();

    // atribui valor para as variaveis relacionadas o menor valor e posicao
    menorPosicao = 0;
    menorValor = X[0];

    // for para buscar pelo menor valor armazena-lo junto com sua posicao
    for (int i = 0; i < N; i++) {
      if (X[i] < menorValor) {
        menorValor = X[i];
        menorPosicao = i;
      }
    }

    // printa saida
    System.out.printf("Menor valor: %d\n", menorValor);
    System.out.printf("Posicao: %d", menorPosicao);
  }
}
