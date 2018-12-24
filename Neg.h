
#ifndef PROJECT1_NEG_H
#define PROJECT1_NEG_H

#include "UnaryExpression.h"

class Neg : public UnaryExpression {
public:
    Neg(Expression *expression);

    double calculate() const;
};


#endif //PROJECT1_NEG_H
