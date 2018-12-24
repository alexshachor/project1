#ifndef PROJECT1_MUL_H
#define PROJECT1_MUL_H

#include "BinaryExpression.h"

class Mul : public BinaryExpression {
public:
    Mul(Expression *left, Expression *right);

    double calculate() const;
};


#endif //PROJECT1_MUL_H
