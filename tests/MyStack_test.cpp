//
// Created by karol on 10/10/2022.
//

#include "ostream"
#include "MyStack_LinkedList.h"
#include "MyStack_Array.h"
#include <gtest/gtest.h>

using namespace std;



TEST(MyStack_LinkedList, PushPopPeek) {
    MyStack_LinkedList<string> stack("Hello");
    stack.push("this");
    stack.push("is");
    stack.push("my");
    stack.push("name");

    Node<string> *found = stack.pop();
    string val1 = found->data;
    EXPECT_EQ(val1, "name");
    string val2 = stack.pop()->data;
    EXPECT_EQ(val2, "my");

    stack.peek();
}

TEST(MyStack_LinkedList, Empty) {
    MyStack_LinkedList<string> stack("Hello");
    EXPECT_EQ(stack.is_empty(), false);
    stack.pop();
    EXPECT_EQ(stack.is_empty(), true);
}


TEST(MyStack_Array, PushPopPeek) {
    MyStack_Array<string> stack("Hello");
    stack.push("this");
    stack.push("is");
    stack.push("my");
    stack.push("name");

    string val1 = stack.pop();
    EXPECT_EQ(val1, "name");
    string val2 = stack.pop();
    EXPECT_EQ(val2, "my");

    stack.peek();
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}