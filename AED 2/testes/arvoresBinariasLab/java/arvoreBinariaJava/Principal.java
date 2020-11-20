import java.util.Scanner;

public class Principal {

  public static void main(String[] args) throws Exception {
    ArvoreBinaria arvoreBinaria = new ArvoreBinaria();
    Scanner in = new Scanner(System.in);
    int tam, value, altura;
    // tam = in.nextInt();

    // for (int i = 0; i < tam; i++) {
    //   value = in.nextInt();
    //   arvoreBinaria.inserir(value);
    // }

    // in.close();
    // altura = arvoreBinaria.altura();
    // System.out.println("ALTURA = " + altura);

    arvoreBinaria.inserir(3);
    arvoreBinaria.inserir(5);
    arvoreBinaria.inserir(1);
    arvoreBinaria.inserir(8);
    arvoreBinaria.inserir(2);
    arvoreBinaria.inserir(4);
    arvoreBinaria.inserir(7);
    arvoreBinaria.inserir(6);

    arvoreBinaria.caminharCentral();
    arvoreBinaria.caminharPre();
    arvoreBinaria.caminharPos();
    // arvoreBinaria.remover(6);
    // arvoreBinaria.remover(2);
    // arvoreBinaria.remover(4);

    // arvoreBinaria.caminharCentral();
    // arvoreBinaria.caminharPre();
    // arvoreBinaria.caminharPos();
  }
}
// import java.util.Scanner;
// public class Main {
//   public static void main(String[] args) {
//     Scanner in = new Scanner(System.in);
//     int N, menorValor, menorPosicao;
//     int X[] = new int[1000];
//     // recebe quantidade de numeros que serao recebidos
//     N = in.nextInt();
//     // preenche vetor
//     for (int i = 0; i < N; i++) {
//       X[i] = in.nextInt();
//     }
//     in.close();
//     // atribui valor para as variaveis relacionadas o menor valor e posicao
//     menorPosicao = 0;
//     menorValor = X[0];
//     // for para buscar pelo menor valor armazena-lo junto com sua posicao
//     for (int i = 0; i < N; i++) {
//       if (X[i] < menorValor) {
//         menorValor = X[i];
//         menorPosicao = i;
//       }
//     }
//     // printa saida
//     System.out.printf("Menor valor: %d\n", menorValor);
//     System.out.printf("Posicao: %d", menorPosicao);
//   }
// }
