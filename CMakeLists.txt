# example of splitting cpp proj into src and test here: https://matgomes.com/integrate-google-test-into-cmake/
cmake_minimum_required(VERSION 3.16)
project(Algorithms_DataStructures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS  OFF)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)




