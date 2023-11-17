cmake_minimum_required(VERSION 3.22.1)
project(bchain VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-O0")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wextra")
set(CMAKE_CXX_FLAGS "-Werror")
set(CMAKE_CXX_FLAGS "-pedantic")
set(CMAKE_CXX_FLAGS "-m64")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_MODULE_PATH)

find_package(OpenSSL REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
enable_testing()
  
include_directories(src)
  
add_executable(bchain_test)
target_link_libraries(bchain_test
  OpenSSL::SSL
  GTest::gtest_main
  GTest::gmock_main
)

add_subdirectory(src)
  
include(GoogleTest)
gtest_discover_tests(bchain_test)
