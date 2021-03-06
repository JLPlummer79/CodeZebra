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
    if(s.size() > 15){
        for(size_t i=0; i < 15; ++i){
            ts[i] = s[i];
        }
        return ts;
    }
    else {
        return s;
    }
}

float checkValidFloat(const std::string &s) {
    for(size_t i = 0; i < s.size(); ++i) {
        if(!std::isdigit(s[i])){
            return 0;
        }
    }
    return std::stof(s);
}