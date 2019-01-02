//
// Created by alexander on 1/1/19.
//

#include "WhileCommand.h"

WhileCommand::WhileCommand(string condition, vector<Command *> commands) : ConditionCommand(condition, commands) {}

void WhileCommand::doCommand() const {
    while (ConditionCommand::isConditionFulfilled()) {
        ConditionCommand::doCommand();
    }
}