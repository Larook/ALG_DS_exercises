//
// Created by karol on 21/09/2022.
//

#include <iostream>
#include "A.h"

int A::functionExample(int i) {  // do **not** use `static` here!
    std::cout << i + 2 << std::endl;
    return i + 2;
}