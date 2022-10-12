//
// Created by karol on 11/10/2022.
//


#include "ostream"
#include <gtest/gtest.h>
#include <MyBinarySearchTree.h>

using namespace std;

TEST(MyBinarySearchTree, Insert) {
    MyBinarySearchTree<int> tree(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);

    Node<int> *found1 = tree.lookup(9);
    EXPECT_TRUE(found1 != nullptr);
    Node<int> *found2 = tree.lookup(170);
    EXPECT_TRUE(found2 != nullptr);
    Node<int> *found3 = tree.lookup(16);
    EXPECT_TRUE(found3 == nullptr);
}


TEST(MyBinarySearchTree, Lookup) {
    MyBinarySearchTree<int> tree(9);
    tree.insert(4);
    tree.insert(6);

    Node<int> *found1 = tree.lookup(9);
    EXPECT_TRUE(found1 != nullptr);

    Node<int> *found2 = tree.lookup(6);
    EXPECT_TRUE(found2 != nullptr);

    Node<int> *found3 = tree.lookup(1);
    EXPECT_TRUE(found3 == nullptr);
}

TEST(MyBinarySearchTree, Display) {
    MyBinarySearchTree<int> tree(60);
    tree.insert(30);
    tree.insert(14);
    tree.insert(54);
    tree.insert(55);
    tree.insert(38);
    tree.insert(44);

    tree.display_recursive(tree.getRoot());
//    tree.display();
}


TEST(MyBinarySearchTree, Remove) {
    MyBinarySearchTree<int> tree(60);
    tree.insert(30);
    tree.insert(14);
    tree.insert(54);
    tree.insert(55);
    tree.insert(38);
    tree.insert(44);

//    tree.display();
    tree.display_recursive(tree.getRoot());


    tree.remove(54);
//    tree.display();
    tree.display_recursive(tree.getRoot());

//    Node<int> *found1 = tree.lookup(9);
//    EXPECT_TRUE(found1 != nullptr);
//
//    Node<int> *found2 = tree.lookup(6);
//    EXPECT_TRUE(found2 != nullptr);
//
//    Node<int> *found3 = tree.lookup(1);
//    EXPECT_TRUE(found3 == nullptr);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}