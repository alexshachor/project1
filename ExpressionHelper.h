//
// Created by alexander on 12/24/18.
//

#ifndef PROJECT1_EXPRESSIONHELPER_H
#define PROJECT1_EXPRESSIONHELPER_H

#include <string>
#include "Expression.h"
#include<stack>
#include "FileHelper.h"
#include "MapsManagement.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Number.h"
#include "BoolExpression.h"
#include "VarExpression.h"

#define GREATER ">"
#define GREATER_OR_EQUAL ">="
#define SMALLER "<"
#define SMALLER_OR_EQUAL "<="
#define EQUAL_EQUAL "=="
#define NOT_EQUAL "!="


using namespace std;

class ExpressionHelper {

public:

    static vector<string> splitExpression(string str);

    static Expression *getExpressionByStr(string str);

    static double getExpressionValue(string str);

    static Expression *getBoolExpressionByStr(string str);
};


#endif //PROJECT1_EXPRESSIONHELPER_H
