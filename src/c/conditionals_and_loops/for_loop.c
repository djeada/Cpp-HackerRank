#include <stdio.h>

int main(void) {
  int first, last;
  if (scanf("%d%d", &first, &last) != 2) {
    return 1;
  }

  static const char *const names[] = {
      "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
  };
  for (int n = first; n <= last; ++n) {
    if (n >= 1 && n <= 9) {
      puts(names[n - 1]);
    } else {
      puts(n % 2 == 0 ? "even" : "odd");
    }
  }
  return 0;
}
