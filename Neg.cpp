#include "Neg.h"

Neg::Neg(Expression *expression) : UnaryExpression(expression) {
}

double Neg::calculate() const {
    return -1 * (this->expression->calculate());
}