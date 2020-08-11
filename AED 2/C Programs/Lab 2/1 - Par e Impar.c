#include <stdio.h>

int main(void) {
  int num;
  scanf("%i", &num);

  if (num % 2 == 0) {
    printf("PAR");
  } else {
    printf("IMPAR");
  }

  printf(" e ");

  if (num > 0) {
    printf("POSITIVO");
  } else {
    if (num == 0) {
      printf("NEUTRO");
    } else {
      printf("NEGATIVO");
    }
  }
}
