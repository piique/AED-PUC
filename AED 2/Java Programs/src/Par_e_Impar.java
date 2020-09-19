import java.util.Scanner;

public class Par_e_Impar {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int num = in.nextInt();
    in.close();

    if (num % 2 == 0) {
      System.out.print("PAR");
    } else {
      System.out.print("IMPAR");
    }

    System.out.print(" e ");

    if (num > 0) {
      System.out.print("POSITIVO");
    } else {
      if (num == 0) {
        System.out.print("NEUTRO");
      } else {
        System.out.print("NEGATIVO");
      }
    }

  }
}
