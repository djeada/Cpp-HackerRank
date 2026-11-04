#include <stdio.h>

int main(void) {
  int counts[10] = {0};
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch >= '0' && ch <= '9') {
      ++counts[ch - '0'];
    }
  }
  for (int i = 0; i < 10; ++i) {
    printf("%d%c", counts[i], i == 9 ? '\n' : ' ');
  }
  return 0;
}
