//
// Created by karol on 11/10/2022.
//
#include "include/MyQueue.h"
#include "stack"

template<typename T>
class QueueUsingStack {
    std::stack<T> stack_in;
    std::stack<T> stack_out;

public:
    QueueUsingStack() { ; }

    void enqueue(T value) {
        stack_in.push(value);
    }

    T dequeue() {
        // first reverse the stack by putting elements on stack_out, then pop() from reversed
        int a = stack_in.size();
        for (int i = 0; i < a; i++) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
        T prev_top = stack_out.top();
        stack_out.pop();
        return prev_top;
    }

//    void peek() {
//        ;
//    }

};
