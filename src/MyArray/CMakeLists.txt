#add_library(MyArray exercises_MyArray.cpp MyArray.cpp ../MyHashTable/MyHashTable.cpp ../MyHashTable/include/MyHashTable/MyHashTable.h)
add_library(MyArray exercises_MyArray.cpp MyArray.cpp ../MyLinkedList/MySinglyLinkedList.cpp ../MyLinkedList/include/MySinglyLinkedList.h)
#add_library(MyArray exercises_MyArray.cpp)

target_include_directories(MyArray PUBLIC include)