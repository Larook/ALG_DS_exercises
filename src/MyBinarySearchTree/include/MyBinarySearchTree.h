//
// Created by karol on 11/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYBINARYSEARCHTREE_H
#define ALGORITHMS_DATASTRUCTURES_MYBINARYSEARCHTREE_H

#include "iostream"

template<typename T>
class Node {
private:
    T value;
    Node *left = nullptr;
    Node *right = nullptr;

public:
    Node(T val) {
        setValue(val);
    }

    T getValue() const {
        return value;
    }

    void setValue(T val) {
        Node::value = val;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }

    void describe() {
        std::cout << "node value = " << this->getValue() << std::endl;
        if (this->getLeft()) {
            std::cout << "\t left value = " << this->getLeft()->getValue() << std::endl;
        }
        if (this->getRight()) {
            std::cout << "\t right value = " << this->getRight()->getValue() << std::endl;
        }
    }
};

template<typename T>
class MyBinarySearchTree {
    Node<T> *root;
public:
    Node<T> *getRoot() const;

    void setRoot(Node<T> *root);

public:
    MyBinarySearchTree(T val);

    void insert(T val);

    Node<T> *lookup(T val);

    Node<T> *get_closer_leaf(Node<T> *parent, T val);

    void remove(T value);

    void display();

    void display_recursive(Node<T> *node);

    std::vector<Node<T> *> breadth_first_search();

    std::vector<Node<T> *>
    breadth_first_search_recursion(std::vector<Node<T> *> queue, std::vector<Node<T> *> visited);

    std::vector<Node<T> *> depth_first_search(std::string choice);

    std::vector<Node<T> *> traverse_dfs_in_order(Node<T> *current_, std::vector<Node<T> *> visited);
    std::vector<Node<T> *> traverse_dfs_pre_order(Node<T> *current_, std::vector<Node<T> *> visited);
    std::vector<Node<T> *> traverse_dfs_post_order(Node<T> *current_, std::vector<Node<T> *> visited);
};


#endif //ALGORITHMS_DATASTRUCTURES_MYBINARYSEARCHTREE_H
