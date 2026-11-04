#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  // Approach 1 (active) prints tokens as they arrive using constant space.
  bool in_word = false;
  int ch;
  while ((ch = getchar()) != EOF) {
    if (isspace(ch)) {
      if (in_word) {
        putchar('\n');
        in_word = false;
      }
    } else {
      putchar(ch);
      in_word = true;
    }
  }
  if (in_word) {
    putchar('\n');
  }

  // Approach 2 tokenizes the buffered line. Replace the streaming code above.
  /*
  char sentence[1002];
  if (fgets(sentence, sizeof sentence, stdin) != NULL) {
    const char *delimiters = " \t\r\n";
    for (char *word = strtok(sentence, delimiters); word != NULL;
         word = strtok(NULL, delimiters)) {
      puts(word);
    }
  }
  */
  return 0;
}
