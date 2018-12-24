#ifndef PROJECT1_UNARYEXPRESSION_H
#define PROJECT1_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression *expression;
public:
    UnaryExpression(Expression *exper) {
        this->expression = exper;
    }

    ~UnaryExpression() {
        if (this->expression != nullptr) {
            delete this->expression;
        }
    }
};

#endif //PROJECT1_UNARYEXPRESSION_H
