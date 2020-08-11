import java.util.Scanner;

public class Maior_e_Menor_Vetor {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int maior, menor;
    int n = in.nextInt();
    int v[] = new int[n];

    for (int i = 0; i < n; i++) {
      v[i] = in.nextInt();
    }
    in.close();
    maior = v[0];
    menor = v[0];

    for (int i = 0; i < n; i++) {
      if (v[i] > maior) {
        maior = v[i];
      }
      if (v[i] < menor) {
        menor = v[i];
      }
    }
    System.out.println("MAIOR = " + maior);
    System.out.println("MENOR = " + menor);
  }

}
