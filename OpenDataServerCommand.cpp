#include "OpenDataServerCommand.h"

OpenDataServerCommand::OpenDataServerCommand(string str) : Command(str) {}

void OpenDataServerCommand::doCommand() const {

    string result = FileHelper::getParamByPrefix(params, SERVER_PREFIX);
    vector<string> paramsVec = ExpressionHelper::splitExpression(result);

    if (paramsVec.size() != PARAMS_NUM) {
        throw ("not enough params");
    }

    double port = ExpressionHelper::getExpressionValue(paramsVec[0]);
    double paceInSecond = ExpressionHelper::getExpressionValue(paramsVec[1]);
    DataReaderServer server;
    int args[] = {(int) port, (int) paceInSecond};
    server.runServer(args);
}