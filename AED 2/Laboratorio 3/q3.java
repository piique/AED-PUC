import java.util.Scanner;

public class q3 {

  public static void main(String[] args) {
    int N, K;
    Scanner in = new Scanner(System.in);

    float notas[] = new float[10000];

    // input qtd participantes
    N = in.nextInt();

    // input qtd classificados
    K = in.nextInt();

    // tratamento de exceção
    if (K > N || K <= 0) {
      K = N;
      System.out.printf("%d", K);
      in.close();
      return;
    }

    // input de notas
    for (int i = 0; i < N; i++) {
      notas[i] = in.nextFloat();
    }

    // chamada de função para ordenação
    insertionsort(notas, N);

    // for para contar quantas notas a mais do limite de classificação passaram
    for (int i = K; i < N; i++) {
      if (notas[i - 1] == notas[i]) {
        K++;
      } else {
        break;
      }
    }

    System.out.printf("%d", K);

    in.close();
  }

  // metodo de ordenacao por insercao
  public static void insertionsort(float v[], int n) {
    int i, j;
    float aux;
    for (i = 1; i < n; i++) {
      aux = v[i];
      j = i - 1;
      while (j > -1 && v[j] < aux) {
        v[j + 1] = v[j];
        j -= 1;
      }
      v[j + 1] = aux;
    }
  }
}
