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

  // Approach 1 (active) reverses the array in place.
  for (int left = 0, right = n - 1; left < right; ++left, --right) {
    const int saved = values[left];
    values[left] = values[right];
    values[right] = saved;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", values[i], i + 1 == n ? '\n' : ' ');
  }

  // Approach 2 prints the array backward. Replace the two loops above.
  /*
  for (int i = n - 1; i >= 0; --i) {
    printf("%d%c", values[i], i == 0 ? '\n' : ' ');
  }
  */

  free(values);
  return 0;
}
