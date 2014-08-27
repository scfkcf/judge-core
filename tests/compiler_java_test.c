#include "compilers/compiler_java.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  assert(argc == 3);
  int expected_result = atoi(argv[2]);
  int compile_result = compile_java(argv[1]);
  assert(expected_result == compile_result);
  return 0;
}
