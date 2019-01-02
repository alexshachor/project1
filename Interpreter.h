//
// Created by avi on 1/1/19.
//

#ifndef PROJECT1_INTERPETER_H
#define PROJECT1_INTERPETER_H

#include <vector>
#include "FileHelper.h"

#include "Command.h"
#include "ConditionCommand.h"
#include "BindCommand.h"
#include "ConnectCommand.h"
#include "EqualCommand.h"
#include "IfCommand.h"
#include "OpenDataServerCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "VarCommand.h"
#include <iostream>
#include <fstream>

#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define BIND "bind"
#define EQUAL "="
#define WHILE "while"
#define IF "if"
#define PRINT "print"
#define SLEEP "sleep"
#define VAR "var"
#define OPEN_BRACES "{"
#define CLOSE_BRACES "}"

class Interpreter {
private:
    vector<Command *> commands;
public:
    void lexer(string fileName = "");

    Command *commandFactory(string line);

    Command *parser(vector<string> lines, bool insertToCommands);

    void runCommands(vector<Command *> commands) const;

    ~Interpreter();
};


#endif //PROJECT1_INTERPETER_H
