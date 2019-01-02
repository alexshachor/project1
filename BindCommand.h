//
// Created by alexander on 12/26/18.
//

#ifndef PROJECT1_BINDCOMMAND_H
#define PROJECT1_BINDCOMMAND_H

#include "Command.h"
#include "MapsManagement.h"
#include "FileHelper.h"

#define VAR_PREFIX "var "
#define KEY_VALUE_DELIMITER '='
#define BIND_VALUE_PREFIX "\""
#define BIND_VALUE_SUFFIX "\""
#define  PARAMS_NUM 2


class BindCommand : public Command {
public:
    BindCommand(string str);

    void doCommand() const;
};


#endif //PROJECT1_BINDCOMMAND_H
