import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    int aux = 0;

    Scanner in = new Scanner(System.in);
    String text;
    int n = in.nextInt();

    while (n > aux) {
      text = in.nextLine();
      in.nextLine();
      frequencia(text);
      aux++;
    }
    // System.out.println("Hello world!");
  }

  public static void frequencia(String text) {
    int tam, maior = 0;

    int letra[] = new int[26];

    tam = text.length();

    text = text.toLowerCase();

    // zerando letras
    for (int i = 0; i < 26; i++) {
      letra[i] = 0;
    }

    // la??o de repeticao para ver qual letras repete e gravar na sua posicao
    for (int i = 0; i < tam; i++) {
      if (text.charAt(i) >= 97 && text.charAt(i) <= 122) {
        letra[text.charAt(i) - 97]++;
      }
    }

    // la??o para ver qual das letras repete mais
    for (int i = 0; i < 26; i++) {
      if (maior < letra[i]) {
        maior = letra[i];
      }
    }

    for (int i = 0; i < 26; i++) {
      if (maior == letra[i]) {
        System.out.printf("%c", i + 97);// printando as letras que mais repete
      }
    }
    // printf("\n");
  }

}