#ifndef PROJECT1_PLUS_H
#define PROJECT1_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus();
    Plus(Expression *left, Expression *right);

    double calculate() const;
};

#endif //PROJECT1_PLUS_H
