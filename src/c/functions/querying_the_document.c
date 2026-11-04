#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Splitting in place keeps each word in the input buffer.
char ****get_document(char *text) {
  const int paragraph_count = count_parts(text, '\n');
  char ****document = allocate((size_t)paragraph_count + 1, sizeof *document);
  document[paragraph_count] = NULL;

  for (int p = 0; p < paragraph_count; ++p) {
    char *paragraph_text = take_part(&text, '\n');
    const int sentence_count = count_parts(paragraph_text, '.');
    char ***paragraph = allocate((size_t)sentence_count + 1, sizeof *paragraph);
    document[p] = paragraph;
    paragraph[sentence_count] = NULL;

    for (int s = 0; s < sentence_count; ++s) {
      char *sentence_text = take_part(&paragraph_text, '.');
      const int word_count = count_parts(sentence_text, ' ');
      char **sentence = allocate((size_t)word_count, sizeof *sentence);
      paragraph[s] = sentence;
      for (int w = 0; w < word_count; ++w) {
        sentence[w] = take_part(&sentence_text, ' ');
      }
    }
  }

  return document;
}

char ***kth_paragraph(char ****document, int k) {
  return document[k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m) {
  return document[m - 1][k - 1];
}

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document,
                                               int k, int m, int n) {
  return document[n - 1][m - 1][k - 1];
}

static void free_document(char ****document) {
  for (int p = 0; document[p] != NULL; ++p) {
    for (int s = 0; document[p][s] != NULL; ++s) {
      free(document[p][s]);
    }
    free(document[p]);
  }
  free(document);
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

static void print_sentence(char **sentence, int word_count) {
  for (int w = 0; w < word_count; ++w) {
    printf("%s%s", w == 0 ? "" : " ", sentence[w]);
  }
}

int main(void) {
  char text[1005];
  if (!read_document_text(text, sizeof text)) {
    return 1;
  }
  char ****document = get_document(text);

  const int queries = read_int();
  for (int i = 0; i < queries; ++i) {
    const int type = read_int();
    const int k = read_int();
    if (type == 1) {
      char ***paragraph = kth_paragraph(document, k);
      const int sentence_count = read_int();
      for (int s = 0; s < sentence_count; ++s) {
        print_sentence(paragraph[s], read_int());
        putchar('.');
      }
    } else if (type == 2) {
      const int m = read_int();
      print_sentence(kth_sentence_in_mth_paragraph(document, k, m), read_int());
    } else {
      const int m = read_int();
      const int n = read_int();
      fputs(kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n), stdout);
    }
    putchar('\n');
  }

  free_document(document);
  return 0;
}
