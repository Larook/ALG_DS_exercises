//
// Created by karol on 29/09/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYSINGLYLINKEDLIST_H
#define ALGORITHMS_DATASTRUCTURES_MYSINGLYLINKEDLIST_H

#include "MyVirtualLinkedList.h"

using namespace std;

template<typename T>
class MySinglyLinkedList : public MyVirtualLinkedList<T> {
    int length = 0;
    node<T> *headP;
    node<T> *tailP;

public:
    explicit MySinglyLinkedList(T value);
//    using MyVirtualLinkedList<T>::MyVirtualLinkedList; // take all of the super() constructors

    void append(T value);

    T get_value(int index);

    void prepend(T value);

    node<T> *get_node(int index);

    void insert(int index, T value);

    void remove(int index);

    static MySinglyLinkedList<T> reverse(MySinglyLinkedList<T> input);
};


#endif //ALGORITHMS_DATASTRUCTURES_MYSINGLYLINKEDLIST_H
