#include "Div.h"

Div::Div() {}

Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Div::calculate() const {
    if (right->calculate() == 0) {
        throw ("can not divid by tero");
    } else {
        return (this->left->calculate() / this->right->calculate());
    }
}