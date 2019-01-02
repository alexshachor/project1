//
// Created by avi on 12/24/18.
//

#ifndef PROJECT1_MINUS_H
#define PROJECT1_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus();
    Minus(Expression *left, Expression *right);

    double calculate() const;
};


#endif //PROJECT1_MINUS_H
