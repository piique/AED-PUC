#include <ctype.h>
#include <stdio.h>
#include <string.h>

// preenche toda a string com espacos vazios
void zeraString(char v[]) {
  for (int i = 0; i < 200; i++) {
    v[i] = '.';
  }
}

int main(void) {
  int N, count = 0, aux[26], maior;
  char v[200];

  scanf("%i", &N);
  setbuf(stdin, NULL);

  for (int i = 0; i < N; i++) {
    v[0] = '\0';
    scanf("%[^\n]s", v);
    setbuf(stdin, NULL);
    printf("Recebeu: %s ", v);
    printf("De tamanho: %i\n", strlen(v));
  }
}
