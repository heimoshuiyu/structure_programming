/*
 * Programmer: Walter
 * Student ID: 1930006025
 * Date: 2020.12.7
 * Task no: Week_11_Task_1
 * write a function stringCopy to copy the string
 */

#include <stdio.h>

char *stringCopy(char *dest, char *src);

int main() {
  char str1[20], str2[20];
  scanf("%s", str1);
  stringCopy(str2, str1);
  printf("%s\n", str2);
  return 0;
}

char *stringCopy(char *dest, char *src) {
  for (; *src != '\0'; src++) {
    *(dest++) = *src;
  }
  *dest = '\0';
  return dest;
}
