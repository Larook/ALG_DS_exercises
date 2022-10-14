//
// Created by karol on 12/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_ALGORITHMS_H
#define ALGORITHMS_DATASTRUCTURES_ALGORITHMS_H

#include "vector"

class Algorithms {

public:
    static int factorial_iterative(int num);

    static int factorial_recursive(int input);

    static int get_fibonacci_value_iterative(int input);

    static int get_fibonacci_value_recursive(int input);

    static std::string reverse_string_iterative(std::string input);

    static void reverse_string_recursive(std::string &input, int l, int h);

    static void bubble_sort(int array[], int len);

    static void selection_sort(int array[], int len);

    static void insertion_sort(int array[], int len);

    static std::vector<int> merge_sort(std::vector<int> array);

    static void quick_sort(int array[], int low, int high);

};


#endif //ALGORITHMS_DATASTRUCTURES_ALGORITHMS_H
