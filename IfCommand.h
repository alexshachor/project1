//
// Created by alexander on 1/1/19.
//

#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H

#include "ConditionCommand.h"

class IfCommand : public ConditionCommand {
public:
    IfCommand(string condition, vector<Command *> commands);

    void doCommand() const;
};


#endif //PROJECT1_IFCOMMAND_H
