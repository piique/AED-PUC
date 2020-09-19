import java.util.Scanner;

public class Matheus {
  public static void main(String[] args) {
    int A, B;

    Scanner in = new Scanner(System.in);
    A = in.nextInt();
    B = in.nextInt();

    System.out.printf("SOMA = %d \n", (A + B));
    System.out.printf("SUBTRACAO = %d\n", (A - B));
    System.out.printf("MULTIPLICACAO = %d\n", (A * B));

    if (B == 0) {
      System.out.printf("DIVISAO = INDETERMINADO");
    } else {
      System.out.printf("DIVISAO = %.2f", ((float) A / B));
    }

    in.close();
  }
}