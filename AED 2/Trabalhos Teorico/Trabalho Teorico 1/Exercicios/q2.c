#include <stdio.h>

int main() {
  double a;
  double *p, *q;
  a = 3.14;
  printf("+% f\n", a);
  p = &a;
  *p = 2.718;
  printf("% f\n", a);
  a = 5;
  printf("% f\n", *p);
  p = NULL;
  p = (double *)malloc(sizeof(double));
  *p = 20;
  q = p;
  printf("% f\n", *p);
  printf("% f\n", a);
  free(p);
  printf("% f\n", *q);
}
