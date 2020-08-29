package Trabalho_Pratico_1;

import java.util.Scanner;

public class q3 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String v;

    // leitura de string
    v = in.nextLine();
    // verifica se chegou ao final da string atraves da palavra FIM
    while (v.charAt(0) != 'F' && v.charAt(1) != 'I' && v.charAt(2) != 'M') {
      criframento(v);
      v = in.nextLine();
    }
    in.close();
  }

  // metodo que recebe string e retorna na para usuario outra de forma cifrada
  public static void criframento(String v) {
    // for para percorrer toda a string
    for (int i = 0; i < v.length(); i++) {
      // verifica se caracter esta contitido no alfabeto de acordo com a tabela ascii
      if ((v.charAt(i) >= 65 && v.charAt(i) <= 87) || (v.charAt(i) >= 97 && v.charAt(i) <= 119))
        // adiciona 3 numeros a letra caso nao seja uma das 3 ultimas
        System.out.printf("%c", v.charAt(i) + 3);
      else {
        System.out.printf(" ");
      }

      // verifica se as letras sao as 3 ultimas do alfabeto
      if ((v.charAt(i) >= 120 && v.charAt(i) <= 122) || (v.charAt(i) >= 88 && v.charAt(i) <= 90)) {
        System.out.print((char) (v.charAt(i) - 23));
      }
    }

  }
}
