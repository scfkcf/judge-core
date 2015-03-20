#include "compilers/compiler_cc.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  assert(argc == 3);
  int expected_result = atoi(argv[2]);
  int compile_result = compile_cc(argv[1], "-static -w -O2 -lm -DONLINE_JUDGE");
  assert(expected_result == compile_result);
  return 0;
}
