#include "MapsManagement.h"

map<string, double> MapsManagement::pathValueMap;
map<string, double> MapsManagement::symbolTable;
map<string, string> MapsManagement::bindMap;


double MapsManagement::getValueByPath(string path) {
    return MapsManagement::pathValueMap[path];
}

double MapsManagement::getSymbolTable(string key) {
    return MapsManagement::symbolTable[key];
}

string MapsManagement::getBindMap(string key) {
    return MapsManagement::bindMap[key];
}


void MapsManagement::setPathValue(string path, double value) {
    MapsManagement::pathValueMap[path] = value;
}

void MapsManagement::setSymbolTable(string key, double value) {
    MapsManagement::symbolTable[key] = value;
}

void MapsManagement::setBindMap(string var, string path) {
    MapsManagement::bindMap[var] = path;
}

bool MapsManagement::isInPathValueMap(string path) {
    bool result = false;
    if (MapsManagement::pathValueMap.count(path)) {
        result = true;
    }
    return result;
}

bool MapsManagement::isInSymbolTable(string key) {
    bool result = false;
    if (MapsManagement::symbolTable.count(key)) {
        result = true;
    }
    return result;
}

bool MapsManagement::isInBindMap(string key) {
    bool result = false;
    if (MapsManagement::bindMap.count(key)) {
        result = true;
    }
    return result;
}


map<string, string> MapsManagement::getBindMap() {
    return MapsManagement::bindMap;
}

void MapsManagement::updateSymbolTable(vector<string> updateParams) {

    MapsManagement::setPathValue
            ("/instrumentation/airspeed-indicator/indicated-speed-kt",
             stod(updateParams.at(0)));
    MapsManagement::setPathValue
            ("/instrumentation/altimeter/indicated-altitude-ft",
             stod(updateParams.at(1)));
    MapsManagement::setPathValue
            ("/instrumentation/altimeter/pressure-alt-ft",
             stod(updateParams.at(2)));
    MapsManagement::setPathValue
            ("/instrumentation/attitude-indicator/indicated-pitch-deg",
             stod(updateParams.at(3)));
    MapsManagement::setPathValue
            ("/instrumentation/attitude-indicator/indicated-roll-deg",
             stod(updateParams.at(4)));
    MapsManagement::setPathValue
            ("/instrumentation/attitude-indicator/internal-pitch-deg",
             stod(updateParams.at(5)));
    MapsManagement::setPathValue
            ("/instrumentation/attitude-indicator/internal-roll-deg",
             stod(updateParams.at(6)));
    MapsManagement::setPathValue
            ("/instrumentation/encoder/indicated-altitude-ft",
             stod(updateParams.at(7)));
    MapsManagement::setPathValue
            ("/instrumentation/encoder/pressure-alt-ft",
             stod(updateParams.at(8)));
    MapsManagement::setPathValue
            ("/instrumentation/gps/indicated-altitude-ft",
             stod(updateParams.at(9)));
    MapsManagement::setPathValue
            ("/instrumentation/gps/indicated-ground-speed-kt",
             stod(updateParams.at(10)));
    MapsManagement::setPathValue
            ("/instrumentation/gps/indicated-vertical-speed",
             stod(updateParams.at(11)));
    MapsManagement::setPathValue
            ("/instrumentation/heading-indicator/indicated-heading-deg",
             stod(updateParams.at(12)));
    MapsManagement::setPathValue
            ("/instrumentation/magnetic-compass/indicated-heading-deg",
             stod(updateParams.at(13)));
    MapsManagement::setPathValue
            ("/instrumentation/slip-skid-ball/indicated-slip-skid",
             stod(updateParams.at(14)));
    MapsManagement::setPathValue
            ("/instrumentation/turn-indicator/indicated-turn-rate",
             stod(updateParams.at(15)));
    MapsManagement::setPathValue
            ("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
             stod(updateParams.at(16)));
    MapsManagement::setPathValue("/controls/flight/aileron",
                                 stod(updateParams.at(17)));
    MapsManagement::setPathValue("/controls/flight/elevator",
                                 stod(updateParams.at(18)));
    MapsManagement::setPathValue("/controls/flight/rudder",
                                 stod(updateParams.at(19)));
    MapsManagement::setPathValue("/controls/flight/flaps",
                                 stod(updateParams.at(20)));
    MapsManagement::setPathValue
            ("/controls/engines/current-engine/throttle",
             stod(updateParams.at(21)));
    MapsManagement::setPathValue("/engines/engine/rpm",
                                 stod(updateParams.at(22)));
    for (auto it = MapsManagement::bindMap.begin();
         it != MapsManagement::bindMap.end(); ++it) {
        if (MapsManagement::isInSymbolTable(it->first)) {
            MapsManagement::setSymbolTable(it->first,
                                           MapsManagement::getValueByPath(it->second));
        }
    }
}

void MapsManagement::pathValueInit() {
    MapsManagement::setPathValue("/instrumentation/airspeed-indicator/indicated-speed-kt", 0);
    MapsManagement::setPathValue("/instrumentation/altimeter/indicated-altitude-ft", 0);
    MapsManagement::setPathValue("/instrumentation/altimeter/pressure-alt-ft", 0);
    MapsManagement::setPathValue("/instrumentation/attitude-indicator/indicated-pitch-deg", 0);
    MapsManagement::setPathValue("/instrumentation/attitude-indicator/indicated-roll-deg", 0);
    MapsManagement::setPathValue("/instrumentation/attitude-indicator/internal-pitch-deg", 0);
    MapsManagement::setPathValue("/instrumentation/attitude-indicator/internal-roll-deg", 0);
    MapsManagement::setPathValue("/instrumentation/encoder/indicated-altitude-ft", 0);
    MapsManagement::setPathValue("/instrumentation/encoder/pressure-alt-ft", 0);
    MapsManagement::setPathValue("/instrumentation/gps/indicated-altitude-ft", 0);
    MapsManagement::setPathValue("/instrumentation/gps/indicated-ground-speed-kt", 0);
    MapsManagement::setPathValue("/instrumentation/gps/indicated-vertical-speed", 0);
    MapsManagement::setPathValue("/instrumentation/heading-indicator/indicated-heading-deg", 0);
    MapsManagement::setPathValue("/instrumentation/magnetic-compass/indicated-heading-deg", 0);
    MapsManagement::setPathValue("/instrumentation/slip-skid-ball/indicated-slip-skid", 0);
    MapsManagement::setPathValue("/instrumentation/turn-indicator/indicated-turn-rate", 0);
    MapsManagement::setPathValue("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0);
    MapsManagement::setPathValue("/controls/flight/aileron", 0);
    MapsManagement::setPathValue("/controls/flight/elevator", 0);
    MapsManagement::setPathValue("/controls/flight/rudder", 0);
    MapsManagement::setPathValue("/controls/flight/flaps", 0);
    MapsManagement::setPathValue("/controls/engines/current-engine/throttle", 0);
    MapsManagement::setPathValue("/engines/engine/rpm", 0);
}