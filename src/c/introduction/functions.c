#include <stdio.h>

// Approach 1 (active) scans the four values once.
int max_of_four(int a, int b, int c, int d) {
  const int rest[] = {b, c, d};
  int largest = a;
  for (int i = 0; i < 3; ++i) {
    if (rest[i] > largest) {
      largest = rest[i];
    }
  }
  return largest;
}

// Approach 2 compares two pairs and then their winners.
// Replace the active max_of_four function to use it.
/*
int max_of_four(int a, int b, int c, int d) {
  const int left = a > b ? a : b;
  const int right = c > d ? c : d;
  return left > right ? left : right;
}
*/

int main(void) {
  int a, b, c, d;
  if (scanf("%d%d%d%d", &a, &b, &c, &d) != 4) {
    return 1;
  }
  printf("%d\n", max_of_four(a, b, c, d));
  return 0;
}
