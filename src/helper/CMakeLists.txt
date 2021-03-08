cmake_minimum_required(VERSION 3.10)
project(helper VERSION 1.0)

set(FILE_SOURCES
  "version.cpp"
  "trim.cpp"
)
set(FILE_HEADERS
  "helper.hpp"
  "out_container.hpp"
)

add_library(${PROJECT_NAME} STATIC
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)