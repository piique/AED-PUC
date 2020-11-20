#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *somente_consoante(char *v, int n) {
  char *aux = malloc(n * sizeof(char));
  int index = 0;
  for (int j = 0; j < n; j++) {
    if (v[j] != ' ' && v[j] != '\r' && v[j] != 'A' && v[j] != 'a' && v[j] != 'E' && v[j] != 'e' && v[j] != 'I' && v[j] != 'i' && v[j] != 'O' && v[j] != 'o' && v[j] != 'U' && v[j] != 'u' && ((v[j] >= 65 && v[j] <= 90) || (v[j] >= 97 && v[j] <= 122))) {
      aux[index] = v[j];
      index++;
    }
  }

  printf("%s", aux);
  return 0;
}

int main(void) {
  char *p;
  int i, elementos;

  p = (char *)(malloc(1000 * sizeof(char)));
  scanf(" %[^\n]s\n", p);

  elementos = strlen(p);
  somente_consoante(p, elementos);
  free(p);
  return 0;
}