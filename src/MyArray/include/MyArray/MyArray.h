//
// Created by karol on 21/09/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYARRAY_H
#define ALGORITHMS_DATASTRUCTURES_MYARRAY_H
#include "iostream"
#include <map>
#include <vector>

#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


template<typename T>
class MyArray {
private:
    int __length;
    map<int, T> __data;


public:
    MyArray(){
        __length = 0;
//        __data = {{0, 0}};
    }

    MyArray(T* elements, int n){
        __length = 0;
        for (int i=0; i < n; i++){
            this->push(elements[i]);
        }
    }

    T get(int index){ return __data[index+1]; }

    int length(){ return __length; }

    void push(T item){
        __data[__length + 1] = item;
        __length++;
    }

    T pop(){
        // returns the last item and deletes the object
        T value = __data[__length];
        __data.erase(__length);
        __length--;
        return value;
    }
    T pop(int index){
        // returns the last item and deletes the object
        T value = get(index);
        del(index);
        return value;
    }

    void del(int index){
        // delete and item and shift all the later indexes to -1 index
        if (__length == 0){
            throw length_error("Cannot delete from an empty array");
        }

        // shifting is O(n) -- that's why append is O(n)
        if (index < __length){
            for (int i = index; i< __length-1; i++)
            __data[i+1] = __data[i+2];
        }
        __data.erase(__length); // delete last element
        __length--;
    }
    void display();

    /* exercises and demos */
    static void run_example_own_array();
    static void run_intro();
    static string string_reversal(string input, int n);
    static MyArray<int> merge_sorted_arrays(MyArray<int> myArr1, MyArray<int> myArr2);

    static vector<int> two_sum(vector<int> nums, int target);

    static int maximum_sum_subarray(vector<int> nums);

    void two_sum2();

    static int max_subarray_rec(vector<int> A, int id_l, int id_r);

    static bool contains_duplicates(vector<int> A);

    static vector<int> rotate_array(vector<int> A, int k);

    T reverseArray(T input);
};


#endif //ALGORITHMS_DATASTRUCTURES_MYARRAY_H
