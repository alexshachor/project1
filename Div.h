#ifndef PROJECT1_DIV_H
#define PROJECT1_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div();
    Div(Expression *left, Expression *right);

    double calculate() const;

};


#endif //PROJECT1_DIV_H
