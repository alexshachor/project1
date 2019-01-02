#include "Minus.h"

Minus::Minus() {}
Minus::Minus(Expression *left, Expression *right) :
        BinaryExpression(left, right) {}

double Minus::calculate() const {
    return (this->left->calculate() - this->right->calculate());
}
