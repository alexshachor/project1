//
// Created by alexander on 12/31/18.
//

#ifndef PROJECT1_SLEEPCOMMAND_H
#define PROJECT1_SLEEPCOMMAND_H

#include "Command.h"
#include "ExpressionHelper.h"
#include <chrono>
#include <thread>

#define SLEEP_PREFIX "sleep "

class SleepCommand : public Command {
public:
    SleepCommand(string str);

    void doCommand() const;
};


#endif //PROJECT1_SLEEPCOMMAND_H
