#include <stdio.h>

// Approach 1 (active) advances the recurrence recursively.
int find_nth_term(int n, int a, int b, int c) {
  if (n == 1) {
    return a;
  }
  if (n == 2) {
    return b;
  }
  if (n == 3) {
    return c;
  }
  return find_nth_term(n - 1, b, c, a + b + c);
}

// Approach 2 uses a loop and constant stack space. Replace the function above.
/*
int find_nth_term(int n, int a, int b, int c) {
  for (; n > 3; --n) {
    const int next = a + b + c;
    a = b;
    b = c;
    c = next;
  }
  if (n == 1) {
    return a;
  }
  return n == 2 ? b : c;
}
*/

int main(void) {
  int n, a, b, c;
  if (scanf("%d%d%d%d", &n, &a, &b, &c) != 4 || n < 1) {
    return 1;
  }
  printf("%d\n", find_nth_term(n, a, b, c));
  return 0;
}
