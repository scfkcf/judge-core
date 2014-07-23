#include "compiler.h"
#include <stdlib.h>

#define GCC_COMPILE_ERROR_EXIT_CODE 1

int gcc_exit_code_mapping(size_t exit_code) {
  if (GCC_COMPILE_ERROR_EXIT_CODE == exit_code) {
    return COMPILE_RESULT_COMPILE_ERROR;
  } else {
    return COMPILE_RESULT_COMPILER_UNKNOWN_STATUS;
  }
}

int compile_cc(const char* source_file_path) {
  char* const* parameters =
      {"gcc", "gcc", "-static", "-w", "-O2", "-DONLINE_JUDGE", source_file_path};
  return compile(parameters, gcc_exit_code_mapping);
}
