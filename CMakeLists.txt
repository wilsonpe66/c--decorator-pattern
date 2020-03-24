cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_WARN_FLAGS "-Wall -Wextra -Wpedantic")
set(PROJECT_CXX_FLAGS "${PROJECT_WARN_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE
    "${CMAKE_CXX_FLAGS_RELEASE} ${PROJECT_CXX_FLAGS} -O3 -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${PROJECT_CXX_FLAGS} -g")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/archive")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src/app-lib)

add_executable(decorator-pattern src/decorator-pattern-demo.cpp)
target_link_libraries(decorator-pattern app-lib)

add_executable(decorator-pattern-small src/decorator-pattern-small.cpp)
target_link_libraries(decorator-pattern-small app-lib)

add_custom_target(build-release COMMAND strip bin/* && ls -la bin)
add_dependencies(build-release decorator-pattern decorator-pattern-small)

install(
  TARGETS decorator-pattern decorator-pattern-small
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static)

add_custom_target(
  uninstall
  COMMAND bash -c
          "rm /usr/local/bin/{decorator-pattern,decorator-pattern-small}")
