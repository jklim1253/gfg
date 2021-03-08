cmake_minimum_required(VERSION 3.10)
project(test VERSION 1.0)

set(FILE_SOURCES
  "test_out_container.cpp"
)
set(FILE_HEADERS
  "test.hpp"
)

add_library(${PROJECT_NAME} STATIC
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)