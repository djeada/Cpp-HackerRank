#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
  const int sum = *a + *b;
  *b = abs(*a - *b);
  *a = sum;
}

int main(void) {
  int a, b;
  if (scanf("%d%d", &a, &b) != 2) {
    return 1;
  }
  update(&a, &b);
  printf("%d\n%d\n", a, b);
  return 0;
}
