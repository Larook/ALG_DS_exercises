//
// Created by karol on 12/10/2022.
//

#include <string>
#include <valarray>
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

void Algorithms::bubble_sort(int array[], int len) {
    // works by sorting each time and repeated for every member of a list
    // time O(n^2), space O(1)
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            // swap
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void Algorithms::selection_sort(int array[], int len) {
    // works by finding the smallest value of current list
    // then adding it to the beginning of the list
    for (int i = 0; i < len; i++) {
        int min_id = i;
        for (int j = i + 1; j < len; j++) {
            // found the minimum index of this sweep
            if (array[j] < array[min_id]) {
                min_id = j;
            }
        }
        // change the positions of the indexes
        int tmp = array[i];
        array[i] = array[min_id];
        array[min_id] = tmp;
    }
}

void Algorithms::insertion_sort(int array[], int len) {
    // works by finding the smallest value of current list
    // then adding it to the beginning of the list, while shifting over the already sorted blocks
    // has O(n) in the scenario when the list is partially sorted
    for (int i = 0; i < len; i++) {
        int key = array[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j]; // move element ahead
            j = j - 1; // decrease (go left)
        }
        array[j + 1] = key; //put the key at the correct place
    }
}


std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    // join the left and right arrays after they are sorted
    std::vector<int> c;

    while (!(a.empty()) & !(b.empty())) {
        if (a[0] > b[0]) {
            c.push_back(b[0]);
            b.erase(b.begin()); // remove b[0] from b
        } else {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }
    // a OR b is empty and c has almost all elements

    while (!a.empty()) {
        c.push_back(a[0]);
        a.erase(a.begin());
    }
    while (!b.empty()) {
        c.push_back(b[0]);
        b.erase(b.begin());
    }
    return c;
}

std::vector<int> Algorithms::merge_sort(std::vector<int> array) {
    // Divide & Conquer approach -- gives O(nlogn) time complexity and uses recursion
    int length = array.size();
    if (length == 1) {
        return array;
    }
    // Split array into right and left
    int n_left = length / 2;

    std::vector<int> left = std::vector<int>(array.begin(), array.begin() + n_left);
    std::vector<int> right = std::vector<int>(array.begin() + n_left, array.end());

    return merge(merge_sort(left), merge_sort(right));

}


int partition(int array[], int low, int high, int pivot) {
    int p_index = low;

    // traverse the array from low to high
    for (int i = low; i <= high; i++) {
        //if the current element is smaller than the pivot -- swap p_index with the current element
        if (array[i] <= pivot) {
            std::swap(array[p_index], array[i]);
            p_index++;
        }
    }
    p_index--;
    return p_index;
}

void Algorithms::quick_sort(int *array, int low, int high) {
    /* taken from https://www.scaler.com/topics/quick-sort-in-cpp/
     * Divide the array into 2 subarrays around the PIVOT point and recursivelly call quick_sort on the parts
     */
    if (low < high) {
        int pivot = array[high];

        // rearrange and get the proper pivot index
        int p_index = partition(array, low, high, pivot);

        quick_sort(array, low, p_index - 1);
        quick_sort(array, p_index + 1, high);
    }

}
