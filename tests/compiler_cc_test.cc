#include "compilers/compiler_cc.h"
#ifdef HAVE_STDIO_H
#include <stdio.h>
#else
#include <cstdio>
#endif // HAVE_STDIO_H
#ifdef HAVE_C_ASSERT
#include <assert.h>
#else
#include <cassert>
#endif // HAVE_C_ASSERT
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
#include <cstdlib>
#endif // HAVE_STDLIB_H

int main(int argc, char **argv) {
  assert(argc == 3);
  int expected_result = atoi(argv[2]);
  int compile_result = compile_cc(argv[1]);
  assert(expected_result == compile_result);
  return 0;
}
