//
// Created by alexander on 12/27/18.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(string str) : Command(str) {}

void PrintCommand::doCommand() const {
    string print = "";
    //if should print an expression of form "example"
    if (FileHelper::contains(params, STRING_PREFIX, STRING_SUFFIX)) {
        print = FileHelper::getParamByPrefix(params, STRING_PREFIX, STRING_SUFFIX);
    } else {
        string message = FileHelper::getParamByPrefix(params, MESSAGE_PREFIX);
        print = to_string(ExpressionHelper::getExpressionValue(message));
    }
    cout << print << endl;
}