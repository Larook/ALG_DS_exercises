//
// Created by karol on 28/09/2022.
//


#include "../src/MyHashTable/include/MyHashTable/MyHashTable.h"
#include <gtest/gtest.h>

using namespace std;


TEST(MyHashTable, SetGet) {
    MyHashTable<int> hashmap(50);
    hashmap.set("grapes", 1000);
    int read = hashmap.get("grapes");
    EXPECT_EQ(read, 1000);
}

TEST(MyHashTable, EmptyGet) {
    // TODO: fix the hashing collision and get!
    MyHashTable<int> hashmap(50);
    hashmap.set("grapes", 1000);
    int read = hashmap.get("apples");
    EXPECT_EQ(read, 0);
}


TEST(HashTableExercises, FirstReoccuringElement) {
    vector<int> arr = vector<int>{2, 5, 1, 2, 3, 5};
    int first_elem = MyHashTable<int>::get_first_reoccuring_element(arr);
    EXPECT_EQ(first_elem, 2);
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}