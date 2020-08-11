#include <math.h>
#include <stdio.h>

int main(void) {
  float x1, y1, y2, x2;
  do {
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    printf("% 0.2f", pow(pow((x1 - x2), 2) + pow((y1 - y2), 2), 0.5));
  } while (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0);
}
