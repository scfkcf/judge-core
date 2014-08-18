INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
ADD_LIBRARY(compilers STATIC "compiler.cc" "compiler_c.cc" "compiler_cc.cc" "compiler_java.cc")
