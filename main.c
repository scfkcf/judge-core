#include "config.h"
#include "params.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void parse_command_line_flags(int* argc, char*** argv, params_t* params) {
  char *current, *key, *value, *pivot;
  int currentIndex = 1;
  while (currentIndex < *argc) {
    current = (*argv)[currentIndex++];
    if (current[0] != '-') {
      fprintf(stderr, "Can not parse command line flag: %s\n", current);
      exit(1);
    }
    if (strncmp(current, "--", 2) == 0) {
      pivot = strstr(current, "=");
      if (pivot != NULL) {
        *pivot = 0;
        key = current;
        value = pivot + 1;
      } else {
        key = current;
        value = NULL;
      }
    } else {
      key = current;
      value = (*argv)[currentIndex++];
    }
    if (strcmp(key, "--help") == 0 || strcmp(key, "-h") == 0) {
      params->is_help_presented = 1;
    } else if (strcmp(key, "--version") == 0 || strcmp(key, "-v") == 0) {
      params->is_version_presented = 1;
    } else if (strcmp(key, "--lang") == 0 || strcmp(key, "-l") == 0) {
      if (value) {
        params->lang_id = atoi(value);
      }
    } else if (strcmp(key, "--params") == 0 || strcmp(key, "-p") == 0) {
      params->compiler_params = value;
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

