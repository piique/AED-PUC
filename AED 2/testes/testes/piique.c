#include <psapi.h>
#include <stdio.h>
#include <time.h>
#include <winbase.h>
#include <windows.h>

double get_memory_used_MB() {
  PROCESS_MEMORY_COUNTERS info;
  GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
  return (double)info.PeakWorkingSetSize / (1024 * 1024);
}

long long int fib(int n) {
  if (n < 2) return n;
  return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[]) {
  clock_t start_time, end_time;
  double cpu_time_used, memory_used;
  size_t peakSize;

  start_time = clock();

  int *vetor = NULL, i = 1;

  while (true) {
    long long int tam = fib(i++);
    printf("%d\n", tam);

    vetor = (int *)malloc(tam * sizeof(int));

    if (vetor == NULL) break;

    free(vetor);
  }

  end_time = clock();
  cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

  memory_used = get_memory_used_MB();

  printf("Tempo: %0.2f segundos - Memoria: %0.2f MB\n", cpu_time_used, memory_used);

  return 0;
}
