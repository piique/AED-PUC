package Trabalho_Pratico_1;

import java.util.Scanner;

public class q4 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String v;

    // leitura de string
    v = in.nextLine();
    in.close();
    criptografaString(v, 0);
  }

  // metodo recusrsivo para criptografar letra por letra em cada chamada
  public static void criptografaString(String v, int i) {
    if (i < v.length()) {
      // verifica se chegou ao final da string atraves da palavra FIM
      if (v.charAt(i) == 'F' && v.charAt(i + 1) == 'I' && v.charAt(i + 2) == 'M') {
        return;
      }
      // verifica se caracter esta contitido no alfabeto de acordo com a tabela ascii
      // (imprimir espacos vazios)
      if ((v.charAt(i) >= 65 && v.charAt(i) <= 87) || (v.charAt(i) >= 97 && v.charAt(i) <= 119))
        // adiciona 3 numeros a letra caso nao seja uma das 3 ultimas
        System.out.printf("%c", v.charAt(i) + 3);
      else {
        System.out.printf(" ");
      }

      // verifica se as letras sao as 3 ultimas do alfabeto
      if ((v.charAt(i) >= 120 && v.charAt(i) <= 122) || (v.charAt(i) >= 88 && v.charAt(i) <= 90)) {
        if (v.charAt(i) == 'X') {
          System.out.printf("A");
        } else if (v.charAt(i) == 'x') {
          System.out.printf("a");
        } else if (v.charAt(i) == 'Y') {
          System.out.printf("B");
        } else if (v.charAt(i) == 'y') {
          System.out.printf("b");
        } else if (v.charAt(i) == 'Z') {
          System.out.printf("B");
        } else if (v.charAt(i) == 'z') {
          System.out.printf("b");
        }
      }
      // chama a função novamente para a proxima letra ser criptografada
      criptografaString(v, ++i);
    }
  }
}
