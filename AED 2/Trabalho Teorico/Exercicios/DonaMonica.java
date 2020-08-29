import java.util.Scanner;
import java.lang.Math;

public class DonaMonica {
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

  // Descricao: recebe uma string e verifica se eh palindromo desconsiderando
  // espacos vazios.
  // Entradas: recebe 1 strings (char[]) e 1 string String
  // Saida: true para eh palindromo e false para nao palindromo
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

    // finalizar string aux com '\0'
    if (count < tamanho - 1)
      aux[count] = '\0';

    int j = count - 1;
    int i = 0;

    while (i < count) {
      if (aux[i] != aux[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
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
