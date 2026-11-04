#include <stdio.h>
#include <stdlib.h>

struct shelf {
  int *pages;
  size_t count;
  size_t capacity;
};

static int append_book(struct shelf *shelf, int pages) {
  if (shelf->count == shelf->capacity) {
    const size_t capacity = shelf->capacity == 0 ? 1 : 2 * shelf->capacity;
    int *grown = realloc(shelf->pages, capacity * sizeof *grown);
    if (grown == NULL) {
      return 0;
    }
    shelf->pages = grown;
    shelf->capacity = capacity;
  }
  shelf->pages[shelf->count++] = pages;
  return 1;
}

int main(void) {
  int shelf_count, query_count;
  if (scanf("%d%d", &shelf_count, &query_count) != 2 || shelf_count <= 0) {
    return 1;
  }
  struct shelf *shelves = calloc((size_t)shelf_count, sizeof *shelves);
  if (shelves == NULL) {
    return 1;
  }

  int status = 0;
  for (int q = 0; q < query_count; ++q) {
    int type, index, value;
    if (scanf("%d%d", &type, &index) != 2 ||
        (type != 3 && scanf("%d", &value) != 1)) {
      status = 1;
      break;
    }

    struct shelf *shelf = &shelves[index];
    if (type == 1) {
      if (!append_book(shelf, value)) {
        status = 1;
        break;
      }
    } else if (type == 2) {
      printf("%d\n", shelf->pages[value]);
    } else {
      printf("%zu\n", shelf->count);
    }
  }

  for (int i = 0; i < shelf_count; ++i) {
    free(shelves[i].pages);
  }
  free(shelves);
  return status;
}
