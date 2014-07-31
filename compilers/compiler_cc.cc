#include "config.h"
#include "compiler_cc.h"
#include "compiler.h"
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
#include <cstdlib>
#endif // HAVE_STDLIB_H

#define GCC_COMPILE_ERROR_EXIT_CODE 1

int gcc_exit_code_mapping(size_t exit_code) {
  if (0 == exit_code) {
    return COMPILE_RESULT_PASS;
  } else if (GCC_COMPILE_ERROR_EXIT_CODE == exit_code) {
    return COMPILE_RESULT_COMPILE_ERROR;
  } else {
    return COMPILE_RESULT_COMPILER_UNKNOWN_STATUS;
  }
}

int compile_cc(char* const source_file_path) {
#if ((OS_TYPE_LINUX) == (OS_TYPE))
  char* const parameters[] =
      {"gcc", "-static", "-w", "-O2", "-DONLINE_JUDGE", source_file_path, NULL};
#else
  char* const parameters[] =
      {"gcc", "-w", "-O2", "-DONLINE_JUDGE", source_file_path, NULL};
#endif
  return compile(parameters, gcc_exit_code_mapping);
}
