#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0) {
    return 1;
  }
  int *values = malloc((size_t)n * sizeof *values);
  if (values == NULL) {
    return 1;
  }
  for (int i = 0; i < n; ++i) {
    if (scanf("%d", &values[i]) != 1) {
      free(values);
      return 1;
    }
  }

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += values[i];
  }
  printf("%lld\n", sum);
  free(values);
  return 0;
}
