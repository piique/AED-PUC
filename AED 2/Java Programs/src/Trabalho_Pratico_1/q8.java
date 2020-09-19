package Trabalho_Pratico_1;

import java.util.Scanner;

public class q8 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    // string com input do usuario
    String string;
    // vetor de caracteres
    char v[] = new char[200];

    // controlar laco de repeticao while
    boolean aux = true;

    while (aux) {
      // input de string pegando espacos
      string = in.nextLine();

      // verifica se string eh igual a FIM
      if (string.charAt(0) != 'F' && string.charAt(1) != 'I' && string.charAt(2) != 'M') {
        // chamada de metodo
        convertStringToChar(string, v);

        // verifica se eh palindromo atraves da funcao e printa saida
        if (ehPalindromo(v, string.length())) {
          System.out.printf("SIM\n");
        } else {
          System.out.printf("NAO\n");
        }
      } else {
        aux = false;
      }
    }
    in.close();
  }

  // metodo para retirar espacos vazios da string e realizar a chamada do metodo
  // recursivo
  public static boolean ehPalindromo(char v[], int tamanho) {
    char aux[] = new char[tamanho];
    int count = 0; // armazenar quantidade de caracteres presentes no aux

    // for para retirar espacos em branco
    for (int i = 0; i < tamanho; i++) {
      if (v[i] != ' ') {
        aux[count] = v[i];
        count++;
      }
    }

    // finalizar string aux com '\0' caso algum espaco tenha sido retirado
    if (count < tamanho - 1)
      aux[count] = '\0';

    // retorna metodo recursivo
    return ehPalindromo(aux, 0, count - 1);
  }

  // metodo recursivo para verificar se string eh palindromo ou nao
  public static boolean ehPalindromo(char v[], int i, int j) {
    if (i > j) {
      return true;
    } else if (v[i] != v[j]) {
      return false;
    } else {
      return ehPalindromo(v, ++i, --j);
    }
  }

  // metodo para converter string para vetor de caracteres v com todas as letras
  // minusculas
  public static void convertStringToChar(String string, char v[]) {
    // transforma todas as letras maiusculas em minusculas
    string = string.toLowerCase();
    for (int i = 0; i < string.length(); i++) {
      v[i] = string.charAt(i);
    }
    v[string.length()] = '\0';
  }
}
