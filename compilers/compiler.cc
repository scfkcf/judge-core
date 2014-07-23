#include "config.h"
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#else
#ifdef HAVE_SYS_UNISTD_H
#include <sys/unistd.h>
#endif // HAVE_SYS_UNISTD_H
#endif // HAVE_UNISTD_H
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "compiler.h"

int compile(const char* source_file_path, char* const* argv,
    int (*compiler_return_mapping_function)(size_t)) {
  pid_t pid = fork();
  if (pid < 0) {
    return COMPILE_RESULT_FORK_ERROR;
  } else if (pid == 0) {
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
