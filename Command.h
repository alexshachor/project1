//
// Created by alexander on 12/25/18.
//

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <vector>
#include <string>

using namespace std;

class Command {
protected:
    string params;
public:
    Command(string str) {
        this->params = str;
    }

    virtual void doCommand() const = 0;
};


#endif //PROJECT1_COMMAND_H
