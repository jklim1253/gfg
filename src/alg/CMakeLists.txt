cmake_minimum_required(VERSION 3.10)
project(alg VERSION 1.0)

set(FILE_SOURCES
  "version.cpp"
  "shuffle/shuffle.cpp"
  "search/search_linear.cpp"
  "search/search_binary.cpp"
  "search/search_jump.cpp"
)
set(FILE_HEADERS
  "alg.hpp"
  "shuffle/shuffle.hpp"
  "search/search.hpp"
)

add_library(${PROJECT_NAME}
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE helper)