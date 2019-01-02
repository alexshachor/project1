//
// Created by avi on 1/1/19.
//

#include "Interpreter.h"

Command *Interpreter::commandFactory(string line) {
    if (FileHelper::contains(line, OPEN_DATA_SERVER)) {
        return new OpenDataServerCommand(line);
    }
    if (FileHelper::contains(line, CONNECT)) {
        return new ConnectCommand(line);
    }
    if (FileHelper::contains(line, VAR, BIND)) {
        return new BindCommand(line);
    }
    if (FileHelper::contains(line, PRINT)) {
        return new PrintCommand(line);
    }
    if (FileHelper::contains(line, SLEEP)) {
        return new SleepCommand(line);
    }
    if (FileHelper::contains(line, EQUAL)) {
        return new EqualCommand(line);
    }
    if (FileHelper::contains(line, VAR)) {
        return new VarCommand(line);
    } else {
        throw ("unknown command");
    }
}

Command *Interpreter::parser(vector<string> lines, bool insertToCommands) {
    vector<Command *> commandsVec;
    int i = 0;
    if (!insertToCommands) {
        i = 1;
    }
    for (; i < lines.size(); ++i) {

        if (FileHelper::contains(lines[i], WHILE) || FileHelper::contains(lines[i], IF)) {
            vector<string> conditionLines;
            int bracesCounter = 0;
            while (!FileHelper::contains(lines[i], CLOSE_BRACES) || bracesCounter != 1) {
                if (FileHelper::contains(lines[i], OPEN_BRACES)) {
                    bracesCounter++;
                }
                if (FileHelper::contains(lines[i], CLOSE_BRACES)) {
                    bracesCounter--;
                }
                conditionLines.push_back(lines[i]);
            }
            conditionLines.push_back(lines[i]);
            commandsVec.push_back(parser(conditionLines, false));
        } else {
            commandsVec.push_back(commandFactory(lines[i]));
        }
    }
    if (insertToCommands) {
        this->commands = commandsVec;
    } else if (FileHelper::contains(lines[0], WHILE)) {
        return new WhileCommand(lines[0], commandsVec);
    } else if (FileHelper::contains(lines[0], IF)) {
        return new IfCommand(lines[0], commandsVec);
    }
    return nullptr;
}

void Interpreter::lexer(string fileName) {
    streambuf *cinbuf = nullptr;
    if (!fileName.empty()) {
        ifstream in(fileName);
        //save old buf
        cinbuf = std::cin.rdbuf();
        //redirect cin to input file
        cin.rdbuf(in.rdbuf());
    }
    string line;
    vector<string> allLines;
    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }
        allLines.push_back(line);
    }
    if (cinbuf != nullptr) {
        //reset to standard input again
        std::cin.rdbuf(cinbuf);
    }
    parser(allLines, true);
}

void Interpreter::runCommands(vector<Command *> commands) const {
    for (int i = 0; i < commands.size(); ++i) {
        commands[i]->doCommand();
    }
}

Interpreter::~Interpreter() {
    for (int i = 0; i < commands.size(); ++i) {
        delete commands[i];
    }
}
