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
#include "compiler.h"

int compile(char* const* argv, int (*compiler_return_mapping_function)(size_t)) {
  pid_t pid = fork();
  if (pid < 0) {
    return COMPILE_RESULT_FORK_ERROR;
  } else if (pid == 0) {
    freopen("compiler_stderr.log", "w", stderr);
    execvp(argv[0], argv);
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
