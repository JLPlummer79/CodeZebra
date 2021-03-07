#include "error.h"
#include <string>
#include <cctype>
#include <iostream>

//*******************************************************
// name:
// called by:
// passed:
// returns:
// The 'name' function 'description of what it does'    *
//                                                      *
//*******************************************************

int checkIfInteger(const char &input){
        int digit;
        if(std::isdigit(input)) {
            digit = input - '0';
            return digit;
        }
        else{
            return 0;
        }
}

char checkSingleChar(const std::string &s){
    return s[0];
}

std::string checkStringSize(const std::string &s){
    std::string ts;
    if(s.length() >= 10) {
        for(int i = 0; i < 10; ++i) {
            ts.push_back(s[i]);
        }
        return ts;
    }
    else {
        return s;
    }
}

float checkValidFloat(const std::string &s) {
    int decimal_flag = 0;
    if(s.empty()) {
        return 0;
    }
    for(auto j = 0; j < s.size(); ++j) {
        if(ispunct(s[j])) {
            ++decimal_flag;
        }
    }
    for(size_t i = 0; i < s.size(); ++i) {
        if(!std::isdigit(s[i]) && decimal_flag > 1) {
            return 0;
        }
    }
    return std::stof(s);
}

int compareFloats(const float a, const float b) {
    if ((a - b) >= 0) {
        return 1;
        std::cout << 1;
    }
    return 0;
    std::cout << 0;
}