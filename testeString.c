#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  int N, count = 0, aux[26], maior;
  char v[200];

  scanf("%i", &N);
  setbuf(stdin, NULL);
  // scanf("%[a-z A-Z]s", v);
  gets(v);
  printf("Valor lido: %s\n", v);

  return 0;
}

// funcionou isso uma vez
// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     int N, count = 0, aux[26], maior;
//     char v[200];

//     scanf("%i\n", &N);
//     fflush(stdin);
//     scanf("%[^\n]s", v);
//     // gets(v);
//     printf("Valor lido: %s", v);

//     return 0;
// }

// mostrar para o prof
// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int main(void) {
//   int N, count = 0, aux[26], maior;
//   char v[200];

//   scanf("%i", &N);
//   setbuf(stdin, NULL);

//   for (int i = 0; i < N; i++) {
//     v[0] = '\0';
//     scanf("%[^\n]s", v);
//     setbuf(stdin, NULL);
//     printf("Recebeu: %s\n", v);
//   }
// }
