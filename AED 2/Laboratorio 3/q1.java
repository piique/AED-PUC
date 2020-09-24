import java.util.Scanner;

public class q1 {
  public static void main(String[] args) {
    int n, auxPar = 0, auxImpar = 0;
    int vPar[] = new int[1000], vImpar[] = new int[1000], v[] = new int[1000];

    Scanner in = new Scanner(System.in);
    n = in.nextInt();

    for (int i = 0; i < n; i++) {
      v[i] = in.nextInt();
    }

    in.close();

    // separa em 2 arrays (Par e Impar)
    for (int i = 0; i < n; i++) {
      if (v[i] % 2 == 0) {
        vPar[auxPar++] = v[i];
      } else {
        vImpar[auxImpar++] = v[i];
      }
    }

    bolha(vPar, auxPar);
    bolhaDecrescente(vImpar, auxImpar);
    substituiArrayOriginal(v, n, vPar, auxPar, vImpar, auxImpar);

  }

  // metodo de ordenação bolha
  public static void bolha(int v[], int n) {
    int i, j, temp;
    for (i = n - 1; i >= 1; i--) {
      for (j = 0; j < i; j++) {
        if (v[j] > v[j + 1]) {
          temp = v[j];
          v[j] = v[j + 1];
          v[j + 1] = temp;
        }
      }
    }
  }

  // metodo de ordenação bolha decrescente
  public static void bolhaDecrescente(int v[], int n) {
    int i, j, temp;
    for (i = n - 1; i >= 1; i--) {
      for (j = 0; j < i; j++) {
        if (v[j] < v[j + 1]) {
          temp = v[j];
          v[j] = v[j + 1];
          v[j + 1] = temp;
        }
      }
    }
  }

  // função para substituir valores no array original enquanto printa os mesmos
  public static void substituiArrayOriginal(int v[], int n, int vPar[], int auxPar, int vImpar[], int auxImpar) {
    int aux = 0;
    for (int i = 0; i < n; i++) {
      if (i < auxPar) {
        v[i] = vPar[i];
      } else {
        v[i] = vImpar[aux++];
      }
      System.out.printf("%d\n", v[i]);
    }
  }

}
