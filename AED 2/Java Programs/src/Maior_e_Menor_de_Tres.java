import java.util.Scanner;

public class Maior_e_Menor_de_Tres {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    in.close();

    if (a >= b && a >= c) {
      System.out.println("MAIOR = " + a);
    } else if (b >= a && b >= c) {
      System.out.println("MAIOR = " + b);
    } else if (c >= a && c >= b) {
      System.out.println("MAIOR = " + c);
    }

    if (a <= b && a <= c) {
      System.out.println("MENOR = " + a);
    } else if (b <= a && b <= c) {
      System.out.println("MENOR = " + b);
    } else if (c <= a && c <= b) {
      System.out.println("MENOR = " + c);
    }
  }
}
