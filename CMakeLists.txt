CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(VERSION "0.0.20140823")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# runtime environment
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(OperatingSystem 0)
ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    SET(OperatingSystem 1)
else(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    MESSAGE(FATAL_ERROR "judge core is only supported on mac os or linux platform.")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# include files check start

INCLUDE(CheckIncludeFiles)
CHECK_INCLUDE_FILES("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILES("sys/unistd.h" HAVE_SYS_UNISTD_H)
IF ((NOT HAVE_UNISTD_H) AND (NOT HAVE_SYS_UNISTD_H))
    MESSAGE(FATAL_ERROR "system header file unistd.h and sys/unistd.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("string.h" HAVE_STRING_H)
IF (NOT HAVE_STRING_H)
    MESSAGE(FATAL_ERROR "system header file string.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("ctype.h" HAVE_CTYPE_H)
IF (NOT HAVE_CTYPE_H)
    MESSAGE(FATAL_ERROR "system header file ctype.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("sys/wait.h" HAVE_SYS_WAIT_H)
IF (NOT HAVE_SYS_WAIT_H)
    MESSAGE(FATAL_ERROR "system header file sys/wait.h not found.")
ENDIF()

CHECK_INCLUDE_FILES("stdlib.h" HAVE_STDLIB_H)
CHECK_INCLUDE_FILES("cstdlib" HAVE_C_STDLIB)
IF ((NOT HAVE_STDLIB_H) AND (NOT HAVE_C_STDLIB))
    MESSAGE(FATAL_ERROR "system header file stdlib.h and cstdlib not found.")
ENDIF()

CHECK_INCLUDE_FILES("stdio.h" HAVE_STDIO_H)
CHECK_INCLUDE_FILES("cstdio" HAVE_C_STDIO)
IF ((NOT HAVE_STDIO_H) AND (NOT HAVE_C_STDIO))
    MESSAGE(FATAL_ERROR "system header file stdio.h and cstdio not found.")
ENDIF()

CHECK_INCLUDE_FILES("assert.h" HAVE_ASSERT_H)
CHECK_INCLUDE_FILES("cassert" HAVE_C_ASSERT)
IF ((NOT HAVE_ASSERT_H) AND (NOT HAVE_C_ASSERT))
    MESSAGE(FATAL_ERROR "system header file assert.h and cassert not found.")
ENDIF()

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# include files check end

ENABLE_TESTING()

ADD_DEFINITIONS(-std=gnu++0x)
ADD_SUBDIRECTORY("compilers")
ADD_SUBDIRECTORY("tests")
ADD_EXECUTABLE(judge_core "main.cc")

# tests for C compiler
MACRO(add_compiler_c_test source_file result)
    ADD_TEST(
        NAME add_compiler_c_test[${source_file}]
        COMMAND compiler_c_test ${source_file} ${result}
    )
ENDMACRO(add_compiler_c_test)

add_compiler_c_test(${CMAKE_SOURCE_DIR}/test_resources/test_pass.c 0)
add_compiler_c_test(${CMAKE_SOURCE_DIR}/test_resources/test_compile_error.c 1)

# tests for C++ compiler
MACRO(add_compiler_cc_test source_file result)
    ADD_TEST(
        NAME add_compiler_cc_test[${source_file}]
        COMMAND compiler_cc_test ${source_file} ${result}
    )
ENDMACRO(add_compiler_cc_test)

add_compiler_cc_test(${CMAKE_SOURCE_DIR}/test_resources/test_pass.cc 0)
add_compiler_cc_test(${CMAKE_SOURCE_DIR}/test_resources/test_compile_error.cc 1)

# tests for Java compiler
MACRO(add_compiler_java_test source_file result)
    ADD_TEST(
        NAME add_compiler_java_test[${source_file}]
        COMMAND compiler_java_test ${source_file} ${result}
    )
ENDMACRO(add_compiler_java_test)

add_compiler_java_test(${CMAKE_SOURCE_DIR}/test_resources/test_pass.java 0)
add_compiler_java_test(${CMAKE_SOURCE_DIR}/test_resources/test_compile_error.java 1)
