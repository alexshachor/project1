//
// Created by alexander on 1/1/19.
//

#include "IfCommand.h"

IfCommand::IfCommand(string condition, vector<Command *> commands) : ConditionCommand(condition, commands) {}

void IfCommand::doCommand() const {
    if (ConditionCommand::isConditionFulfilled()) {
        ConditionCommand::doCommand();
    }
}