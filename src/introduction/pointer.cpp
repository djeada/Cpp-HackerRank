#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
  int sum = *a + *b;
  int absolut = abs(*a - *b);
  *a = sum;
  *b = absolut;
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;

  if (scanf("%d %d", &a, &b) != 2) {
    return 0;
  }
  update(pa, pb);
  printf("%d\n%d", a, b);

  return 0;
}