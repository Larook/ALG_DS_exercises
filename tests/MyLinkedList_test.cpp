//
// Created by karol on 29/09/2022.
//


//#include "../src/MyLinkedList/include/MyLinkedList/MyLinkedList.h"
#include "MyLinkedList.h"
#include <gtest/gtest.h>

using namespace std;



TEST(MyLinkedList, Append) {
    MyLinkedList<int> myLL(4);
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

TEST(MyLinkedList, Prepend) {
    MyLinkedList<int> myLL(4);
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

TEST(MyLinkedList, Insert) {
    MyLinkedList<int> myLL(1);
    myLL.append(4);
    myLL.append(10);
    myLL.append(16);

    myLL.display();
    myLL.insert(2, 99);
    myLL.display();

    EXPECT_EQ(myLL.get_value(2), 99);
}
TEST(MyLinkedList, Remove) {
    MyLinkedList<int> myLL(1);
    myLL.append(4);
    myLL.append(10);
    myLL.append(16);
    myLL.display();

    myLL.remove(2);
    myLL.display();

    EXPECT_EQ(myLL.get_value(2), 16);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}