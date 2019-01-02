//
// Created by alexander on 1/1/19.
//

#ifndef PROJECT1_VAREXPRESSION_H
#define PROJECT1_VAREXPRESSION_H

#include "Expression.h"
#include <string>
#include "MapsManagement.h"
#include "FileHelper.h"

using namespace std;

class VarExpression : public Expression {
private:
    string var;
public:
    VarExpression(string str);

    double calculate() const;
};


#endif //PROJECT1_VAREXPRESSION_H
