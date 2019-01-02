//
// Created by alexander on 1/1/19.
//

#ifndef PROJECT1_WHILECOMMAND_H
#define PROJECT1_WHILECOMMAND_H

#include "ConditionCommand.h"

class WhileCommand : public ConditionCommand {
public:
    WhileCommand(string condition, vector<Command *> commands);

    void doCommand() const;
};


#endif //PROJECT1_WHILECOMMAND_H
