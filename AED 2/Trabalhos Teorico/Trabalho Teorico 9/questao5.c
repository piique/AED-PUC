#include <stdio.h>
#include <stdlib.h>

int _strlen(char *string) {
  int len = 0;
  while (*(string + len) != '\0') {
    len++;
  }
  return len;
}

int strcmp(char *string1, char *string2) {
  int len1 = _strlen(string1);
  int len2 = _strlen(string2);

  if (len1 > len2) {
    return 1;
  } else if (len1 == len2) {
    return 0;
  } else {
    return -1;
  }
}

void strcat(char *string1, char *string2) {
  for (int i = 0; i < _strlen(string2); i++) {
    *(string1 + _strlen(string1)) = *(string2 + i);
  }
}

char *strchr(char *string, int c) {
  for (int i = 0; i < srtlen(string); i++) {
    if (*(string + i) == c) {
      return string + i;
    }
  }
  return NULL;
}

int main() {
  char *string1 = (char *)malloc(1000 * sizeof(char));
  char *string2 = (char *)malloc(10 * sizeof(char));

  *string2 = 'j';
  *(string2 + 1) = 'o';
  *(string2 + 2) = 't';
  *(string2 + 3) = 'a';

  scanf(" %[^\n]s\n", string1);

  printf("String len: %i", _strlen(string1));
  strcat(string1, string2);
  printf("Concatenação: %s", string1);

  free(string1);
  free(string2);

  return 0;
}
