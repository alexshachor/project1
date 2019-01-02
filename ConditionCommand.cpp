//
// Created by alexander on 1/1/19.
//

#include "ConditionCommand.h"

string extractCondition(string params) {
    string conditionStr, prefix, suffix;
    if (FileHelper::contains(params, PARENTHESES_PREFIX, PARENTHESES_SUFFIX)) {
        prefix = PARENTHESES_PREFIX;
        suffix = PARENTHESES_SUFFIX;
    } else {
        if (FileHelper::contains(params, IF_PREFIX)) {
            prefix = IF_PREFIX;
        } else {
            prefix = WHILE_PREFIX;
        }
        if (FileHelper::contains(params, CURLY_BRACKETS_SUFFIX)) {
            suffix = CURLY_BRACKETS_SUFFIX;
        }
    }
    conditionStr = FileHelper::getParamByPrefix(params, prefix, suffix);
    return conditionStr;
}


ConditionCommand::ConditionCommand(string condition, vector<Command *> commands) : Command(
        extractCondition(condition)) {
    this->commands = commands;
}

void ConditionCommand::doCommand() const {
    for (int i = 0; i < commands.size(); ++i) {
        commands[i]->doCommand();
    }
}


bool ConditionCommand::isConditionFulfilled() const {
    bool result = false;
    Expression *boolExpression = ExpressionHelper::getBoolExpressionByStr(params);
    if (boolExpression != nullptr) {
        double boolResult = boolExpression->calculate();
        if (boolResult) {
            result = true;
        }
        delete boolExpression;
    }
    return result;
}

ConditionCommand::~ConditionCommand() {
    for (vector<Command *>::iterator it = commands.begin(); it != commands.end(); ++it) {
        delete (*it);
    }
}