//
// Created by karol on 10/10/2022.
//

#include <iostream>
#include "include/MyStack_Array.h"

template<typename T>
MyStack_Array<T>::MyStack_Array(T value) {
    data.push_back(value);
    length++;
}

template<typename T>
void MyStack_Array<T>::push(T value) {
    data.push_back(value);
    length++;
}

template<typename T>
T MyStack_Array<T>::pop() {
    T prev_top = data.back();
    data.pop_back();
    length--;
    return prev_top;
}

template<typename T>
void MyStack_Array<T>::peek() {
    std::cout << "on the top of the stack = " << data.back() << std::endl;
}

template<typename T>
bool MyStack_Array<T>::is_empty() {
    if (length < 1) { return true; }
    return false;
}


// ensures that compiler will generate code for those types
template
class MyStack_Array<int>;

template
class MyStack_Array<float>;

template
class MyStack_Array<std::string>;

