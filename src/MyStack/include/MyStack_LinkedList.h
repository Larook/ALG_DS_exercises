//
// Created by karol on 10/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYSTACK_LINKEDLIST_H
#define ALGORITHMS_DATASTRUCTURES_MYSTACK_LINKEDLIST_H


template<typename T>
struct Node {
    T data;
    Node *prev;
//    Node *prev;
};

template<typename T>
class MyStack_LinkedList {
    Node<T> *top;
    Node<T> *bottom;
    int length = 0;


public:
    MyStack_LinkedList(T value);

    void push(T value);

    Node<T> *pop();

    void peek();

    bool is_empty();

};

#endif //ALGORITHMS_DATASTRUCTURES_MYSTACK_LINKEDLIST_H
