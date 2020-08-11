import java.util.Scanner;

public class Calculadora_Simples {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n1 = in.nextInt();
    int n2 = in.nextInt();
    in.close();

    System.out.println("SOMA = " + (n1 + n2));
    System.out.println("SUBTRACAO = " + (n1 - n2));
    System.out.println("MULTIPLICACAO = " + (n1 * n2));

    if (n2 == 0) {
      System.out.println("DIVISAO = INDETERMINADO");
    } else {
      System.out.println("DIVISAO = " + (float) n1 / n2);
    }
  }
}
