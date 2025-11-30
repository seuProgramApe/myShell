#include <string.h>
#include <stdlib.h>

#include "io_util.h"
#include "error_handle.h"
#include "string_util.h"


void input_str(FILE* infile, char* dest, int char_limit, const char* prompt) {
  if (dest == NULL || char_limit == 0)
    return;

  memset(dest, NIL_CHAR, char_limit * sizeof(char)); // fill dest with '\0'
  char *trimmed = NULL; 
  fflush(infile); // clear input buffer (infile)

  do { // keep reading input until a non-empty input is obtained
    if (prompt != NULL && dest[0] == NIL_CHAR)
      fputs(prompt, stdout); // output prompt

    if (fgets(dest, char_limit, infile) == NULL) { // fgets() returns dest (char*) or NULL
      puts("\nexit"); // receive EOF, terminate the process
      exit(receivedEOF);
    }
    trimmed = trim_str(dest, strlen(dest) + 1);
  } while (trimmed[0] == NIL_CHAR);

  if (dest != trimmed) {
    strcpy(dest, trimmed);
    char *end = dest;
    while (*end++ != NIL_CHAR);
    memset(end, NIL_CHAR, (dest + char_limit) - end);
  }
}
