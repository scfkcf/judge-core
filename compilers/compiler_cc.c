#include "config.h"
#include "compiler_cc.h"
#include "compiler.h"
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
#include <cstdlib>
#endif // HAVE_STDLIB_H

#define GPP_COMPILE_ERROR_EXIT_CODE 1

int gpp_exit_code_mapping(size_t exit_code) {
  if (0 == exit_code) {
    return COMPILE_RESULT_PASS;
  } else if (GPP_COMPILE_ERROR_EXIT_CODE == exit_code) {
    return COMPILE_RESULT_COMPILE_ERROR;
  } else {
    return COMPILE_RESULT_COMPILER_UNKNOWN_STATUS;
  }
}

int compile_cc(char* const source_file_path) {
  char* const parameters[] =
      {"g++", "-static", "-w", "-O2", "-lm", "-DONLINE_JUDGE", source_file_path, NULL};
  return compile(parameters, gpp_exit_code_mapping);
}
