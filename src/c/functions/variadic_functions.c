#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...) {
  va_list values;
  va_start(values, count);
  int total = 0;
  for (int i = 0; i < count; ++i) {
    total += va_arg(values, int);
  }
  va_end(values);
  return total;
}

int min(int count, ...) {
  va_list values;
  va_start(values, count);
  int smallest = INT_MAX;
  for (int i = 0; i < count; ++i) {
    const int value = va_arg(values, int);
    if (value < smallest) {
      smallest = value;
    }
  }
  va_end(values);
  return smallest;
}

int max(int count, ...) {
  va_list values;
  va_start(values, count);
  int largest = INT_MIN;
  for (int i = 0; i < count; ++i) {
    const int value = va_arg(values, int);
    if (value > largest) {
      largest = value;
    }
  }
  va_end(values);
  return largest;
}

static void report(int correct) {
  puts(correct ? "Correct Answer" : "Wrong Answer");
}

int main(void) {
  int cases;
  if (scanf("%d", &cases) != 1) {
    return 1;
  }

  // Exercise the same three argument counts as the HackerRank driver.
  for (int i = 0; i < cases; ++i) {
    report(sum(3, 4, 9, 2) == 15 && min(3, 4, 9, 2) == 2 &&
           max(3, 4, 9, 2) == 9);
    report(sum(5, 5, 1, 5, 8, 2) == 21 && min(5, 5, 1, 5, 8, 2) == 1 &&
           max(5, 5, 1, 5, 8, 2) == 8);
    report(sum(10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == 55 &&
           min(10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == 1 &&
           max(10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == 10);
  }
  return 0;
}
