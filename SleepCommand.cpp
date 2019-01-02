//
// Created by alexander on 12/31/18.
//

#include "SleepCommand.h"

SleepCommand::SleepCommand(string str) : Command(str) {}

void SleepCommand::doCommand() const {
    string result = FileHelper::getParamByPrefix(params, SLEEP_PREFIX);
    double sleepFor = ExpressionHelper::getExpressionValue(result);
    chrono::milliseconds dura((long) sleepFor);
    this_thread::sleep_for(dura);
}