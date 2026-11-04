#include <stdio.h>
#include <stdlib.h>

typedef struct triangle {
  int a;
  int b;
  int c;
} triangle;

static long double area_key(const triangle *t) {
  const long double a = t->a;
  const long double b = t->b;
  const long double c = t->c;
  // Heron's formula gives this product as 16 times the squared area.
  return (a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c);
}

static int compare_area(const void *a, const void *b) {
  const long double left = area_key(a);
  const long double right = area_key(b);
  return (left > right) - (left < right);
}

void sort_by_area(triangle *triangles, int count) {
  qsort(triangles, (size_t)count, sizeof *triangles, compare_area);
}

int main(void) {
  int count;
  if (scanf("%d", &count) != 1 || count <= 0) {
    return 1;
  }
  triangle *triangles = malloc((size_t)count * sizeof *triangles);
  if (triangles == NULL) {
    return 1;
  }
  for (int i = 0; i < count; ++i) {
    triangle *t = &triangles[i];
    if (scanf("%d%d%d", &t->a, &t->b, &t->c) != 3) {
      free(triangles);
      return 1;
    }
  }

  sort_by_area(triangles, count);
  for (int i = 0; i < count; ++i) {
    const triangle t = triangles[i];
    printf("%d %d %d\n", t.a, t.b, t.c);
  }
  free(triangles);
  return 0;
}
