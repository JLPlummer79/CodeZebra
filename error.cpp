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

//*******************************************************
// name: checkIfInteger
// called by: menu, editCustomerMenu
// passed: const char&
// returns: int
// The checkIfInteger function checks if the argument   *
// is in fact a digit.  If this is true, input is       *
// is converted to an int by subtracting the ASCII value*
// '0'.  If it is not a digit, 0 is returned.
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
//*******************************************************
// name: checkSingleChar
// called by: menu, editCustomerMenu
// passed: const string &
// returns: char
// The checkSingleChar function ensures that the const  *
// string reference is passed is a single character by  *
// returning the first char present in the string.      *
// this is to prevent undefined behavior due to user    *
// error when using the calling functions               *
//*******************************************************
char checkSingleChar(const std::string &s){
    return s[0];
}
//*******************************************************
// name: checkStringSize
// called by: addCustomer, editCustomer
// passed: const string&
// returns: string
// The checkStringSize function ensures that the        *
// argument is not of a size exceeding 10.  When it is  *
// less than or equal to 10, the argument is returned.  *
//In the case that it is, a new string is constructed   *
// that is exactly 10 elements in size, then returned.  *
// This is done to ensure that user entry does not cause*
// undefined behavior when entering data.               *
//*******************************************************
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
//*******************************************************
// name: checkValidFloat
// called by: addCustomer, editCustomer,                *
// called by: displayContractInfo 
// passed: const string&                                
// returns: float
// The checkValidFloat function ensures that the        *
// argument is a valid candidate for converting to a    *
// float by 1) checking if the argument is empty.  If it*
// is, 0 is returned. 2) checking how many elements are *
// punctuation. 3) checking that each element is a digit*
// and that there is not more than one punctuation char *
// present (in the argument).  If all this is verified, *
// the argument is converted to a float and returned    *
//*******************************************************
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
//*******************************************************
// name: compareFloats
// called by: matchContract
// passed: 2 const floats
// returns: int
// The compareFloats function finds the difference of   *
// the arguments and verfies that one is greater than   *
// the other.  If the result is < 0, 0 is returned.  If *
//  the result is > 0, 1 is returned.                   *
// This is to ensure that undefined behavior due to user*
// error is controlled.  It was also the programmer's   *
// first exposure into the wonderful world of float     *
// Very interesting, and terrifying.                    * 
//*******************************************************
int compareFloats(const float a, const float b) {
    if ((a - b) >= 0) {
        return 1;
    }
    return 0;
}