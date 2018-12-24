#include "Number.h"

Number::Number(double number) {
    this->number = number;
}

double Number::calculate() const {
    return this->number;
}
