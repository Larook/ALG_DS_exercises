//
// Created by karol on 29/09/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYVIRTUALLINKEDLIST_H
#define ALGORITHMS_DATASTRUCTURES_MYVIRTUALLINKEDLIST_H

#include <vector>
//#include <hash_map>
//#include <map>
#include <unordered_map>
#include "iostream"

using namespace std;


template<typename T>
struct node {
    T data;
    struct node *next;
    struct node *prev;
};
//
//template<typename T>
//struct node_single : public node<T> {
//    T data;
//    struct node *next;
//};

template<typename T>
class MyVirtualLinkedList {
    int length = 0;
    node<T> *headP;
    node<T> *tailP;

public:

    virtual void append(T value) = 0;

    virtual T get_value(int index) = 0;

    virtual void prepend(T value) = 0;

    virtual node<T> *get_node(int index) = 0;

    virtual void insert(int index, T value) = 0;

    virtual void remove(int index) = 0;

    void display() {
        cout << "my linked list = [";
        cout << "mem=" << headP << " value=" << headP->data << ", ";
        node<T> *node_ptr = headP;
        for (int i = 0; i < length - 1; i++) {
            node_ptr = node_ptr->next;
            cout << "mem=" << node_ptr << " value=" << node_ptr->data << ", ";
        }
        cout << "]" << endl;
    }
};

#endif //ALGORITHMS_DATASTRUCTURES_MYVIRTUALLINKEDLIST_H
