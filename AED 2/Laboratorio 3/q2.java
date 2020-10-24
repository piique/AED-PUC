import java.util.Scanner;

public class q2 {

  public static void main(String[] args) {
    int n, max;
    String string;
    Scanner in = new Scanner(System.in);
    n = in.nextInt();

    for (int i = 0; i < n; i++) {
      max = 0;
      in.nextLine();
      string = in.nextLine();

      // divisao de string em palavras
      String[] palavras = string.split(" ");

      System.out.println("String recebida: " + string);

      // for para achar maior quantidade de letras
      for (int j = 0; j < palavras.length; j++) {
        if (palavras[j].length() > max) {
          max = palavras[j].length();
        }
      }

      // for para a partir da maior quantiadde de letras, printar em ordem decrescente as palavras
      for (int k = 0; k < max; max--) {
        for (int j = 0; j < palavras.length; j++) {
          if (palavras[j].length() == max) {
            System.out.printf("%s ", palavras[j]);
          }
        }
      }
      System.out.printf("\n");
    }

    in.close();
  }
}
