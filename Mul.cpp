#include "Mul.h"

Mul::Mul() {}
Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Mul::calculate() const {
    return (this->left->calculate() * this->right->calculate());
}