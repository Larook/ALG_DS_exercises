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

add_executable(MyHashTable_test MyHashTable_test.cpp)
target_link_libraries(MyHashTable_test PRIVATE GTest::GTest MyHashTable)
add_test(MyHashTable_gtests MyHashTable_test)


add_executable(MyLinkedList_test MyLinkedList_test.cpp)
target_link_libraries(MyLinkedList_test PRIVATE GTest::GTest MyLinkedList)
add_test(MyLinkedList_gtests MyLinkedList_test)


add_executable(MyStack_test MyStack_test.cpp)
target_link_libraries(MyStack_test PRIVATE GTest::GTest MyStack)
add_test(MyStack_gtests MyStack_test)


add_executable(MyQueue_test MyQueue_test.cpp)
target_link_libraries(MyQueue_test PRIVATE GTest::GTest MyQueue)
add_test(MyQueue_gtests MyQueue_test)

add_executable(MyBinarySearchTree_test MyBinarySearchTree_test.cpp)
target_link_libraries(MyBinarySearchTree_test PRIVATE GTest::GTest MyBinarySearchTree)
add_test(MyBinarySearchTree_gtests MyBinarySearchTree_test)

add_executable(MyGraph_test MyGraph_test.cpp)
target_link_libraries(MyGraph_test PRIVATE GTest::GTest MyGraph)
add_test(MyGraph_gtests MyGraph_test)

add_executable(Algorithms_test Algorithms_test.cpp)
target_link_libraries(Algorithms_test PRIVATE GTest::GTest Algorithms)
add_test(Algorithms_gtests Algorithms_test)
