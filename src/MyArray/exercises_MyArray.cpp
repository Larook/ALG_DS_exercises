//
// Created by karol on 22/09/2022.
//
#include <MyArray/MyArray.h>

using namespace std;


template<typename T>
T MyArray<T>::reverseArray(T input) {
    T *inputP = &input;
    int n = sizeof(input);// / sizeof(input[0]);
    int bitsPerChar = 4;
    cout << "n=" << n << endl;
    for (int i = 0; i <= n; i += bitsPerChar) {
        cout << "i" << i << ": " << *(inputP + i) << endl;
    }
    return input;
}


template<>
string MyArray<int>::string_reversal(string input, int n) {
//    const char input[100] = "example";
//    cout << input << endl;
//    char input2[100] = "example";
//    cout << input2 << endl;
//    const char* input3 = "example";
//    cout << input3 << endl;

//    const char *reversed_input = MyArray<const char *>::reverseArray(input);
//    string reversed_input = MyArray<string>::reverseArray(input);

    string reversed_input;
    for (int i = n - 1; i >= 0; i--) {
        reversed_input.push_back(input[i]);
//        cout << "i=" << i << ": " << input[i] << endl;
    }
    cout << "reversed_input = " << reversed_input.data() << endl;
    return reversed_input;
}

template<>
MyArray<int> MyArray<int>::merge_sorted_arrays(MyArray<int> myArr1, MyArray<int> myArr2) {
    /*
     * given 2 arrays -- [0,1,3,4,6,8] and [2,4,5,9]
     * that are already sorted arrays
     * return merged sorted array
     * use objects of MyArray class to use pop()
     */
//    int arr1[] = {1, 3, 4, 6, 8};
//    MyArray<int> myArr1 = MyArray<int>(arr1, n1);
//
//    int arr2[] = {2, 4, 5, 9};
//    MyArray<int> myArr2 = MyArray<int>(arr2, n2);


    MyArray<int> merged;
    bool finished = false;
    // loop until finished -- for every iteration compare which of arr1 or arr2 has lowest first element, then pop
    while (!finished) {
        int lowest1 = myArr1.get(0);    //O(1)
        int lowest2 = myArr2.get(0);    //O(1)
        if (lowest1 < lowest2 && myArr1.length() != 0) {
            merged.push(myArr1.pop(0));    //pop=O(n)   push=O(1)
        } else if (myArr2.length() != 0) {
            merged.push(myArr2.pop(0));    //pop=O(n)   push=O(1)
        } else { finished = true; }
    }
    // total O(n*i), where i is the number of sorted arrays
    return merged;
}

template<>
vector<int> MyArray<int>::two_sum(vector<int> nums, int target) {
    /*
     * given nums = [2,7,11,15] and target = 9
     * return 2 indexes that their sum return the target
     *
     * create an array of differences
     * check if there is a difference in num
     */

    vector<int> indexes;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; i < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                cout << "found" << endl;
                indexes.push_back(i);
                indexes.push_back(j);
                goto indexes_found;
//                break;
            }
        }
    }
    indexes_found:

    for (const auto &num: nums) { cout << num << ' '; }
    cout << "indexes = " << indexes[0] << ", " << indexes[1] << endl;


    return indexes;
}

template<typename T>
void MyArray<T>::two_sum2() {
    /*
     * given nums = [2,7,11,15] and target = 9
     * return 2 indexes that their sum return the target
     *
     * create an array of differences
     * check if there is a difference in num
     */
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> diffs = {0, 0, 0, 0};
    int i1, i2;

    // create an array of differences
    for (int i = 0; i < nums.size(); i++) {
        diffs[i] = target - nums[i];
    }

    // check if there is a difference in num
    if (std::any_of(diffs.begin(), diffs.end(), target)) {
        cout << "found the target" << endl;
    }
//    for (int i=0; i < diffs.size(); i++) {
//    for (int &diff : diffs) {
//        if (diff == target){
//            cout << "found the target" << endl;
//        }
//    }

}

template<>
int MyArray<int>::maximum_sum_subarray(vector<int> nums) {
    /* {5, 4, -1, 7, 8}
     * sort the nums  // O(nlogn)
     * go from beginning and sum (if the number is not minus then add)
     */
    cout << "input" << endl;
    for (const auto &num: nums) { cout << num << ' '; }
    cout << endl;

    // -------------------- O(nlogn) solution
//    // sort
//    sort(nums.begin(), nums.end(), greater<int>());  // O(nlogn)
//
//    cout << "sorted" << endl;
//    for (const auto& num: nums) { cout << num << ' '; }
//
//    int sum = 0;
//    for (const auto& num: nums) {
//        if (num > 0) { sum += num;}
//        else{ break;}
//    }
//    cout << "sum = " << sum << endl;
//    return sum;


//    /*
//     * -------------------- O(n)
//     *  check if the following element increases the sum
//     */
    int sum_now = 0;
    int sum_max = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum_now = sum_max + nums[i];
        sum_max = max(sum_max, sum_now);
        cout << "sum max = " << sum_max << endl;
    }
    return sum_max;

    /*
     * -------------------- Divide and Conquer
     * (Divide) maximum subarray lies somewhere in the:
     *      left-half of array
     *      right-half of array
     *      mid element with some part of the l-h and some of the r-h
     * (Conquer) solving problem recursively
     * (Combine) the solutions to the subproblems into the solution for the original problem
     */
//    int a = nums.size();
////    return max_subarray_rec(nums, 0, nums.size()-1);
//    return MyArray<int>::max_subarray_rec(nums, 0, a - 1);

}

template<typename T>
int MyArray<T>::max_subarray_rec(vector<int> A, int id_l, int id_r) {
    cout << "h" << endl;
    if (id_l > id_r) return -999999999;  // search went through everything
//    if (id_l == id_r) return A[id_l];  // search went through everything
    int sum_l = 0, sum_r = 0;  // sum_l = max subarray sum in [id_l, id_mid]
    int id_mid = (id_l + id_r) / 2;  // middle index

    // sum left
    int sum_curr = 0;
    for (int i = id_mid - 1, sum_curr = 0; i >= id_l; i--) { // go left from the middle
        sum_curr += A[i];
        sum_l = max(sum_curr, sum_l);
    }
    // sum right
    sum_curr = 0;
    for (int i = id_mid + 1, sum_curr = 0; i <= id_r; i++) { // go left from the middle
        sum_curr += A[i];
        sum_r = max(sum_curr, sum_r);
    }

    // return max of 3 cases -- either current left or right, or divide into smaller problems again recursively
    int sol_this = sum_l + sum_r + A[id_mid];
    int sol_div_r = MyArray<T>::max_subarray_rec(A, id_mid + 1, id_r);
    int sol_div_l = MyArray<T>::max_subarray_rec(A, id_l, id_mid - 1);
    if ((sol_this == 23) || (sol_div_r == 23) || (sol_div_l == 23)) {
        cout << "heyy" << endl;
    }
    int sol_max = max({sol_this, sol_div_r, sol_div_l});
    return sol_max;
//    return max({sum_l+sum_r + A[id_mid], MyArray<T>::max_subarray(A, id_mid+1, id_r), MyArray<T>::max_subarray_rec(A, id_l, id_mid-1)});
}


template<typename T>
bool MyArray<T>::contains_duplicates(vector<int> A) {
//    /*
//     * check sorted array
//     * look for duplicates -- the same as the previous
//     */
//    sort(A.begin(), A.end());  //O(nlogn)
//
//    int prev_val = A[0];
//    for (int i=1; i<A.size(); i++){
//        if (prev_val == A[i]){
//            return true;
//        }
//        prev_val = A[i];
//    }
//    return false;

    /*
     * hash map solution
     * O(n) time complexity
     */
    unordered_set<int> unique; // = new hash<int>();
//    unordered_map<int, int> unique; // = new hash<int>();

    for (int num : A) {
        int cnt = unique.count(num);
        if (cnt > 0) {
            return true;
        }
        unique.insert(num);
    }
    return false;
}


template<>
vector<int> MyArray<int>::rotate_array(vector<int> A, int k) {
    /*
     * rotate the array to the right by k steps
     * 1 - iterate over array and swap
     *
     * 2 - create temp array, copy the indexes, probably O(n) complexity
     */
    vector<int> rotated;
    int n = A.size();
    int j = 0;
    for (int i = k - 1; j < n; i++, j++) {
        if (i >= n) { i -= n; }
        rotated.insert(rotated.begin() + j, A[i]);
    }

    for (auto t : rotated) {
        cout << t << endl;
    }
    return rotated;
}

