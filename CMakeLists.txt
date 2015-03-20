CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)
PROJECT(judge_core C)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
INCLUDE(CMakeVersion.cmake)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# runtime environment
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(OperatingSystem 0)
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    MESSAGE(FATAL_ERROR "judge core is only supported on linux platform.")
ENDIF()

# set project up to use C99 dialect
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
FIND_PACKAGE(C99 REQUIRED)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C99_C_FLAGS}")

# include files check start

INCLUDE(CheckIncludeFiles)
CHECK_INCLUDE_FILES("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILES("sys/unistd.h" HAVE_SYS_UNISTD_H)
IF((NOT HAVE_UNISTD_H) AND (NOT HAVE_SYS_UNISTD_H))
    MESSAGE(FATAL_ERROR "system header file unistd.h and sys/unistd.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("string.h" HAVE_STRING_H)
IF(NOT HAVE_STRING_H)
    MESSAGE(FATAL_ERROR "system header file string.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("types.h" HAVE_TYPES_H)
CHECK_INCLUDE_FILES("sys/types.h" HAVE_SYS_TYPES_H)
IF((NOT HAVE_TYPES_H) AND (NOT HAVE_SYS_TYPES_H))
    MESSAGE(FATAL_ERROR "system header file types.h and sys/types.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("ctype.h" HAVE_CTYPE_H)
IF(NOT HAVE_CTYPE_H)
    MESSAGE(FATAL_ERROR "system header file ctype.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("sys/wait.h" HAVE_SYS_WAIT_H)
IF(NOT HAVE_SYS_WAIT_H)
    MESSAGE(FATAL_ERROR "system header file sys/wait.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("stdlib.h" HAVE_STDLIB_H)
IF(NOT HAVE_STDLIB_H)
    MESSAGE(FATAL_ERROR "system header file stdlib.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("stdio.h" HAVE_STDIO_H)
IF (NOT HAVE_STDIO_H)
    MESSAGE(FATAL_ERROR "system header file stdio.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("assert.h" HAVE_ASSERT_H)
IF(NOT HAVE_ASSERT_H)
    MESSAGE(FATAL_ERROR "system header file assert.h not found.")
ENDIF()

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# include files check end

ENABLE_TESTING()

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/common)
ADD_SUBDIRECTORY("compilers")
ADD_SUBDIRECTORY("tests")
ADD_EXECUTABLE(judge_core ${CMAKE_SOURCE_DIR}/common/params.h main.c)

INCLUDE(CMakeTests)