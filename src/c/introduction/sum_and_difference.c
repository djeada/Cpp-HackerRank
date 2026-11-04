#include <stdio.h>

int main(void) {
  int a, b;
  float x, y;
  if (scanf("%d%d%f%f", &a, &b, &x, &y) != 4) {
    return 1;
  }

  printf("%d %d\n%.1f %.1f\n", a + b, a - b, x + y, x - y);
  return 0;
}
