//
// Created by alexander on 12/24/18.
//

#include "ExpressionHelper.h"


vector<string> convertInfixToPostfix(string expression);

int hasHigherPrecedence(char operator1, char operator2);

bool isOperator(char c);

bool isOperand(char c);

bool isLetter(char c);

Expression *evaluateExpression(vector<string> *postfixVec);


vector<string> convertInfixToPostfix(string expression) {
    stack<char> stackStructure;
    char space = ' ', openPren = '(', closePren = ')';
    string postfix = "";
    //scan from left
    for (int i = 0; i < expression.length(); i++) {

        //skip white space
        if (expression[i] == space) {
            continue;
        } else if (isOperator(expression[i])) {
            while (!stackStructure.empty() && stackStructure.top() != openPren &&
                   hasHigherPrecedence(stackStructure.top(), expression[i])) {
                postfix += space;
                postfix += stackStructure.top();
                stackStructure.pop();
            }
            postfix += space;
            stackStructure.push(expression[i]);
        } else if (isOperand(expression[i]) || isLetter(expression[i])) {
            postfix += expression[i];
        } else if (expression[i] == openPren) {
            stackStructure.push(expression[i]);
        } else if (expression[i] == closePren) {
            while (!stackStructure.empty() && stackStructure.top() != openPren) {
                postfix += space;
                postfix += stackStructure.top();
                stackStructure.pop();
            }
            stackStructure.pop();
        }
    }

    while (!stackStructure.empty()) {
        postfix += space;
        postfix += stackStructure.top();
        stackStructure.pop();
    }
    vector<string> result = FileHelper::split(postfix, space);

    return result;
}

bool isOperand(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }

    return false;
}

bool isLetter(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return true;
    }
    return false;
}


int getOperatorWeight(char op) {
    int weight = -1;
    switch (op) {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        default:
            break;
    }
    return weight;
}

int hasHigherPrecedence(char op1, char op2) {
    int op1Weight = getOperatorWeight(op1);
    int op2Weight = getOperatorWeight(op2);
    return op1Weight >= op2Weight;
}

vector<string> ExpressionHelper::splitExpression(string str) {
    vector<string> result;
    string currentExpression;
    char space = ' ', comma = ',', openPren = '(', closePren = ')';
    bool wasSpace = false, wasDigit = false;
    for (char &current : str) {
        if (current == space) {
            wasSpace = true;
            continue;
        }
        if (isOperator(current)) {
            currentExpression += current;
            wasDigit = false;
            wasSpace = false;
        } else {
            bool isNewExpression = (current != closePren && wasSpace && wasDigit) || current == comma;
            if (isNewExpression) {
                wasSpace = false;
                wasDigit = false;
                result.push_back(currentExpression);
                currentExpression = "";
                if (current != comma) {
                    currentExpression += current;
                }
            } else {
                wasSpace = false;
                if (current != openPren) {
                    wasDigit = true;
                }
                currentExpression += current;
            }
        }
    }
    if (!currentExpression.empty()) {
        result.push_back(currentExpression);
    }
    return result;
}

Expression *evaluateExpression(vector<string> *postfixVec) {
    if (postfixVec->empty()) {
        return new Number(0);
    }
    string current = postfixVec->back();
    postfixVec->pop_back();
    BinaryExpression *binaryExpression;
    bool isOperator = false;
    if (current == "+") {
        binaryExpression = new Plus();
        isOperator = true;
    }
    if (current == "-") {
        binaryExpression = new Minus();
        isOperator = true;
    }
    if (current == "*") {
        binaryExpression = new Mul();
        isOperator = true;
    }
    if (current == "/") {
        binaryExpression = new Div();
        isOperator = true;
    }
    if (isOperator) {
        Expression *right = evaluateExpression(postfixVec);
        Expression *left = evaluateExpression(postfixVec);
        binaryExpression->setExpressions(left, right);
        return binaryExpression;
    } else {
        if (isLetter(current[0])) {
            return new VarExpression(current);
        } else {
            return new Number(stod(current));
        }
    }
}

Expression *ExpressionHelper::getExpressionByStr(string expressionStr) {
    string str = FileHelper::trim(expressionStr);
    vector<string> postfixVec = convertInfixToPostfix(str);
    Expression *result = evaluateExpression(&postfixVec);
    return result;
}


double ExpressionHelper::getExpressionValue(string expressionStr) {
    double result;
    Expression *expression = ExpressionHelper::getExpressionByStr(expressionStr);
    if (expression != nullptr) {
        result = expression->calculate();
        delete expression;
    }
    return result;
}

Expression *ExpressionHelper::getBoolExpressionByStr(string str) {
    vector<string> bothExpressions;
    if (FileHelper::contains(str, GREATER_OR_EQUAL)) {
        bothExpressions = FileHelper::splitByStr(str, GREATER_OR_EQUAL);
        return new GreaterOrEqual(getExpressionByStr(bothExpressions[0]), getExpressionByStr(bothExpressions[1]));
    }
    if (FileHelper::contains(str, GREATER)) {
        bothExpressions = FileHelper::splitByStr(str, GREATER);
        return new Greater(getExpressionByStr(bothExpressions[0]), getExpressionByStr(bothExpressions[1]));
    }
    if (FileHelper::contains(str, SMALLER_OR_EQUAL)) {
        bothExpressions = FileHelper::splitByStr(str, SMALLER_OR_EQUAL);
        return new SmallerOrEqual(getExpressionByStr(bothExpressions[0]), getExpressionByStr(bothExpressions[1]));
    }
    if (FileHelper::contains(str, SMALLER)) {
        bothExpressions = FileHelper::splitByStr(str, SMALLER);
        return new Smaller(getExpressionByStr(bothExpressions[0]), getExpressionByStr(bothExpressions[1]));
    }
    if (FileHelper::contains(str, EQUAL_EQUAL)) {
        bothExpressions = FileHelper::splitByStr(str, EQUAL_EQUAL);
        return new Equal(getExpressionByStr(bothExpressions[0]), getExpressionByStr(bothExpressions[1]));
    }
    if (FileHelper::contains(str, NOT_EQUAL)) {
        bothExpressions = FileHelper::splitByStr(str, NOT_EQUAL);
        return new NotEqual(getExpressionByStr(bothExpressions[0]), getExpressionByStr(bothExpressions[1]));
    } else {
        throw ("unknown bool expression format");
    }
}