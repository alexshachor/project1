#include <iostream>
#include "Number.h"

int main() {

    Number *n = new Number(5);
    std::cout << n->calculate() << std::endl;
    return 0;
}