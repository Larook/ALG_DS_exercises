//
// Created by karol on 10/10/2022.
//


#include "ostream"
#include "../src/MyQueue/include/MyQueue.h"
#include "../src/MyQueue/exercise_MyQueue.cpp"
#include <gtest/gtest.h>

using namespace std;



TEST(MyQueue, EnqueueDequeue) {
    MyQueue<string> queue("Hello");
    queue.enqueue("this");
    queue.enqueue("is");
    queue.enqueue("my");
    queue.enqueue("name");

    Node<string> *found = queue.dequeue();
    string val1 = found->data;
    EXPECT_EQ(val1, "Hello");

    Node<string> *found2 = queue.dequeue();
    string val2 = found2->data;
    EXPECT_EQ(val2, "this");
}

TEST(MyQueue, DequeueNull) {
    MyQueue<string> queue("Hello");
    queue.enqueue("there");
    Node<string> *found = queue.dequeue();
    string val1 = found->data;
    EXPECT_EQ(val1, "Hello");

    found = queue.dequeue();
    string val2 = found->data;
    EXPECT_EQ(val2, "there");

    found = queue.dequeue();
    EXPECT_EQ(found, nullptr);
}

TEST(QueueExercises, QueueUsingStackTest) {
    QueueUsingStack<std::string> q1; // = new Q
    q1.enqueue("Hello");
    q1.enqueue("this");
    q1.enqueue("is");
    q1.enqueue("my");
    q1.enqueue("name");

    string val1 = q1.dequeue();
    EXPECT_EQ(val1, "Hello");

    string val2 = q1.dequeue();
    EXPECT_EQ(val2, "this");

    string val3 = q1.dequeue();
    EXPECT_EQ(val3, "is");

    q1.enqueue("a dinosaur");

    string val4 = q1.dequeue();
    EXPECT_EQ(val4, "a dinosaur");

    string val5 = q1.dequeue();
    EXPECT_EQ(val5, "my");
}



int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}