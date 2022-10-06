#add_library(MySinglyLinkedList MySinglyLinkedList.cpp ../../tests/MyLinkedList_test.cpp)
#add_library(MySinglyLinkedList MySinglyLinkedList.cpp include/MySinglyLinkedList.h)
#add_library(MyLinkedList MySinglyLinkedList.cpp MyVirtualLinkedList.cpp include/MyVirtualLinkedList.h)
#add_library(MyLinkedList MyVirtualLinkedList.cpp MySinglyLinkedList.cpp)
#add_library(MyLinkedList MyVirtualLinkedList.cpp MySinglyLinkedList.cpp)
#add_library(MyHashTable exercises_MyHashTable.cpp MyHashTable.cpp)
#add_library(MyLinkedList MyVirtualLinkedList.cpp)
#add_library(MyLinkedList MySinglyLinkedList.cpp)
#target_include_directories(MyLinkedList PUBLIC include)
#
#add_library(MyVirtualLinkedList MyVirtualLinkedList.cpp)
#add_library(MySinglyLinkedList MySinglyLinkedList.cpp)


#set(C_LIB ${CMAKE_BINARY_DIR}/libcombi.a)
#
#add_custom_target(combined
#        COMMAND ar -x $<TARGET_FILE:MyVirtualLinkedList>
#        COMMAND ar -x $<TARGET_FILE:MySinglyLinkedList>
#        COMMAND ar -qcs ${C_LIB} *.o
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#        DEPENDS MyVirtualLinkedList MySinglyLinkedList
#        )
#
#add_library(MyLinkedList STATIC IMPORTED GLOBAL)
##add_dependencies(MyLinkedList combined)
#add_dependencies(MyLinkedList MyVirtualLinkedList MySinglyLinkedList)


#add_library(MyLinkedList MySinglyLinkedList.cpp MyDoublyLinkedList.cpp include/MyDoublyLinkedList.h)
add_library(MyLinkedList MySinglyLinkedList.cpp MyDoublyLinkedList.cpp include/exercises_MyLinkedList.cpp)
#add_library(MyLinkedList MySinglyLinkedList.cpp)
#add_library(MyLinkedList MySinglyLinkedList.cpp include/MyVirtualLinkedList.cpp)
target_include_directories(MyLinkedList PUBLIC include)