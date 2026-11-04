#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap_strings(char **a, char **b) {
  char *saved = *a;
  *a = *b;
  *b = saved;
}

int next_permutation(int count, char **strings) {
  int pivot = count - 2;
  while (pivot >= 0 && strcmp(strings[pivot], strings[pivot + 1]) >= 0) {
    --pivot;
  }
  if (pivot < 0) {
    return 0;
  }

  // Increase the rightmost possible position, then minimize its suffix.
  int successor = count - 1;
  while (strcmp(strings[pivot], strings[successor]) >= 0) {
    --successor;
  }
  swap_strings(&strings[pivot], &strings[successor]);
  for (int left = pivot + 1, right = count - 1; left < right;
       ++left, --right) {
    swap_strings(&strings[left], &strings[right]);
  }
  return 1;
}

static char **read_strings(int count) {
  char **strings = calloc((size_t)count, sizeof *strings);
  if (strings == NULL) {
    return NULL;
  }
  for (int i = 0; i < count; ++i) {
    char word[2501];
    if (scanf("%2500s", word) == 1) {
      const size_t size = strlen(word) + 1;
      strings[i] = malloc(size);
      if (strings[i] != NULL) {
        memcpy(strings[i], word, size);
        continue;
      }
    }
    for (int j = 0; j < i; ++j) {
      free(strings[j]);
    }
    free(strings);
    return NULL;
  }
  return strings;
}

int main(void) {
  int count;
  if (scanf("%d", &count) != 1 || count <= 0) {
    return 1;
  }
  char **strings = read_strings(count);
  if (strings == NULL) {
    return 1;
  }

  do {
    for (int i = 0; i < count; ++i) {
      printf("%s%c", strings[i], i + 1 == count ? '\n' : ' ');
    }
  } while (next_permutation(count, strings));

  for (int i = 0; i < count; ++i) {
    free(strings[i]);
  }
  free(strings);
  return 0;
}
