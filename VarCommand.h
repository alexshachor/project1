//
// Created by avi on 1/2/19.
//

#ifndef PROJECT1_VARCOMMAND_H
#define PROJECT1_VARCOMMAND_H

#include "Command.h"
#include "MapsManagement.h"
#include "FileHelper.h"

#define VAR_PREFIX "var "

class VarCommand : public Command {
public:
    VarCommand(string line);

    void doCommand() const;
};


#endif //PROJECT1_VARCOMMAND_H
