# example of splitting cpp proj into src and test here: https://matgomes.com/integrate-google-test-into-cmake/
cmake_minimum_required(VERSION 3.16)
project(Algorithms_DataStructures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS  OFF)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

#add_executable(Algorithms_DataStructures main.cpp A.cpp A.h)
#add_executable(Algorithms_DataStructures main.cpp BasicIntroExample.cpp BasicIntroExample.h A.cpp A.h MyArray.cpp MyArray.h exercises_MyArray.cpp tests/GoogleTestDemo.cpp)
#add_executable(Algorithms_DataStructures ../Samsung_cpp_revision/help/samsung_tasks.cpp basic_intro_examples.cpp basic_intro_examples.h)
#target_link_libraries(Algorithms_DataStructures ${GTEST_BOTH_LIBRARIES})




