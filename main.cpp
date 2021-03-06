#include "menu.h"
#include <iostream>
#include <string>

int main(){
    std::string name[10] {"John Wick"};
    std::string boatName[10] {"Daisy"};
    float contract[10] {100000.0};
    float paidToDate[10] {1000.0};
    const int size = 10;
    
    menu(name, boatName, contract, paidToDate, size);

    return 0;
}