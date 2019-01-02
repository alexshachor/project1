//
// Created by alexander on 12/26/18.
//

#include "BindCommand.h"

BindCommand::BindCommand(string str) : Command(str) {}

void BindCommand::doCommand() const {

    string line = FileHelper::trim(params);
    //split by = in order to seperate between key-value
    vector<string> splitted = FileHelper::split(line, KEY_VALUE_DELIMITER);
    if (splitted.size() != PARAMS_NUM) {
        throw ("unknown format of bind line");
    }

    string key;
    if (FileHelper::contains(splitted[0], VAR_PREFIX)) {
        vector<string> varKeySplitted;
        //split by space in order to seperate between var and var name
        varKeySplitted = FileHelper::split(FileHelper::trim(splitted[0]), WHITE_SPACE);
        key = FileHelper::trim(varKeySplitted[1]);
    } else {
        key = FileHelper::trim(splitted[0]);
    }
    string path = FileHelper::getParamByPrefix(FileHelper::trim(splitted[1]), BIND_VALUE_PREFIX, BIND_VALUE_SUFFIX);

    if (key.empty() || path.empty()) {
        throw ("missing key or value!");
    }
    //if this isn't a declaration of new var and it doesn't exist in symbol map, throw exception
    if (!FileHelper::contains(line, VAR_PREFIX) && !MapsManagement::isInSymbolTable(key)) {
        throw ("Undeclared var");
    }
    if (FileHelper::contains(line, VAR_PREFIX) && !MapsManagement::isInSymbolTable(key)) {
        MapsManagement::setSymbolTable(key, 0);
    }
    MapsManagement::setBindMap(key, path);
}