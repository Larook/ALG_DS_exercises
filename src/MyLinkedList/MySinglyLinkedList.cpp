//
// Created by karol on 29/09/2022.
//

#include "include/MySinglyLinkedList.h"


template<typename T>
MySinglyLinkedList<T>::MySinglyLinkedList(T value) {
    node<T> *nodeP = new node<T>;
    nodeP->data = value;
    nodeP->prev = NULL;

    headP = nodeP;
    tailP = nodeP;
    length++;
}

template<typename T>
void MySinglyLinkedList<T>::append(T value) {
    // O(1)
    node<T> *nodeP = new node<T>;
    nodeP->data = value;
    nodeP->prev = NULL;

    tailP->prev = nodeP;
    tailP = nodeP;
    length++;
}

template<typename T>
T MySinglyLinkedList<T>::get_value(int index) {
    node<T> *node_search = headP;
    for (int i = 0; i < index; i++) {
        node_search = node_search->prev;
    }
    return node_search->data;
}

template<typename T>
void MySinglyLinkedList<T>::prepend(T value) {
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
    new_nodeP->prev = headP;

    headP = new_nodeP;
    length++;
}

template<typename T>
node<T> *MySinglyLinkedList<T>::get_node(int index) {
    // O(n)
    node<T> *nodeP_now = headP;
    for (int i = 1; i <= index; i++) {
        nodeP_now = nodeP_now->prev;
    }
    return nodeP_now;
}

template<typename T>
void MySinglyLinkedList<T>::insert(int index, T value) {
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
        node<T> *nodeP_new = new node<T>;
        nodeP_new->data = value;

        node<T> *nodeP_now = get_node(index - 1);
        nodeP_new->prev = nodeP_now->prev; // connect next_node to new_node
        nodeP_now->prev = nodeP_new;  // connect previous_node to the new_node
        length++;
    }
}

template<typename T>
void MySinglyLinkedList<T>::remove(int index) {
    /* O(n)
     * removes the node at given index
     *     * - *   *   * - * - *
     *          \_____/
     */
    node<T> *nodeP_prev = get_node(index - 1);
    nodeP_prev->prev = nodeP_prev->prev->prev;

    // this also works but more iters
    // node<T> *nodeP_next = get_node(index+1);
    // nodeP_prev->next = nodeP_next;
    length--;
}

template<typename T>
MySinglyLinkedList<T> MySinglyLinkedList<T>::reverse(MySinglyLinkedList<T> input) {
    /*
     * reverse the nodes of the LinkedList
     * take the head and tail node
     * use 2 sequential nodes -- first & second
     */
    if (input.length == 1) { return input; }

    node<T> *first = input.headP;
    input.tailP = input.headP;
    node<T> *second = first->prev;

    while (second) {
        node<T> *tmp = second->prev;
        // swap nexts: first with second
        second->prev = first;

        // go one step further -- update the first and second
        first = second;
        second = tmp;
    }
    input.headP->prev = NULL;
    input.headP = first;
    return input;
}


// ensures that compiler will generate code for those types
template
class MySinglyLinkedList<int>;

template
class MySinglyLinkedList<float>;

template
class MySinglyLinkedList<string>;

