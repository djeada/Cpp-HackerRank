#include <stdio.h>

void calculate_the_maximum(int n, int k) {
  int best_and = 0;
  int best_or = 0;
  int best_xor = 0;
  for (int a = 1; a < n; ++a) {
    for (int b = a + 1; b <= n; ++b) {
      const int and_value = a & b;
      const int or_value = a | b;
      const int xor_value = a ^ b;
      if (and_value < k && and_value > best_and) {
        best_and = and_value;
      }
      if (or_value < k && or_value > best_or) {
        best_or = or_value;
      }
      if (xor_value < k && xor_value > best_xor) {
        best_xor = xor_value;
      }
    }
  }
  printf("%d\n%d\n%d\n", best_and, best_or, best_xor);
}

int main(void) {
  int n, k;
  if (scanf("%d%d", &n, &k) != 2) {
    return 1;
  }
  calculate_the_maximum(n, k);
  return 0;
}
