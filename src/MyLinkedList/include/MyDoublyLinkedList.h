//
// Created by karol on 06/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYDOUBLYLINKEDLIST_H
#define ALGORITHMS_DATASTRUCTURES_MYDOUBLYLINKEDLIST_H
#include "MyVirtualLinkedList.h"

using namespace std;


template<typename T>
class MyDoublyLinkedList: public MyVirtualLinkedList<T> {
    int length = 0;
    node<T> *headP;
    node<T> *tailP;

public:
    explicit MyDoublyLinkedList(T value);

    void append(T value);;

    T get_value(int index);

    void prepend(T value);

    node<T>* get_node(int index);

    void insert(int index, T value);

    void remove(int index);

};


#endif //ALGORITHMS_DATASTRUCTURES_MYDOUBLYLINKEDLIST_H
