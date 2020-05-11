#include <stdio.h>

int multiplica(int n1, int n2);

int main()
{
  int n1 = 3, n2 = 4;

  // printf("Digite 2 numeros: ");
  // scanf("%f %f", &n1, &n2);

  printf("\nResultado da multiplica de %i por %i eh: %i", n1, n2, multiplica(n1, n2));
  return 0;
}

int multiplica(int a, int b)
{

  if (a == 0 || b == 0)
  {
    return 0;
  }
  else if (a > 0 && b > 1)
  {
    return a + multiplica(a, --b);
  }
}
// a = 20 - b = 4 --- return (40, 3) = 80
//                            return(60, 2) = 80
//                                return(80, 1) = 80
