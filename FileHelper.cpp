//
// Created by alexander on 12/24/18.
//

#include "FileHelper.h"


int getIntValOfChar(char c) {
    return c - '0';
}


bool FileHelper::isNumber(const string &s) {
    string str = trim(s);
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

vector<string> FileHelper::split(string str, char delimiter) {

    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == delimiter) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

vector<string> FileHelper::splitByStr(string stringToBeSplitted, string delimiter) {
    std::vector<std::string> splittedString;
    int startIndex = 0;
    int endIndex = 0;
    while ((endIndex = stringToBeSplitted.find(delimiter, startIndex)) < stringToBeSplitted.size()) {
        std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
        splittedString.push_back(val);
        startIndex = endIndex + delimiter.size();
    }
    if (startIndex < stringToBeSplitted.size()) {
        std::string val = stringToBeSplitted.substr(startIndex);
        splittedString.push_back(val);
    }
    return splittedString;
}

string FileHelper::getParamByPrefix(string line, string prefix, string optionalSuffix) {
    //get the part of the line after the prefix
    string result = line.substr(line.find(prefix) + 1);
    int paramSize = result.find(optionalSuffix);
    //get the param itself without the rest of the line
    result = result.substr(0, paramSize);
    result = trim(result);
    return result;
}

string FileHelper::trim(const string &s) {
    auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) { return std::isspace(c); });
    auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) { return std::isspace(c); }).base();
    return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

bool FileHelper::contains(string line, string param, string optionalParam) {
    bool result = false;
    if (line.find(param) != string::npos) {
        //if the line should contain also another parameter in addition to the param
        if (!optionalParam.empty()) {
            if (line.find(optionalParam) != string::npos) {
                result = true;
            }
        } else {
            result = true;
        }
    }
    return result;
}
