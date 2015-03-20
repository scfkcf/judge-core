#include "config.h"
#include "compiler_java.h"
#include "compiler.h"
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
#include <cstdlib>
#endif // HAVE_STDLIB_H

#define JAVAC_EXIT_OK 0
#define JAVAC_EXIT_ERROR 1

int javac_exit_code_mapping(size_t exit_code) {
  if (JAVAC_EXIT_OK == exit_code) {
    return COMPILE_RESULT_PASS;
  } else if (JAVAC_EXIT_ERROR == exit_code) {
    return COMPILE_RESULT_COMPILE_ERROR;
  } else {
    return COMPILE_RESULT_COMPILER_UNKNOWN_STATUS;
  }
}

int compile_java(char* const source_file_path, const char* param) {
  char wrapped_param[BUFF_SIZE];
  sprintf(wrapped_param, "javac %s %s", source_file_path, param);
  return compile(wrapped_param, javac_exit_code_mapping);
}
