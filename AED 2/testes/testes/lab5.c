#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool verificaString(char *str) {
  int count = 0;
  for (int i = 0; i <= strlen(str); i++) {
    if ((str[i] == ')') && count == 0) {
      return false;
    } else if (str[i] == '(') {
      count++;
    } else if (str[i] == ')') {
      count--;
    }
  }

  return count == 0;
}

int main(void) {
  int n;

  scanf("%i\n", &n);

  for (int x = 0; x < n; x++) {
    char str[100];
    scanf("%s\n", str);
    fflush(stdin);
    if (verificaString(str)) {
      printf("correct\n");
    } else {
      printf("incorrect\n");
    }
  }

  return 0;
}
