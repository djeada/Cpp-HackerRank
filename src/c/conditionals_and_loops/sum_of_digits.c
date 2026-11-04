#include <stdio.h>

int main(void) {
  // Approach 1 (active) extracts each base-10 digit with division.
  int n;
  if (scanf("%d", &n) != 1) {
    return 1;
  }
  int sum = 0;
  for (; n > 0; n /= 10) {
    sum += n % 10;
  }

  // Approach 2 reads the digits as characters. Replace the block above.
  /*
  char digits[6];
  if (scanf("%5s", digits) != 1) {
    return 1;
  }
  int sum = 0;
  for (int i = 0; digits[i] != '\0'; ++i) {
    sum += digits[i] - '0';
  }
  */
  printf("%d\n", sum);
  return 0;
}
