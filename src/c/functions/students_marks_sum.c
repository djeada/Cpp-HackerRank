#include <stdio.h>
#include <stdlib.h>

int marks_summation(int *marks, int number_of_students, char gender) {
  int total = 0;
  for (int i = gender == 'b' ? 0 : 1; i < number_of_students; i += 2) {
    total += marks[i];
  }
  return total;
}

int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0) {
    return 1;
  }
  int *marks = malloc((size_t)n * sizeof *marks);
  if (marks == NULL) {
    return 1;
  }
  for (int i = 0; i < n; ++i) {
    if (scanf("%d", &marks[i]) != 1) {
      free(marks);
      return 1;
    }
  }

  char gender;
  const int read_gender = scanf(" %c", &gender);
  if (read_gender == 1) {
    printf("%d\n", marks_summation(marks, n, gender));
  }
  free(marks);
  return read_gender != 1;
}
