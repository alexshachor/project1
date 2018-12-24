#ifndef PROJECT1_NUMBER_H
#define PROJECT1_NUMBER_H

#include "Expression.h"

class Number : public Expression {
private:
    double number;
public:
    Number(double number);

    double calculate() const;
};


#endif //PROJECT1_NUMBER_H
