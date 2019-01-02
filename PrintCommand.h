//
// Created by alexander on 12/27/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include "Command.h"
#include "FileHelper.h"
#include "ExpressionHelper.h"
#include <iostream>

#define STRING_PREFIX "\""
#define STRING_SUFFIX "\""
#define MESSAGE_PREFIX "print "


class PrintCommand : public Command {
public:
    PrintCommand(string str);

    void doCommand() const;
};


#endif //PROJECT1_PRINTCOMMAND_H
