#include "config.h"
#include "compiler_c.h"
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

int compile_c(char* const source_file_path, const char* param) {
  char wrapped_param[BUFF_SIZE];
  sprintf(wrapped_param, "gcc %s %s", param, source_file_path);
  return compile(wrapped_param, gcc_exit_code_mapping);
}
