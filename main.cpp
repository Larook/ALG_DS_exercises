
#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <vector>

#include "BasicIntroExample.h"
#include "A.h"
#include "MyArray.h"
#include "exercises_MyArray.cpp"

using namespace std;


int main() {

//    A::functionExample(3);
//    BasicIntroExample::run_example_own_array();


//    MyArray<int>::run_intro();
//    MyArray<int>::run_example_own_array();
//    MyArray<int>::string_reversal();
//    MyArray<int>::merge_sorted_arrays();
//    MyArray<int>::two_sum(vector<int>{2,7,11, 15}, 9);
//      cout << "sol=" << MyArray<int>::maximum_sum_subarray(vector<int>{5, 4, -1, 7, 8}) << endl;
//    cout << "has_dupl=" << MyArray<int>::contains_duplicates(vector<int>{1, 2, 3, 4, 2, 7}) << endl;

//    MyArray<int>::move_zeros();
    vector<int> res = MyArray<int>::rotate_array(vector<int>{1,2,3,4,5}, 3);

    return 0;
}


