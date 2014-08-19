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

int compile_java(char* const source_file_path) {
  char* const parameters[] = 
    {"javac", source_file_path, "-d", ".", NULL};
  return compile(parameters, javac_exit_code_mapping);
}
