#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word {
  char *data;
};

struct sentence {
  struct word *data;
  int word_count;
};

struct paragraph {
  struct sentence *data;
  int sentence_count;
};

struct document {
  struct paragraph *data;
  int paragraph_count;
};

static void *allocate(size_t count, size_t size) {
  void *data = calloc(count, size);
  if (data == NULL && count != 0) {
    exit(EXIT_FAILURE);
  }
  return data;
}

static int count_parts(const char *text, char delimiter) {
  int count = *text != '\0';
  for (; *text != '\0'; ++text) {
    if (*text == delimiter && text[1] != '\0') {
      ++count;
    }
  }
  return count;
}

static char *take_part(char **remaining, char delimiter) {
  char *part = *remaining;
  char *end = strchr(part, delimiter);
  if (end != NULL) {
    *end = '\0';
    *remaining = end + 1;
  }
  return part;
}

static struct sentence parse_sentence(char *text) {
  const int count = count_parts(text, ' ');
  struct sentence sentence = {
      allocate((size_t)count, sizeof(struct word)), count
  };
  for (int i = 0; i < count; ++i) {
    sentence.data[i].data = take_part(&text, ' ');
  }
  return sentence;
}

static struct paragraph parse_paragraph(char *text) {
  const int count = count_parts(text, '.');
  struct paragraph paragraph = {
      allocate((size_t)count, sizeof(struct sentence)), count
  };
  for (int i = 0; i < count; ++i) {
    paragraph.data[i] = parse_sentence(take_part(&text, '.'));
  }
  return paragraph;
}

// Each word points into the input buffer, which the caller keeps alive.
struct document get_document(char *text) {
  const int count = count_parts(text, '\n');
  struct document document = {
      allocate((size_t)count, sizeof(struct paragraph)), count
  };
  for (int i = 0; i < count; ++i) {
    document.data[i] = parse_paragraph(take_part(&text, '\n'));
  }
  return document;
}

struct paragraph kth_paragraph(struct document document, int k) {
  return document.data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document document,
                                               int k, int m) {
  return document.data[m - 1].data[k - 1];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document document,
                                                     int k, int m, int n) {
  return document.data[n - 1].data[m - 1].data[k - 1];
}

static void free_document(struct document document) {
  for (int p = 0; p < document.paragraph_count; ++p) {
    struct paragraph paragraph = document.data[p];
    for (int s = 0; s < paragraph.sentence_count; ++s) {
      free(paragraph.data[s].data);
    }
    free(paragraph.data);
  }
  free(document.data);
}

static int read_document_text(char *text, size_t capacity) {
  int paragraphs;
  if (scanf("%d ", &paragraphs) != 1 || paragraphs < 1) {
    return 0;
  }

  size_t length = 0;
  for (int i = 0; i < paragraphs; ++i) {
    if (capacity - length < 2 ||
        fgets(text + length, (int)(capacity - length), stdin) == NULL) {
      return 0;
    }
    length += strcspn(text + length, "\r\n");
    if (i + 1 < paragraphs) {
      text[length++] = '\n';
    }
  }
  text[length] = '\0';
  return 1;
}

static int read_int(void) {
  int value;
  if (scanf("%d", &value) != 1) {
    exit(EXIT_FAILURE);
  }
  return value;
}

static void print_sentence(struct sentence sentence) {
  for (int w = 0; w < sentence.word_count; ++w) {
    printf("%s%s", w == 0 ? "" : " ", sentence.data[w].data);
  }
}

int main(void) {
  char text[1005];
  if (!read_document_text(text, sizeof text)) {
    return 1;
  }
  struct document document = get_document(text);

  const int queries = read_int();
  for (int i = 0; i < queries; ++i) {
    const int type = read_int();
    const int k = read_int();
    if (type == 1) {
      const struct paragraph paragraph = kth_paragraph(document, k);
      for (int s = 0; s < paragraph.sentence_count; ++s) {
        print_sentence(paragraph.data[s]);
        putchar('.');
      }
    } else if (type == 2) {
      const int m = read_int();
      print_sentence(kth_sentence_in_mth_paragraph(document, k, m));
    } else {
      const int m = read_int();
      const int n = read_int();
      const struct word word =
          kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
      fputs(word.data, stdout);
    }
    putchar('\n');
  }

  free_document(document);
  return 0;
}
