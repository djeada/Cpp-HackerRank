#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1) {
    return 1;
  }

  const int size = 2 * n - 1;
  const int center = n - 1;
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      const int vertical = abs(row - center);
      const int horizontal = abs(col - center);
      const int ring = vertical > horizontal ? vertical : horizontal;
      printf("%d%c", ring + 1, col + 1 == size ? '\n' : ' ');
    }
  }
  return 0;
}
