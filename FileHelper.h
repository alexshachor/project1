//
// Created by alexander on 12/24/18.
//

#ifndef PROJECT1_FILEHELPER_H
#define PROJECT1_FILEHELPER_H

#define WHITE_SPACE ' '


#include "Expression.h"
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include "vector"

using namespace std;

class FileHelper {
public:

    static bool isNumber(const string &s);

    static vector<string> split(string str, char delimiter);

    static vector<string> splitByStr(string stringToBeSplitted, string delimiter);

    static string getParamByPrefix(string line, string prefix, string optionalSuffix = "");

    static string trim(const string &str);

    static bool contains(string line, string param, string optionalParam = "");
};


#endif //PROJECT1_FILEHELPER_H
