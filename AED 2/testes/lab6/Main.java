import java.util.Scanner;

public class Main {

  static class No {

    public String elemento; // Conteudo do no.
    public No esq, dir; // Filhos da esq e dir.

    /**
     * Construtor da classe.
     * @param elemento Conteudo do no.
     */
    public No(String elemento) {
      this(elemento, null, null);
    }

    /**
     * Construtor da classe.
     * @param elemento Conteudo do no.
     * @param esq No da esquerda.
     * @param dir No da direita.
     */
    public No(String elemento, No esq, No dir) {
      this.elemento = elemento;
      this.esq = esq;
      this.dir = dir;
    }
  }

  public static class ArvoreBinaria {

    private No raiz; // Raiz da arvore.

    /**
     * Construtor da classe.
     */
    public ArvoreBinaria() {
      raiz = null;
    }

    /**
     * Metodo publico iterativo para pesquisar elemento.
     * @param x Elemento que sera procurado.
     * @return <code>true</code> se o elemento existir,
     * <code>false</code> em caso contrario.
     */
    public No pesquisar(String x) {
      return pesquisar(x, raiz);
    }

    /**
     * Metodo privado recursivo para pesquisar elemento.
     * @param x Elemento que sera procurado.
     * @param i No em analise.
     * @return <code>true</code> se o elemento existir,
     * <code>false</code> em caso contrario.
     */
    private No pesquisar(String x, No i) {
      No resp = i;
      if (i == null) {
        return null;
      } else if (x.equals(i.elemento)) {
        return i;
      } else {
        resp = pesquisar(x, i.esq);
        if (resp == null) {
          resp = pesquisar(x, i.dir);
        }
      }
      return resp;
    }

    /**
     * Metodo publico iterativo para exibir elementos.
     */
    public void caminharCentral() {
      // System.out.print("[ ");
      caminharCentral(raiz);
      // System.out.println("]");
    }

    /**
     * Metodo privado recursivo para exibir elementos.
     * @param i No em analise.
     */
    private void caminharCentral(No i) {
      if (i != null) {
        if (
          (
            i.elemento.equals("+") ||
            i.elemento.equals("-") ||
            i.elemento.equals("/") ||
            i.elemento.equals("*")
          ) &&
          i.esq.elemento.matches("[0-9]") &&
          i.dir.elemento.matches("[0-9]")
        ) {
          System.out.print("(");
        }

        caminharCentral(i.esq); // Elementos da esquerda.
        // System.out.print(i.elemento + " "); // Conteudo do no.
        System.out.print(i.elemento); // Conteudo do no.
        caminharCentral(i.dir); // Elementos da direita.

        if (
          (
            i.elemento.equals("+") ||
            i.elemento.equals("-") ||
            i.elemento.equals("/") ||
            i.elemento.equals("*")
          ) &&
          i.esq.elemento.matches("[0-9]") &&
          i.dir.elemento.matches("[0-9]")
        ) {
          System.out.print(")");
        }
      }
    }

    /**
     * Metodo publico iterativo para exibir elementos.
     */
    public void caminharPre() {
      System.out.print("[ ");
      caminharPre(raiz);
      System.out.println("]");
    }

    /**
     * Metodo privado recursivo para exibir elementos.
     * @param i No em analise.
     */
    private void caminharPre(No i) {
      if (i != null) {
        System.out.print(i.elemento + " "); // Conteudo do no.
        caminharPre(i.esq); // Elementos da esquerda.
        caminharPre(i.dir); // Elementos da direita.
      }
    }

    /**
     * Metodo publico iterativo para exibir elementos.
     */
    public void caminharPos() {
      System.out.print("[ ");
      caminharPos(raiz);
      System.out.println("]");
    }

    /**
     * Metodo privado recursivo para exibir elementos.
     * @param i No em analise.
     */
    private void caminharPos(No i) {
      if (i != null) {
        caminharPos(i.esq); // Elementos da esquerda.
        caminharPos(i.dir); // Elementos da direita.
        System.out.print(i.elemento + " "); // Conteudo do no.
      }
    }

    /**
     * Metodo publico para inserir elemento.
     * @param elemento Elemento a ser inserido.
     * @return No em analise, alterado ou nao.
     */
    public No inserir(String elemento) {
      raiz = new No(elemento);
      return raiz;
    }

    /**
     * Metodo publico para inserir elemento.
     * @param x Elemento a ser inserido.
     * @param i No em analise.
     * @return No em analise, alterado ou nao.
     * @throws Exception Se o elemento existir.
     */
    public No inserir(String elemento, String elementoPai, String lado)
      throws Exception {
      No i = pesquisar(elementoPai);
      if (i == null) throw new Exception("Erro ao inserir!");

      if (lado.equals("E")) {
        i.esq = new No(elemento);
      } else if (lado.equals("D")) {
        i.dir = new No(elemento);
      } else {
        throw new Exception("Erro ao inserir!");
      }
      return i;
    }

    public String getRaiz() throws Exception {
      return raiz.elemento;
    }
  }

  public static void main(String[] args) throws Exception {
    ArvoreBinaria arvoreBinaria = new ArvoreBinaria();
    Scanner in = new Scanner(System.in);
    String value;
    String[] array = new String[] {};
    int n = in.nextInt();
    in.nextLine();
    for (int i = 0; i < n; i++) {
      // in.nextLine();
      // System.out.println(i);
      value = in.nextLine();
      // raiz
      if (value.length() == 1) {
        arvoreBinaria.inserir(value);
      } else if (value.length() > 1) {
        array = value.split(" ");
        // elemento, pai, lado
        arvoreBinaria.inserir(array[0], array[1], array[2]);
      }
    }
    in.close();

    arvoreBinaria.caminharCentral();
  }
}
/* 
5
+
3 + E
* + D
5 * E
8 * D
*/
