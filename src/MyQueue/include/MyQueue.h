//
// Created by karol on 10/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYQUEUE_H
#define ALGORITHMS_DATASTRUCTURES_MYQUEUE_H

template<typename T>
struct Node {
    T data;
    Node *next;
};

template<typename T>
class MyQueue {
    Node<T> *first;
    Node<T> *last;
    int length = 0;

public:
    MyQueue(T value);

    void peek();

    void enqueue(T value);

    Node<T> *dequeue();
};


#endif //ALGORITHMS_DATASTRUCTURES_MYQUEUE_H
