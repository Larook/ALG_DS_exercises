//
// Created by karol on 11/10/2022.
//

#include "include/MyBinarySearchTree.h"


template<typename T>
MyBinarySearchTree<T>::MyBinarySearchTree(T val) {
    Node<T> *node = new Node<T>(val);
    node->setLeft(nullptr);
    node->setRight(nullptr);
    setRoot(node);
    std::cout << "constr root val=" << root->getValue() << std::endl;

}

template<typename T>
Node<T> *MyBinarySearchTree<T>::getRoot() const {
    return root;
}

template<typename T>
void MyBinarySearchTree<T>::setRoot(Node<T> *root) {
    MyBinarySearchTree::root = root;
}

template<typename T>
void MyBinarySearchTree<T>::display() {
    Node<T> *current_node = getRoot();
    std::cout << "--- Displaying the tree" << std::endl;
    bool end_leaf_found = false;
    while (!end_leaf_found) {
        T val_prev = current_node->getValue();

        current_node->describe();
        Node<T> *node_left = current_node->getLeft();
        Node<T> *node_right = current_node->getRight();
        if (node_left) { current_node = node_left; }
        if (node_right) { current_node = node_right; }

//        current_node = get_closer_leaf(current_node, val);
        if (val_prev == current_node->getValue()) {
            std::cout << "--- end of tree" << std::endl;
            return;
        }
    }


}

template<typename T>
void MyBinarySearchTree<T>::remove(T value) {
    // TODO: complete this -- 3 different cases
    /*
     * locate the node with the value and remove it
     * Removing:
     *  set searched_node.right as searched.left.parent
     */
    Node<T> *searched_node = lookup(value);

    T value_left_parent = searched_node->getLeft()->getValue();
    Node<T> *searched_left_parent = lookup(value_left_parent);

    searched_node->setRight(searched_left_parent);

}

template<typename T>
void MyBinarySearchTree<T>::insert(T val) {
    /*
     * when inserting need to traverse the tree and check the values -- either go left or right
     * when was the parent found? When is smaller, but doesn't have LEFT or bigger and doesnt have RIGHT
     */

    Node<T> *node = new Node<T>(val);

    Node<T> *parent = getRoot();

    bool parent_found = false;
    bool found_left = false;
    bool found_right = false;

    while (!parent_found) {
        parent = get_closer_leaf(parent, val);
        T parent_value = parent->getValue();
        // parent found if there are no leafs
        found_left = (val < parent_value) && !(parent->getLeft()); // there is no Left node (but should be)
        found_right = (val >= parent_value) && !(parent->getRight()); // there is no Right node (but should be)
        parent_found = found_left || found_right;
    }

    // when found the terminating leaf
    if (found_left) { parent->setLeft(node); }
    if (found_right) { parent->setRight(node); }

    std::cout << "node val=" << node->getValue() << std::endl;
    std::cout << "\tparent val=" << parent->getValue() << std::endl;

}

template<typename T>
Node<T> *MyBinarySearchTree<T>::get_closer_leaf(Node<T> *parent, T val) {
    /*
     * returns Left or Right leaf of the parent
     */
    T parent_value = parent->getValue();
    if ((parent_value > val) && parent->getLeft()) {
        parent = parent->getLeft();
    } else if ((parent_value <= val) && parent->getRight()) {
        parent = parent->getRight();
    }
    return parent;
}

template<typename T>
Node<T> *MyBinarySearchTree<T>::lookup(T val) {
    /*
     * search the tree from the root to find the searched value
     */
    Node<T> *node_current = getRoot();
    if (node_current == nullptr) { return nullptr; }

    bool val_found = false;
    while (!val_found) {
        val_found = node_current->getValue() == val;
        if (val_found) { return node_current; }
        T val_prev = node_current->getValue();
        node_current = get_closer_leaf(node_current, val);
        if (val_prev == node_current->getValue()) { return nullptr; }
    }
    return nullptr;
}


// ensures that compiler will generate code for those types
template
class MyBinarySearchTree<int>;

template
class MyBinarySearchTree<float>;

template
class MyBinarySearchTree<std::string>;

template
class Node<int>;

template
class Node<float>;

template
class Node<std::string>;
