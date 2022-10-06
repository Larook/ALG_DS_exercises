//
// Created by karol on 29/09/2022.
//

#include "MySinglyLinkedList.h"
#include "MyDoublyLinkedList.h"
#include <gtest/gtest.h>

using namespace std;



TEST(MySinglyLinkedList, Append) {
    MySinglyLinkedList<int> myLL(4);
    int val1 = myLL.get_value(0);
    EXPECT_EQ(val1, 4);

    myLL.append(10);
    int val2 = myLL.get_value(1);
    EXPECT_EQ(val2, 10);

    myLL.append(16);
    int val3 = myLL.get_value(2);
    EXPECT_EQ(val3, 16);
    myLL.display();
}

TEST(MySinglyLinkedList, Prepend) {
    MySinglyLinkedList<int> myLL(4);
    myLL.append(10);

    myLL.prepend(1);
    myLL.display();
    EXPECT_EQ(myLL.get_value(0), 1);
    EXPECT_EQ(myLL.get_value(1), 4);
    EXPECT_EQ(myLL.get_value(2), 10);
//
//    myLL.append(16);
//    int val3 = myLL.get_value(2);
//    EXPECT_EQ(val3, 16);

//    myLL.display();
}

TEST(MySinglyLinkedList, Insert) {
    MySinglyLinkedList<int> myLL(1);
    myLL.append(4);
    myLL.append(10);
    myLL.append(16);

    myLL.display();
    myLL.insert(2, 99);
    myLL.display();

    EXPECT_EQ(myLL.get_value(2), 99);
}

TEST(MySinglyLinkedList, Remove) {
    MySinglyLinkedList<int> myLL(1);
    myLL.append(4);
    myLL.append(10);
    myLL.append(16);
    myLL.display();

    myLL.remove(2);
    myLL.display();

    EXPECT_EQ(myLL.get_value(2), 16);
}


TEST(MyDoublyLinkedList, Append) {
    MyDoublyLinkedList<int> myLL(4);
    int val1 = myLL.get_value(0);
    EXPECT_EQ(val1, 4);

    myLL.append(10);
    int val2 = myLL.get_value(1);
    EXPECT_EQ(val2, 10);

    myLL.append(16);
    int val3 = myLL.get_value(2);
    EXPECT_EQ(val3, 16);
    myLL.display();  // probs with display
}

TEST(MyDoublyLinkedList, Prepend) {
    MyDoublyLinkedList<int> myLL(4);
    int val1 = myLL.get_value(0);
    EXPECT_EQ(val1, 4);

    myLL.prepend(1);
    int val2 = myLL.get_value(0);
    EXPECT_EQ(val2, 1);

    myLL.display();  // probs with display
}

TEST(MyDoublyLinkedList, Insert) {
    MyDoublyLinkedList<int> myLL(4);
    myLL.append(10);
    myLL.append(16);
    myLL.insert(2, 99);

    int val = myLL.get_value(2);
    EXPECT_EQ(val, 99);

    myLL.display();  // probs with display
}

TEST(MyDoublyLinkedList, Remove) {
    // 4, 10, 16 -> 4, 16
    MyDoublyLinkedList<int> myLL(4);
    myLL.append(10);
    myLL.append(16);

    myLL.remove(1);
    int val = myLL.get_value(1);
    EXPECT_EQ(val, 16);

    myLL.display();  // probs with display
}

TEST(Exercise, ReverseSinglyLinkedList) {
    // 1, 4, 10, 16 -> 16, 10, 4, 1
    MySinglyLinkedList<int> myLL(1);
    myLL.append(4);
    myLL.append(10);
    myLL.append(16);

    MySinglyLinkedList<int> reversedLL = MySinglyLinkedList<int>::reverse(myLL);

//    int val = reversed_LL.get_value(1);
//    EXPECT_EQ(val, 4);
    myLL.display();  // probs with display
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}