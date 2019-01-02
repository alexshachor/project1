//
// Created by alexander on 1/1/19.
//

#include "VarExpression.h"

VarExpression::VarExpression(string str) {
    this->var = FileHelper::trim(str);
}

double VarExpression::calculate() const {

    //if it doesn't exist in symbol map, throw exception
    if (!MapsManagement::isInSymbolTable(this->var)) {
        throw ("Undeclared var");
    }
    double result = MapsManagement::getSymbolTable(this->var);
    return result;
}