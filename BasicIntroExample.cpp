//
// Created by karol on 21/09/2022.
//

#include <iostream>
#include <ctime>
#include <iomanip>
#include "BasicIntroExample.h"

//using namespace std;

void BasicIntroExample::O_n_linear_array_search_example(){
    /*
     * O(n) where n is just number of elements in an array
     * Usually search is linear, but the number of elements might be huge, so it's better just to
     * most common notation
     */

    time_t start_t, end_t;
    string arr[5] = {"fish", "shark", "medusa", "Nemo", "Alex"};
    string look_for = "Nemo";
    time(&start_t);
    int len = sizeof(arr) / sizeof(string);
    for (int i=0; i<len; i++){
        cout << arr[i] << endl;
        if (arr[i] == look_for){
            cout << "Nemo found!" << endl;
        }
    }
    time(&end_t);
    double taken_t = double(end_t - start_t);
    cout << "taken_t = " << taken_t << setprecision(5) << endl;
}

void BasicIntroExample::run_example(){
    string info = "this is example msg from class";
    ConsoleInterface console(info);
    console.printout();
    O_n_linear_array_search_example();
}



