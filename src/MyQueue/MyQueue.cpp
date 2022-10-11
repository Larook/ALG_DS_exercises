//
// Created by karol on 10/10/2022.
//

#include <iostream>
#include "include/MyQueue.h"


template<typename T>
MyQueue<T>::MyQueue(T value) {
    Node<T> *node_new = new Node<T>;
    node_new->data = value;
    node_new->next = nullptr;

    first = node_new;
    last = node_new;
    length++;
}


template<typename T>
void MyQueue<T>::peek() {
    std::cout << "queue: first = " << first->data << std::endl;
    std::cout << "\t\t last = " << last->data << std::endl;
}

template<typename T>
void MyQueue<T>::enqueue(T value) {
    // add new last_node
    Node<T> *node_new = new Node<T>;
    node_new->data = value;
    node_new->next = nullptr;

//    Node<T> *prev_last = last;
    last->next = node_new;
    last = node_new;
    length++;
}

template<typename T>
Node<T> *MyQueue<T>::dequeue() {
    // return the first_node and update
    if (length < 1) { return nullptr; }
    Node<T> *prev_first = first;

    Node<T> *new_first = first->next;
    first = new_first;
    length--;
    return prev_first;
}

// ensures that compiler will generate code for those types
template
class MyQueue<int>;

template
class MyQueue<float>;

template
class MyQueue<std::string>;

