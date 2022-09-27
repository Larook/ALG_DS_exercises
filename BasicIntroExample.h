//
// Created by karol on 21/09/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_BASICINTROEXAMPLE_H
#define ALGORITHMS_DATASTRUCTURES_BASICINTROEXAMPLE_H


using namespace std;

class BasicIntroExample{
public:
    static void O_n_linear_array_search_example();
    static void run_example();
};


class ConsoleInterface{
public:
    string message;
    ConsoleInterface(string _message){
        message = _message;
    }

    void printout(){ cout << message << endl; }
};



#endif //ALGORITHMS_DATASTRUCTURES_BASICINTROEXAMPLE_H
