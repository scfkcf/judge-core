#ifndef __COMPILER_H__
#define __COMPILER_H__

#include <ctype.h>

#define COMPILE_RESULT_PASS 0
#define COMPILE_RESULT_FORK_ERROR -1
#define COMPILE_RESULT_COMPILE_ERROR 1
#define COMPILE_RESULT_WAIT_PID_ERROR 2
#define COMPILE_RESULT_COMPILER_TIMEOUT 3
#define COMPILE_RESULT_COMPILER_STOPPED 4
#define COMPILE_RESULT_COMPILER_UNKNOWN_STATUS 5

int compile(char* const* argv, int (*compiler_return_mapping_function)(size_t));

#endif // __COMPILER_H__
