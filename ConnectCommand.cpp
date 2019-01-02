//
// Created by alexander on 12/25/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(string str) : Command(str) {}

void ConnectCommand::doCommand() const {
    char space = ' ';
    string line = FileHelper::getParamByPrefix(params, CONNECT_PREFIX);

    vector<string> paramsVec = FileHelper::split(line, space);

    if (paramsVec.size() != PARAMS_NUM) {
        throw ("not enough params!");
    }

    string serverIp = paramsVec[SERVER_IP_INDEX];
    int portno = ExpressionHelper::getExpressionValue(paramsVec[SERVER_PORT_INDEX]);
    ClientManagement::connectToServer(serverIp, portno);
}
