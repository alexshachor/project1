//
// Created by alexander on 12/25/18.
//

#ifndef PROJECT1_CONNECTCOMMAND_H
#define PROJECT1_CONNECTCOMMAND_H

#include "Command.h"
#include "FileHelper.h"
#include "ClientManagement.h"
#include "ExpressionHelper.h"

#define CONNECT_PREFIX "connect "
#define SERVER_IP_INDEX 0
#define SERVER_PORT_INDEX 1
#define PARAMS_NUM 2


class ConnectCommand : public Command {
public:
    ConnectCommand(string str);

    void doCommand() const;
};


#endif //PROJECT1_CONNECTCOMMAND_H
