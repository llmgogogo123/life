cmake_minimum_required(VERSION 3.16)
project(life CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mystring STATIC src/mystring.cpp)
target_include_directories(mystring PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test_mystring tests/test.cpp)
target_link_libraries(test_mystring PRIVATE mystring)

enable_testing()
add_test(NAME unit COMMAND test_mystring)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address -g)
    add_link_options(-fsanitize=address)
endif()
