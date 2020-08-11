public class Main {
    public static int somar(int[] v) {
        int SOMA = 0;
        int n = v.length;

        while (n != 0) {
            SOMA += v[--n];
        }
        return SOMA;
    }

    public static void main(String[] args) {
        int n = 3;
        int v[] = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = 11;
        }
        System.out.println(somar(v));
    }
}
