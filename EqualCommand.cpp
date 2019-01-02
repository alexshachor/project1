//
// Created by alexander on 12/26/18.
//

#include "EqualCommand.h"

EqualCommand::EqualCommand(string str) : Command(str) {}

void EqualCommand::doCommand() const {

    string line = FileHelper::trim(params);
    //split by = in order to seperate between key-value
    vector<string> splitted = FileHelper::split(line, EQUAL_DELIMITER);
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

    if (key.empty()) {
        throw ("key not found");
    }
    //if this isn't a declaration of new var and it doesn't exist in symbol map, throw exception
    if (!FileHelper::contains(line, VAR_PREFIX) && !MapsManagement::isInSymbolTable(key)) {
        throw ("Undeclared var");
    }
    string expression = FileHelper::getParamByPrefix(FileHelper::trim(splitted[1]), VALUE_PREFIX);
    if (expression.empty()) {
        throw ("value not found");
    }
    double value = ExpressionHelper::getExpressionValue(expression);

    MapsManagement::setSymbolTable(key, value);
    if (MapsManagement::isInBindMap(key)) {
        string path = MapsManagement::getBindMap(key);
        string message = SEND_MESSAGE_PREFIX + path + WHITE_SPACE + to_string(value) + NEW_LINE;
        ClientManagement::sendMessage(message);
    }
}