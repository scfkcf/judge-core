#include "compilers/compiler_c.h"
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
  int result = atoi(argv[2]);
  printf("%d\n", compile_c(argv[1]));
  assert(result == compile_c(argv[1]));
  return 0;
}
