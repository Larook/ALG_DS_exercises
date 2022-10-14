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

TEST(MyBinarySearchTree, BreadthFirstSearch) {
    MyBinarySearchTree<int> tree(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);

    std::vector<Node<int> *> visited_nodes = tree.breadth_first_search();
    for (auto node : visited_nodes) {
        std::cout << "node value = " << node->getValue() << std::endl;
    }

    // recursive approach
    std::vector<Node<int> *> visited_nodes2;
    std::vector<Node<int> *> queue({tree.getRoot()});
    visited_nodes2 = tree.breadth_first_search_recursion(queue, visited_nodes2);

    for (auto node : visited_nodes2) {
        std::cout << "node value = " << node->getValue() << std::endl;
    }
}

TEST(MyBinarySearchTree, DepthFirstSearch) {
    // TODO: some problems with recursion?
    MyBinarySearchTree<int> tree(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);

    std::vector<Node<int> *> visited_nodes = tree.depth_first_search("in_order");
    for (auto node : visited_nodes) {
        std::cout << "node value = " << node->getValue() << std::endl;
    }

//    std::vector<Node<int> *> visited_nodes2 = tree.depth_first_search("pre_order");
//    for (auto node : visited_nodes2) {
//        std::cout << "node value = " << node->getValue() << std::endl;
//    }
//
//    std::vector<Node<int> *> visited_nodes3 = tree.depth_first_search("post_order");
//    for (auto node : visited_nodes3) {
//        std::cout << "node value = " << node->getValue() << std::endl;
//    }
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