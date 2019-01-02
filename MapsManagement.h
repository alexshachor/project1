#ifndef PROJECT1_MAPSMANAGEMENT_H
#define PROJECT1_MAPSMANAGEMENT_H

#include <string>
#include <map>
#include <vector>
#include "Command.h"

using namespace std;

class MapsManagement {
private:
    static map<string, double> pathValueMap;
    static map<string, double> symbolTable;
    static map<string, string> bindMap;

public:

    static double getValueByPath(string path);

    static double getSymbolTable(string key);

    static string getBindMap(string key);

    static void setPathValue(string path, double value);

    static void setSymbolTable(string key, double value);

    static void setBindMap(string var, string path);

    static bool isInPathValueMap(string path);

    static bool isInSymbolTable(string key);

    static bool isInBindMap(string key);

    static map<string, string> getBindMap();

    static void updateSymbolTable(vector<string> updateParams);

    static void pathValueInit();
};

#endif //PROJECT1_MAPSMANAGEMENT_H