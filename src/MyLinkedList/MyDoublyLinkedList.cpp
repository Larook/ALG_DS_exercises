//
// Created by karol on 06/10/2022.
//
#include "MyDoublyLinkedList.h"


template<typename T>
MyDoublyLinkedList<T>::MyDoublyLinkedList(T value) {
    node<T> *nodeP = new node<T>;
    nodeP->data = value;
    nodeP->next = NULL;
    nodeP->prev = NULL;

    headP = nodeP;
    tailP = nodeP;
    length++;
}

template<typename T>
void MyDoublyLinkedList<T>::append(T value) {
    // O(1)
    node<T> *nodeP = new node<T>;
    nodeP->data = value;
    nodeP->next = NULL;
    nodeP->prev = tailP;

    tailP->next = nodeP;
    tailP = nodeP;
    length++;
}

template<typename T>
T MyDoublyLinkedList<T>::get_value(int index) {
    node <T> *node_search = headP;
    for (int i = 0; i < index; i++) {
        node_search = node_search->next;
    }
    return node_search->data;
}

template<typename T>
void MyDoublyLinkedList<T>::prepend(T value) {
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
    new_nodeP->prev = NULL;

    headP->prev = new_nodeP;
    headP = new_nodeP;
    length++;
}

template<typename T>
node <T> *MyDoublyLinkedList<T>::get_node(int index) {
    // O(n)
    node <T> *nodeP_now = headP;
    for (int i = 1; i <= index; i++) {
        nodeP_now = nodeP_now->next;
    }
    return nodeP_now;
}

template<typename T>
void MyDoublyLinkedList<T>::insert(int index, T value) {
    /* O(n)
     * insert at this location, this value to the list
     * for each index, find the one before and change
     *
     * connect prev_node to new_node
     * connect new_node to next_node
     */
    if (index == 0) { this->prepend(value); }
    else if (index >= length) { this->append(value); }
    else {
        // when indeed inserting inbetween
        node<T> *node_before = get_node(index - 1);
        node<T> *node_after = node_before->next;


        node<T> *nodeP_new = new node<T>;
        nodeP_new->data = value;
        nodeP_new->prev = node_before;
        nodeP_new->next = node_after; // connect next_node to new_node

        node_before->next = nodeP_new;  // connect previous_node to the new_node
        node_after->prev = nodeP_new;

        length++;
    }
}

template<typename T>
void MyDoublyLinkedList<T>::remove(int index) {
    /* O(n)
     * removes the node at given index
     *     * - *   *   * - * - *
     *          \_____/
     */
    node <T> *nodeP_before = get_node(index - 1);
    node <T> *nodeP_after = nodeP_before->next->next;
    nodeP_before->next = nodeP_after;
    nodeP_after->prev = nodeP_before;

    length--;
}


// ensures that compiler will generate code for those types
template
class MyDoublyLinkedList<int>;

template
class MyDoublyLinkedList<float>;

template
class MyDoublyLinkedList<string>;
