//
// Created by karol on 12/10/2022.
//

#include <gtest/gtest.h>
#include "Algorithms.h"

TEST(AlgorithmsRecursion, Factorial) {
    int input = 5;
    int sol_gt = 120;

    int sol_iter = Algorithms::factorial_iterative(input);
    int sol_rec = Algorithms::factorial_recursive(input);

    EXPECT_EQ(sol_iter, sol_gt);
    EXPECT_EQ(sol_rec, sol_gt);
}

TEST(AlgorithmsRecursion, Fibonnaci) {

    int input = 6;
    int sol_gt = 8;

    int sol_iter = Algorithms::get_fibonacci_value_iterative(input);
    EXPECT_EQ(sol_iter, sol_gt);

    int sol_rec = Algorithms::get_fibonacci_value_recursive(input);
    EXPECT_EQ(sol_rec, sol_gt);
}

TEST(AlgorithmsRecursion, StringReversal) {
    std::string input = "yoyo mastery";
    std::string sol_gt = "yretsam oyoy";

    std::string sol_iter = Algorithms::reverse_string_iterative(input);
    EXPECT_EQ(sol_iter, sol_gt);
//
    std::string sol_rec = input;
    Algorithms::reverse_string_recursive(sol_rec, 0, sol_rec.length() - 1);
    EXPECT_EQ(sol_rec, sol_gt);
}

TEST(AlgorithmsSorting, BubbleSort) {

    int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    int length = sizeof(numbers) / sizeof(int);

    Algorithms::bubble_sort(numbers, length);

    for (auto obj : numbers) {
        std::cout << obj << std::endl;
    }
}

TEST(AlgorithmsSorting, SelectionSort) {
    int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    int length = sizeof(numbers) / sizeof(int);

    Algorithms::selection_sort(numbers, length);

    for (auto obj : numbers) {
        std::cout << obj << std::endl;
    }
}

TEST(AlgorithmsSorting, InsertionSort) {
//    int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    int numbers[] = {1, 4, 8, 5, 9};
    int length = sizeof(numbers) / sizeof(int);

    Algorithms::insertion_sort(numbers, length);

    for (auto obj : numbers) {
        std::cout << obj << std::endl;
    }
}

TEST(AlgorithmsSorting, MergeSort) {
//    std::vector<int>numbers = std::vector<int>({1, 4, 8, 5, 9});
    std::vector<int> numbers = std::vector<int>({99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0});

    numbers = Algorithms::merge_sort(numbers);

    for (auto obj : numbers) {
        std::cout << obj << std::endl;
    }
}

TEST(AlgorithmsSorting, QuickSort) {
//    std::vector<int>numbers = std::vector<int>({1, 4, 8, 5, 9});
    int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    Algorithms::quick_sort(numbers, 0, sizeof(numbers) / sizeof(int) - 1);

    for (auto obj : numbers) {
        std::cout << obj << std::endl;
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}