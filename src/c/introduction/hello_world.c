#include <stdio.h>

int main(void) {
  puts("Hello, World!");
  int ch;
  while ((ch = getchar()) != EOF) {
    putchar(ch);
  }
  return 0;
}
