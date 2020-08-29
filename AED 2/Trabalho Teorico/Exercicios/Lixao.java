class Lixao {
  public void mostraMaiorEMenor(int v[], int x) {
    int maior = v[0];
    int menor = v[0];

    for (int i = 0; i < v.length; i++) {
      if (v[i] > maior)
        maior = v[i];
      else if (v[i] < menor)
        menor = v[i];
    }
    System.out.println("Maior: " + maior);
    System.out.println("Menor: " + menor);
  }
}
