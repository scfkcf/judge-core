#include "config.h"
#include "params.h"
#include <string.h>
#include <stdio.h>

void parse_command_line_flags(int* argc, char*** argv, params_t* params) {
  for (int i = 1; i < *argc; i++) {
    if ((*argv)[i][0] != '-') {
      continue;
    }
    if (strcmp((*argv)[i], "--help") == 0 || strcmp((*argv)[i], "-h") == 0) {
      params->is_help_presented = 1;
    } else if (strcmp((*argv)[i], "--version") == 0 || strcmp((*argv)[i], "-v") == 0) {
      params->is_version_presented = 1;
    }
  }
}

int main(int argc, char** argv) {
  params_t params;
  memset(&params, 0, sizeof(params));
  parse_command_line_flags(&argc, &argv, &params);
  
  /* help and version */
  if (params.is_help_presented) {
    fprintf(stderr, USAGE_MESSAGE, PROJECT_NAME);
    return 0;
  }
  if (params.is_version_presented) {
    printf("%s %s\n", PROJECT_NAME, VERSION);
    return 0;
  }

  return 0;
}

