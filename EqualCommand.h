//
// Created by alexander on 12/26/18.
//

#ifndef PROJECT1_EQUALCOMMAND_H
#define PROJECT1_EQUALCOMMAND_H

#include "Command.h"
#include "FileHelper.h"
#include "MapsManagement.h"
#include "ClientManagement.h"
#include "ExpressionHelper.h"

#define SEND_MESSAGE_PREFIX "SET "
#define NEW_LINE "\r\n"
#define VAR_PREFIX "var "
#define VALUE_PREFIX "="
#define EQUAL_DELIMITER '='
#define PARAMS_NUM 2

class EqualCommand : public Command {
public:
    EqualCommand(string str);

    void doCommand() const;
};


#endif //PROJECT1_EQUALCOMMAND_H
