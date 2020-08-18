#include <stdio.h>
#include <string.h>:

int main(void) {
  char v[1000], aux;

  scanf(" %[^\n]s", &v);
  criptografaString(v, 0, strlen(v));
  return 0;
}

void criptografaString(char v[], int i, int len) {
  if (i < len) {
    if (v[i] == 'F' && v[i + 1] == 'I' && v[i + 2] == 'M') {
      return 0;
    }
    if ((v[i] >= 65 && v[i] <= 87) || (v[i] >= 97 && v[i] <= 119))
      printf("%c", v[i] + 3);
    else {
      printf(" ");
    }

    if ((v[i] >= 120 && v[i] <= 122) || (v[i] >= 88 && v[i] <= 90)) {
      if (v[i] == 'X') {
        printf("A");
      } else if (v[i] == 'x') {
        printf("a");
      } else if (v[i] == 'Y') {
        printf("B");
      } else if (v[i] == 'y') {
        printf("b");
      } else if (v[i] == 'Z') {
        printf("B");
      } else if (v[i] == 'z') {
        printf("b");
      }
    }
    criptografaString(v, ++i, len);
  }
}
