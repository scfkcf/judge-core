#include "config.h"
#include <string.h>
#include <stdio.h>

#define PARSE_RESULT_RETUENED 0
#define PARSE_RESULT_EXITED 1
#define USAGE_MESSAGE "usage: %s [-h] [-v]\n\ncompile and run customized code in sandbox and verify the problem result with standard output.\n\noptional arguments:\n  -h, --help\t\tshow this help message and exit\n  -v, --version\t\tprint the version number of judge_core and exit\n"

int parse_command_line_flags(int* argc, char*** argv) {
  for (int i = 1; i < *argc; i++) {
    if ((*argv)[i][0] != '-') {
      continue;
    }
    if (strcmp((*argv)[i], "--help") == 0 || strcmp((*argv)[i], "-h") == 0) {
      fprintf(stderr, USAGE_MESSAGE, (*argv)[0]);
      return PARSE_RESULT_EXITED;
    } else if (strcmp((*argv)[i], "--version") == 0 || strcmp((*argv)[i], "-v") == 0) {
      printf("%s %s\n", (*argv)[0], VERSION);
      return PARSE_RESULT_EXITED;
    }
  }
  return PARSE_RESULT_RETUENED;
}

int main(int argc, char** argv) {
  if (parse_command_line_flags(&argc, &argv) == PARSE_RESULT_EXITED) {
    return 0;
  }
  return 0;
}

