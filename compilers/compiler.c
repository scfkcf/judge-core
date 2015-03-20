#include "config.h"
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#else
#include <sys/unistd.h>
#endif // HAVE_UNISTD_H
#include <sys/wait.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
#include <cstdlib>
#endif // HAVE_STDLIB_H
#ifdef HAVE_STDIO_H
#include <stdio.h>
#else
#include <cstdio>
#endif // HAVE_STDIO_H
#ifdef HAVE_TYPES_H
#include <types.h>
#else
#include <sys/types.h>
#endif // HAVE_TYPES_H
#include <string.h>
#include "compiler.h"

char* parsed[BUFF_SIZE];

int compile(char* param, int (*compiler_return_mapping_function)(size_t)) {
  /* parse param */
  int index = 1;
  parsed[0] = strtok(param, " ");
  while (parsed[index] = strtok(NULL, " ")) {
    index++;
  }
  parsed[index] = NULL;
  
  pid_t pid = fork();
  if (pid < 0) {
    return COMPILE_RESULT_FORK_ERROR;
  } else if (pid == 0) {
    freopen("compiler_stderr.log", "w", stderr);
    execvp(parsed[0], &parsed);
  } else {
    int status;
    pid_t child_pid = waitpid(pid, &status, WUNTRACED);
    if (child_pid == -1) {
      return COMPILE_RESULT_WAIT_PID_ERROR;
    }
    if (WIFEXITED(status)) {
      size_t exit_code = WEXITSTATUS(status);
      return compiler_return_mapping_function(exit_code);
    } else {
      if (WIFSIGNALED(status)) {
        return COMPILE_RESULT_COMPILER_TIMEOUT;
      } else if (WIFSTOPPED(status)) {
        return COMPILE_RESULT_COMPILER_STOPPED;
      } else {
        return COMPILE_RESULT_COMPILER_UNKNOWN_STATUS;
      }
    }
  }
  return COMPILE_RESULT_COMPILER_UNKNOWN_STATUS;
}
