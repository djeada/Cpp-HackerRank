#include <stdio.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1) {
    return 1;
  }

  static const char *const names[] = {
      "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
  };
  if (n >= 1 && n <= 9) {
    puts(names[n - 1]);
  } else {
    puts("Greater than 9");
  }
  return 0;
}
