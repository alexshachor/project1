//
// Created by avi on 1/2/19.
//

#include "VarCommand.h"

VarCommand::VarCommand(string line) : Command(line) {}

void VarCommand::doCommand() const {
    string key = FileHelper::getParamByPrefix(params, VAR_PREFIX);
    if (key.empty()) {
        throw ("cannot find var name");
    }
    MapsManagement::setSymbolTable(key, 0);
}