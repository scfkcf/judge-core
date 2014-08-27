INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
ADD_LIBRARY(compilers STATIC "compiler.c" "compiler_c.c" "compiler_cc.c" "compiler_java.c")
