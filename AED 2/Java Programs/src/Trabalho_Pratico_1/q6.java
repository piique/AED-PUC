package Trabalho_Pratico_1;

import java.util.Scanner;

public class q6 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N, maior, aux[] = new int[26];
    // string com input do usuario
    String string;

    // vetor de caracteres
    char v[] = new char[200];
    N = in.nextInt();

    // limpar buffer do teclado e nao pegar o "Enter"
    in.nextLine();

    for (int j = 0; j < N; j++) {
      // input de string pegando espacos
      string = in.nextLine();
      if (string.length() <= 200) {
        // zera vetor auxiliar
        zeraVetor(aux);

        // transforma todas as letras maiusculas em minusculas
        string = string.toLowerCase();

        // chamada de metodo para conversao de string para vetor de caracteres
        convertStringToChar(string, v);

        // chamada de metodo para ordenar o vetor de forma crescente
        ordenaVetor(v, string.length());

        /*
         * for para buscar letras com maior repeticao e armazenar no vetor aux em sua
         * respectiva posicao. Ex: 'a' na posicao adiciona 1 na posicao aux[0], para
         * representar a ocorrencia de uma letra a (primeira letra adiciona 1 na
         * primeira posicao e assim respectivamente).
         */
        for (int i = 0; i < string.length(); i++) {
          if (v[i] >= 97 && v[i] <= 122)
            aux[(int) v[i] - 97]++;
        }

        // for para buscar a maior quantidade de repeticoes no vetor aux e armazenar o
        // numero na variavel maior
        maior = 0;
        for (int i = 0; i < 26; i++) {
          if (maior < aux[i])
            maior = aux[i];
        }

        // for para printar letras com maior repeticoes
        for (int i = 0; i < 26; i++) {
          if (maior == aux[i]) {
            // printa letra(s) com maior ocorrencia de acordo com a tabela ascii
            System.out.printf("%c", i + 97);
          }
        }
        System.out.printf("\n");

      }
    }

    in.close();
  }

  // função utilizada para zerar todas as posicoes de um vetor v
  public static void zeraVetor(int v[]) {
    for (int i = 0; i < v.length; i++) {
      v[i] = 0;
    }
  }

  // ordena vetor em ordem afabetica - metodo de ordenação bolha utilizado
  public static void ordenaVetor(char v[], int n) {
    int aux;
    for (int j = 1; j < n; j++) {
      for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
          aux = v[i];
          v[i] = v[i + 1];
          v[i + 1] = (char) aux;
        }
      }
    }
  }

  // metodo para converter string para vetor de caracteres v
  public static void convertStringToChar(String string, char v[]) {
    for (int i = 0; i < string.length(); i++) {
      v[i] = string.charAt(i);
    }
    if (v.length != string.length())
      v[string.length()] = '\0';
  }
}
