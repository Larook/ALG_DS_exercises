//
// Created by karol on 29/09/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYLINKEDLIST_H
#define ALGORITHMS_DATASTRUCTURES_MYLINKEDLIST_H

#include <vector>
//#include <hash_map>
//#include <map>
#include <unordered_map>
#include "iostream"

using namespace std;


template<typename T>
struct node {
    T data;
    struct node *next;
};

template<typename T>
class MyLinkedList {
    int length = 0;
    node<T> *headP;
    node<T> *tailP;

public:
    MyLinkedList(T value) {
        node<T> *nodeP = new node<T>;
        nodeP->data = value;
        nodeP->next = NULL;

        headP = nodeP;
        tailP = nodeP;
        length++;
    }

    void append(T value) {
        // O(1)
        node<T> *nodeP = new node<T>;
        nodeP->data = value;
        nodeP->next = NULL;

        tailP->next = nodeP;
        tailP = nodeP;
        length++;
    };

    T get_value(int index) {
        node<T> *node_search = headP;
        for (int i = 0; i < index; i++) {
            node_search = node_search->next;
        }
        return node_search->data;
    }

    void prepend(T value) {
        /* O(1)
         * add to the beginning of the list
         * had before: 4->10>16
         * want to have: 1->4->10->16
         *
         * take the current head and its pointer
         * create new node, set next at the prev's head ptr
         * make the new node the head
         */
        node<T> *new_nodeP = new node<T>;;
        new_nodeP->data = value;
        new_nodeP->next = headP;

        headP = new_nodeP;
        length++;
    }

    node<T>* get_node(int index){
        // O(n)
        node<T> *nodeP_now = headP;
        for (int i = 1; i <= index; i++) {
            nodeP_now = nodeP_now->next;
        }
        return nodeP_now;
    }

    void insert(int index, T value) {
        /* O(n)
         * insert at this location, this value to the list
         * for each index, find the one before and change
         *
         * connect prev_node to new_node
         * connect new_node to next_node
         */
        if (index == 0) { this->prepend(value); }
        else if (index >= length) { this->append(value); }
        else{
            // when indeed inserting inbetween
            node<T> *nodeP_new = new node<T>;
            nodeP_new->data = value;

            node<T> *nodeP_now = get_node(index-1);
            nodeP_new->next = nodeP_now->next; // connect next_node to new_node
            nodeP_now->next = nodeP_new;  // connect previous_node to the new_node
        length++;
        }
    }

    void remove(int index){
        /* O(n)
         * removes the node at given index
         *     * - *   *   * - * - *
         *          \_____/
         */
        node<T> *nodeP_prev = get_node(index-1);
        nodeP_prev->next = nodeP_prev->next->next;

        // this also works but more iters
        // node<T> *nodeP_next = get_node(index+1);
        // nodeP_prev->next = nodeP_next;
        length--;
    }

    void display() {
        cout << "my linked list = [";
        cout << "mem=" << headP << " value=" << headP->data << ", ";
        node<T> *node_ptr = headP;
        for (int i = 0; i < length - 1; i++) {
            node_ptr = node_ptr->next;
            cout << "mem=" << node_ptr << " value=" << node_ptr->data << ", ";
        }
        cout << "]" << endl;
    }
};

#endif //ALGORITHMS_DATASTRUCTURES_MYLINKEDLIST_H
