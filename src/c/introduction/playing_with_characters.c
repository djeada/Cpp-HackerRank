#include <stdio.h>
#include <string.h>

int main(void) {
  char first_line[4];
  char word[102];
  char sentence[102];

  if (fgets(first_line, sizeof first_line, stdin) == NULL ||
      fgets(word, sizeof word, stdin) == NULL ||
      fgets(sentence, sizeof sentence, stdin) == NULL) {
    return 1;
  }

  word[strcspn(word, "\r\n")] = '\0';
  sentence[strcspn(sentence, "\r\n")] = '\0';
  printf("%c\n%s\n%s\n", first_line[0], word, sentence);
  return 0;
}
