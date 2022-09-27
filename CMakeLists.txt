cmake_minimum_required(VERSION 3.17)
project(Algorithms_DataStructures)

set(CMAKE_CXX_STANDARD 11)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG release-1.12.1
#)

enable_testing()

#add_executable(Algorithms_DataStructures main.cpp A.cpp A.h)
add_executable(Algorithms_DataStructures main.cpp BasicIntroExample.cpp BasicIntroExample.h A.cpp A.h MyArray.cpp MyArray.h exercises_MyArray.cpp GoogleTestDemo.cpp)
#add_executable(Algorithms_DataStructures ../Samsung_cpp_revision/help/samsung_tasks.cpp basic_intro_examples.cpp basic_intro_examples.h)
#target_link_libraries(Algorithms_DataStructures ${GTEST_BOTH_LIBRARIES})