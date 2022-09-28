//
// Created by karol on 28/09/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYHASHTABLE_H
#define ALGORITHMS_DATASTRUCTURES_MYHASHTABLE_H


#include <iostream>
#include <vector>
#include <map>

using namespace std;


template<typename T>
class MyHashTable {
private:
    int __length;
    int __data[];

    int __hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (hash + key[i] * i) % __length;
        }
        return hash;
    }

public:
    MyHashTable(int size) {
        __length = size;
        __data[size] = {0};
    }


    void set(string key, int value) {
        int address = __hash(key);
        // check for collisions
        if (!__data[address]) { __data[address] = value; }
        else { cout << "collision happened at the address:" << address << endl;}
    }

    int get(string key) {
        int address = __hash(key);
        // what about collisions?
        // shouldt the data be an array of arrays?
        if (__data[address]){
            return __data[address];
        } else return 0;
    }

    vector<string> keys(){
        // return all the keys used ALSO collision
        return vector<string>{"todo"};
    }

    static int get_first_reoccuring_element(vector<int> arr) {
        map<int, int> counter;

        for (auto& elem : arr){
            if (counter.count(elem) == 1){
                return elem;
            }
            counter.insert(std::pair<int, int> (elem, 1));
        }
        return INT16_MAX;
    }
};

#endif //ALGORITHMS_DATASTRUCTURES_MYHASHTABLE_H
