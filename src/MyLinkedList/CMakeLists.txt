#add_library(MyLinkedList MyLinkedList.cpp ../../tests/MyLinkedList_test.cpp)
#add_library(MyLinkedList MyLinkedList.cpp include/MyLinkedList.h)
add_library(MyLinkedList MyLinkedList.cpp)
#add_library(MyHashTable exercises_MyHashTable.cpp MyHashTable.cpp)

target_include_directories(MyLinkedList PUBLIC include)