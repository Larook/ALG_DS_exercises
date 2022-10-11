//
// Created by karol on 10/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYSTACK_ARRAY_H
#define ALGORITHMS_DATASTRUCTURES_MYSTACK_ARRAY_H

#include "vector"

template<typename T>
class MyStack_Array {
    std::vector<T> data;
    int length = 0;


public:
    MyStack_Array(T value);

    void push(T value);

    T pop();

    void peek();

    bool is_empty();

};

#endif //ALGORITHMS_DATASTRUCTURES_MYSTACK_ARRAY_H
