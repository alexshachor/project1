//
// Created by alexander on 1/1/19.
//

#ifndef PROJECT1_CONDITIONCOMMAND_H
#define PROJECT1_CONDITIONCOMMAND_H

#include "Command.h"
#include "ExpressionHelper.h"

#define IF_PREFIX "if"
#define WHILE_PREFIX "while"
#define CURLY_BRACKETS_SUFFIX "{"
#define PARENTHESES_PREFIX "("
#define PARENTHESES_SUFFIX ")"


class ConditionCommand : public Command {
private:
    vector<Command *> commands;
public:
    ConditionCommand(string condition, vector<Command *> commands);

    void doCommand() const;

    bool isConditionFulfilled() const;

    ~ConditionCommand();
};


#endif //PROJECT1_CONDITIONCOMMAND_H