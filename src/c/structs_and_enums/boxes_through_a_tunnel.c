#include <stdio.h>

#define MAX_HEIGHT 41

typedef struct box {
  int length;
  int width;
  int height;
} box;

int get_volume(box b) {
  return b.length * b.width * b.height;
}

int is_lower_than_max_height(box b) {
  return b.height < MAX_HEIGHT;
}

int main(void) {
  int count;
  if (scanf("%d", &count) != 1) {
    return 1;
  }
  for (int i = 0; i < count; ++i) {
    box b;
    if (scanf("%d%d%d", &b.length, &b.width, &b.height) != 3) {
      return 1;
    }
    if (is_lower_than_max_height(b)) {
      printf("%d\n", get_volume(b));
    }
  }
  return 0;
}
