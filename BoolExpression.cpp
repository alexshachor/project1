//
// Created by alexander on 1/1/19.
//

#include "BoolExpression.h"

BoolExpression::BoolExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}

//class Greater
Greater::Greater(Expression *left, Expression *right) : BoolExpression(left, right) {}

double Greater::calculate() const {
    return left->calculate() > right->calculate();
}

//class Smaller
Smaller::Smaller(Expression *left, Expression *right) : BoolExpression(left, right) {}

double Smaller::calculate() const {
    return left->calculate() < right->calculate();
}

//class Equal
Equal::Equal(Expression *left, Expression *right) : BoolExpression(left, right) {}

double Equal::calculate() const {
    return left->calculate() == right->calculate();
}

//class NotEqual
NotEqual::NotEqual(Expression *left, Expression *right) : BoolExpression(left, right) {}

double NotEqual::calculate() const {
    return left->calculate() != right->calculate();
}

//class GreaterOrEqual
GreaterOrEqual::GreaterOrEqual(Expression *left, Expression *right) : BoolExpression(left, right) {}

double GreaterOrEqual::calculate() const {
    return left->calculate() >= right->calculate();
}

//class SmallerOrEqual
SmallerOrEqual::SmallerOrEqual(Expression *left, Expression *right) : BoolExpression(left, right) {}

double SmallerOrEqual::calculate() const {
    return left->calculate() <= right->calculate();
}