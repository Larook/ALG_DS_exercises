//
// Created by karol on 21/09/2022.
//
#include "iostream"
#include <map>
#include <vector>

#include "MyArray.h"
using namespace std;

template<typename T>
void MyArray<T>::run_example_own_array(){
//void MyArray::run_example_own_array(){
    cout << "------------------" << endl;
    cout << "hello from MyArray" << endl;

    MyArray<int> arr1;
    arr1.push(4);
    arr1.push(5);
    arr1.push(7);
//    arr1.push(8);
//    arr1.pop();
    arr1.del(0);

    MyArray<string> arr2;
    arr2.push("yooo");

}

template<typename T>
void MyArray<T>::run_intro() {
//void MyArray::run_intro() {

    /*
     * > Static and Dynamic arrays
     * Static -- fixed in size (specify number of items ahead of time)
     * Dynamic -- allows to copy and build array in a new location
     *      enables to *.append();
     */

    // example of static array
    int arr_st[5] = {0, 1, 2, 3, 4};
    cout << arr_st << endl;

    // make it a dynamic -- make an array with 1 more storage and add it
    int n = sizeof(arr_st) / sizeof(arr_st[0]);
    int value_app = 10;
    int arr_appended[n+1];
    // append is O(n) because it copies the values
    for (int i = 0; i<n; i++){
        arr_appended[i] = arr_st[i];
    }
    arr_appended[n+1] = value_app;
    cout << arr_appended << endl;
}


template<typename T>
void MyArray<T>::display() {
    cout << "MyArray = [";
    for (int i = 0; i< __length; i++){
        cout << __data[i+1] << ",";
    }
    cout << "]";
}

// ensures that compiler will generate code for those types
template class MyArray<int>;
template class MyArray<float>;
template class MyArray<string>;