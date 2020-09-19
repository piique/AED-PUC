package Trabalho_Pratico_1;

import java.util.Scanner;

public class q1 {

  public static void main(String[] args) {
    int n, count = 0;
    Scanner in = new Scanner(System.in);

    // recebe quantidade de numeros que serao recebidos
    n = in.nextInt();

    int v[] = new int[n];

    // preenche vetor
    for (int i = 0; i < n; i++) {
      v[i] = in.nextInt();
    }

    in.close();

    ordenaVetor(v);

    // for para realizar a contagem de numeros repetidos e printa-los
    for (int i = 0; i < n; i++) {
      count++;
      if (i == n - 1) {
        System.out.printf("%d aparece %d vez(es)\n", v[i], count);
      } else if (v[i] != v[i + 1]) {
        System.out.printf("%d aparece %d vez(es)\n", v[i], count);
        count = 0;
      }
    }
  }

  // metodo para realizar ordenação do vetor através do método bolha
  public static void ordenaVetor(int v[]) {
    int aux, n = v.length;
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

}
