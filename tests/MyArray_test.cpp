//
// Created by karol on 27/09/2022.
//

//#include <iostream>
//#include <ctime>
//#include <iomanip>
//#include <map>
//#include <vector>
//
//#include "BasicIntroExample.h"
//#include "A.h"

//#include <stdafx.h>

#include <MyArray/MyArray.h>
//#include <MyArray/exercises_MyArray.cpp>
#include <gtest/gtest.h>

using namespace std;

TEST(MyArrayTest, MyArrayCanPush) {
    MyArray<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push(i);
    }
    EXPECT_EQ(arr.length(), 100);
}

TEST(MyArrayTest, MyArrayCanDelete) {
    MyArray<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push(i);
    }

    EXPECT_EQ(arr.length(), 100);
    arr.del(0);
    EXPECT_EQ(arr.length(), 99);
    EXPECT_EQ(arr.get(0), 1);
}

TEST(MyArrayTest, MyArrayCanPop) {
    MyArray<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push(i);
    }
    EXPECT_EQ(arr.pop(0), 0);
    EXPECT_EQ(arr.pop(0), 1);
    EXPECT_EQ(arr.pop(1), 3);
}

TEST(ArrayExercises, StringReversal) {
    string input = "example";
    int n = input.length();
    string reversed = MyArray<int>::string_reversal(input, n);
    EXPECT_EQ(reversed, "elpmaxe");

}

TEST(ArrayExercises, MergeSortedArrays) {
    int arr1[] = {1, 3, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    MyArray<int> myArr1 = MyArray<int>(arr1, n1);

    int arr2[] = {2, 4, 5, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    MyArray<int> myArr2 = MyArray<int>(arr2, n2);

    MyArray<int> merged = MyArray<int>::merge_sorted_arrays(myArr1, myArr2);
    merged.display();

    int sol[] = {1, 2, 3, 4, 4, 5, 6, 8, 9};
    vector<int> solution_v(std::begin(sol), std::end(sol));

    vector<int> merged_v;
    for (int i = 0; i < merged.length(); i++) {
        merged_v.push_back(merged.get(i));
    }
    EXPECT_EQ(merged_v, solution_v);
}

TEST(ArrayExercises, TwoSum) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> indexes = MyArray<int>::two_sum(nums, target);
    EXPECT_EQ(indexes, vector<int>({0, 1}));
}

TEST(ArrayExercises, MaximumSumSubarray) {
    int sum = MyArray<int>::maximum_sum_subarray(vector<int>{5, 4, -1, 7, 8});
    EXPECT_EQ(sum, 24);
}

TEST(ArrayExercises, RotateArray) {
    vector<int> res = MyArray<int>::rotate_array(vector<int>{1, 2, 3, 4, 5}, 3);
    EXPECT_EQ(res, vector<int>({3, 4, 5, 1, 2}));
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

//    A::functionExample(3);
//    BasicIntroExample::run_example_own_array();


//    MyArray<int>::run_intro();
    MyArray<int>::run_example_own_array();
//    cout << "has_dupl=" << MyArray<int>::contains_duplicates(vector<int>{1, 2, 3, 4, 2, 7}) << endl;

//    MyArray<int>::move_zeros();

//    return 0;
}



