#include <stdio.h>

float progressaoAritimetica(float razao, float primeiroTermo, int n);

int main()
{
  //formula PG: a[n] = a[1] * q^(n-1) onde n: posicao, q: razao, a: termo
  float razao = 3, primeiroTermo = 1;
  int n_esimoTermo = 6;
  //PG  = {1, 3, 9, 27, 81, 243...}
  //termos 1, 2, 3,  4,  5,  6 ...

  // printf("\nProgressao geometrica\nDigite a razao: ");
  // scanf("%f", &razao);
  // printf("Digite o primeiro termo: ");
  // scanf("%f", &primeiroTermo);
  // printf("Digite a posicao do termo a ser descoberto: ");
  // scanf("%i", &n_esimoTermo);

  printf("\nResultado: %0.2f", progressaoAritimetica(razao, primeiroTermo, n_esimoTermo));
  return 0;
}

float progressaoAritimetica(float razao, float primeiroTermo, int n)
{
  if (n <= 1)
  {
    return primeiroTermo;
  }
  return razao * progressaoAritimetica(razao, primeiroTermo, --n);
}

// n = 6 return 3 * pg(n = 5)
//                    return 3 * pg(n = 4)
//                                return 3 * pg(n = 3)
//                                           return 3 * pg(n = 2)
//                                                      return 3 * pg(n = 1)
