#ifndef PROJECT1_OPENDATASERVERCOMMAND_H
#define PROJECT1_OPENDATASERVERCOMMAND_H

#define PARAMS_NUM 2
#define SERVER_PREFIX "OpenDataServer "

#include "Command.h"
#include "DataReaderServer.h"
#include "FileHelper.h"
#include "ExpressionHelper.h"

class OpenDataServerCommand : public Command {
public:
    OpenDataServerCommand(string str);

    void doCommand() const;
};

#endif //PROJECT1_OPENDATASERVERCOMMAND_H