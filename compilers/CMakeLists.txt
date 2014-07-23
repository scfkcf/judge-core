INCLUDE(CheckIncludeFiles)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
CHECK_INCLUDE_FILES("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILES("sys/unistd.h" HAVE_SYS_UNISTD_H)
CHECK_INCLUDE_FILES("ctype.h" HAVE_CTYPE_H)
CHECK_INCLUDE_FILES("sys/wait.h" HAVE_SYS_WAIT_H)
CHECK_INCLUDE_FILES("stdlib.h" HAVE_STDLIB_H)

IF ((NOT HAVE_UNISTD_H) AND (NOT HAVE_SYS_UNISTD_H))
    MESSAGE(FATAL_ERROR "system header file unistd.h and sys/unistd.h not found.")
ENDIF()

IF (NOT HAVE_CTYPE_H)
    MESSAGE(FATAL_ERROR "system header file ctype.h not found.")
ENDIF()

IF (NOT HAVE_SYS_WAIT_H)
    MESSAGE(FATAL_ERROR "system header file sys/wait.h not found.")
ENDIF()

IF (NOT HAVE_STDLIB_H)
    MESSAGE(FATAL_ERROR "system header file stdlib.h not found.")
ENDIF()

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_library(compilers STATIC "compiler.cc")
