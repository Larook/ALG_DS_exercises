//
// Created by karol on 12/10/2022.
//

#include <string>
#include "include/Algorithms.h"


int Algorithms::factorial_iterative(int num) {
    /*
     * returns factorial using loop
     */
    int solution = 1;

    for (int i = 1; i <= num; i++) {
        solution *= i;
    }
    return solution;
}


int Algorithms::factorial_recursive(int input) {
    if (input == 1) {
        return input; // base case
    }
    return input * Algorithms::factorial_recursive(input - 1); // recursive case
}

int Algorithms::get_fibonacci_value_recursive(int n) {
    // base condition
    if (n < 2) {
        return n;
    }
    return Algorithms::get_fibonacci_value_recursive(n - 2) + Algorithms::get_fibonacci_value_recursive(n - 1);
}

int Algorithms::get_fibonacci_value_iterative(int n) {
    /*
     * return the value of the nth index of the fibonnaci sequence
     */
    // init
    int fib_prev = 0;
    int fib_next = 1;
    int fib_next_new;

    for (int i = 2; i <= n; i++) {
        // each step -- starting from 2 because new of 1 is 2
        fib_next_new = fib_prev + fib_next;
        fib_prev = fib_next;
        fib_next = fib_next_new;
    }
    return fib_next;
}

std::string Algorithms::reverse_string_iterative(std::string input) {
    //Implement a function that reverses a string using iteration...and then recursion!
    std::string reversed;
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed.push_back(input[i]);
    }
    return reversed;
}


void Algorithms::reverse_string_recursive(std::string &input, int l, int h) {
    //Implement a function that reverses a string using iteration...and then recursion!
    if (l < h) {
        std::swap(input[l], input[h]);
        reverse_string_recursive(input, l + 1, h - 1);
    }
}
