//
// Created by alexander on 1/1/19.
//

#ifndef PROJECT1_BOOLEXPRESSION_H
#define PROJECT1_BOOLEXPRESSION_H

#include "BinaryExpression.h"

class BoolExpression : public BinaryExpression {
public:
    BoolExpression(Expression *left, Expression *right);
};

class Greater : public BoolExpression {

public:

    Greater(Expression *left, Expression *right);

    double calculate() const;
};

class Smaller : public BoolExpression {

public:

    Smaller(Expression *left, Expression *right);

    double calculate() const;
};

class Equal : public BoolExpression {

public:

    Equal(Expression *left, Expression *right);

    double calculate() const;
};

class NotEqual : public BoolExpression {

public:

    NotEqual(Expression *left, Expression *right);

    double calculate() const;
};

class GreaterOrEqual : public BoolExpression {

public:

    GreaterOrEqual(Expression *left, Expression *right);

    double calculate() const;
};

class SmallerOrEqual : public BoolExpression {

public:
    SmallerOrEqual(Expression *left, Expression *right);

    double calculate() const;
};


#endif //PROJECT1_BOOLEXPRESSION_H
