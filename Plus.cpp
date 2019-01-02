#include "Plus.h"

Plus::Plus() {}
Plus::Plus(Expression *left, Expression *right) :
        BinaryExpression(left, right) {}

double Plus::calculate() const {
    return (this->left->calculate() + this->right->calculate());
}