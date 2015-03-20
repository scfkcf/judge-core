# tests for C compiler
MACRO(ADD_COMPILER_C_TEST source_file result)
    ADD_TEST(
        NAME add_compiler_c_test[${source_file}]
        COMMAND compiler_c_test ${source_file} ${result}
    )
ENDMACRO(ADD_COMPILER_C_TEST)

ADD_COMPILER_C_TEST(${CMAKE_SOURCE_DIR}/test_resources/test_pass.c 0)
ADD_COMPILER_C_TEST(${CMAKE_SOURCE_DIR}/test_resources/test_compile_error.c 1)

# tests for C++ compiler
MACRO(ADD_COMPILER_CC_TEST source_file result)
    ADD_TEST(
        NAME add_compiler_cc_test[${source_file}]
        COMMAND compiler_cc_test ${source_file} ${result}
    )
ENDMACRO(ADD_COMPILER_CC_TEST)

ADD_COMPILER_CC_TEST(${CMAKE_SOURCE_DIR}/test_resources/test_pass.cc 0)
ADD_COMPILER_CC_TEST(${CMAKE_SOURCE_DIR}/test_resources/test_compile_error.cc 1)

# tests for Java compiler
MACRO(ADD_COMPILER_JAVA_TEST source_file result)
    ADD_TEST(
        NAME add_compiler_java_test[${source_file}]
        COMMAND compiler_java_test ${source_file} ${result}
    )
ENDMACRO(ADD_COMPILER_JAVA_TEST)

ADD_COMPILER_JAVA_TEST(${CMAKE_SOURCE_DIR}/test_resources/test_pass.java 0)
ADD_COMPILER_JAVA_TEST(${CMAKE_SOURCE_DIR}/test_resources/test_compile_error.java 1)
