//
// Created by karol on 12/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_ALGORITHMS_H
#define ALGORITHMS_DATASTRUCTURES_ALGORITHMS_H


class Algorithms {

public:
    static int factorial_iterative(int num);

    static int factorial_recursive(int input);

    static int get_fibonacci_value_iterative(int input);

    static int get_fibonacci_value_recursive(int input);

    static std::string reverse_string_iterative(std::string input);

    static void reverse_string_recursive(std::string &input, int l, int h);

};


#endif //ALGORITHMS_DATASTRUCTURES_ALGORITHMS_H
