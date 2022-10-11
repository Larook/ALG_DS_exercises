//
// Created by karol on 10/10/2022.
//

#include <iostream>
#include "include/MyStack_LinkedList.h"

template<typename T>
MyStack_LinkedList<T>::MyStack_LinkedList(T value) {
    Node<T> *new_node = new Node<T>;
    new_node->data = value;
    new_node->prev = nullptr;
//    new_node->prev = nullptr;
    bottom = new_node;
    top = new_node;
    length++;
}

template<typename T>
void MyStack_LinkedList<T>::push(T value) {
    Node<T> *new_node = new Node<T>;
    new_node->data = value;
    new_node->prev = nullptr;

    Node<T> *prev_top = top; // previous_top
    top = new_node;
    top->prev = prev_top;  // put the previous_top as next
    length++;

}

template<typename T>
Node<T> *MyStack_LinkedList<T>::pop() {
    if (!is_empty()) {
        Node<T> *prev_top = top;
        top = top->prev;
        length--;
        return prev_top;
    }
    return nullptr;
}

template<typename T>
void MyStack_LinkedList<T>::peek() {
    std::cout << "on the top of the stack = " << top->data << std::endl;
}

template<typename T>
bool MyStack_LinkedList<T>::is_empty() {
    if (length < 1) { return true; }
    return false;
}


// ensures that compiler will generate code for those types
template
class MyStack_LinkedList<int>;

template
class MyStack_LinkedList<float>;

template
class MyStack_LinkedList<std::string>;

template
class Node<int>;

template
class Node<float>;

template
class Node<std::string>;

