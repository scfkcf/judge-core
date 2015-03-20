#ifndef __COMPILER_H__
#define __COMPILER_H__

#include <ctype.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
#include <cstdlib>
#endif // HAVE_STDLIB_H

#define COMPILE_RESULT_PASS 0
#define COMPILE_RESULT_FORK_ERROR -1
#define COMPILE_RESULT_COMPILE_ERROR 1
#define COMPILE_RESULT_WAIT_PID_ERROR 2
#define COMPILE_RESULT_COMPILER_TIMEOUT 3
#define COMPILE_RESULT_COMPILER_STOPPED 4
#define COMPILE_RESULT_COMPILER_UNKNOWN_STATUS 5

#define BUFF_SIZE 100

int compile(char* params, int (*compiler_return_mapping_function)(size_t));

#endif // __COMPILER_H__
