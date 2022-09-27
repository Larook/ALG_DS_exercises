include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


add_executable(MyArray_test MyArray_test.cpp)
target_link_libraries(MyArray_test PRIVATE GTest::GTest MyArray)

add_test(MyArray_gtests MyArray_test)

