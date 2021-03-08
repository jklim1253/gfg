cmake_minimum_required(VERSION 3.10)

set(FILE_SOURCES
  "main.cpp"
)
set(FILE_HEADERS
)

add_subdirectory(helper)
add_subdirectory(test)

add_executable(${CMAKE_PROJECT_NAME}
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE helper)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE test)