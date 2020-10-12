#include <time.h>

// codigo pase para calculo de tempo gasto pela cpu para realização do código

int main() {
  clock_t start = clock();

  // realização de codigo

  clock_t end = clock();
  double time_elapsed_in_seconds = (end - start) / (double)CLOCKS_PER_SEC;
  return 0;
}
