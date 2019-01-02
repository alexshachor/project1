#ifndef PROJECT1_BINARYEXPRESSION_H
#define PROJECT1_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;

public:
    BinaryExpression() {}
    BinaryExpression(Expression *left, Expression *right) {
        this->left = left;
        this->right = right;
    }

    void setExpressions(Expression *left, Expression *right) {
        this->left = left;
        this->right = right;
    }

    ~BinaryExpression() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    }
};

#endif //PROJECT1_BINARYEXPRESSION_H
