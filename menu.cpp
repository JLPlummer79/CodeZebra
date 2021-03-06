#include "menu.h"
#include "error.h"
#include "options.h"
#include <iostream>


//*******************************************************
// name:
// called by:
// passed:
// returns:
// The 'name' function 'description of what it does'    *
//                                                      *
//*******************************************************

void menu(std::string* name, std::string* boatName, float* contract, float* paidToDate, const int size){
    std::string input;
    char c;
    int flag = 0;

    while(flag != 5){
        std::cout << "              Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Input a customer's information\n";
        std::cout << "2. Edit a customer's information\n";
        std::cout << "3. Search for contract by value\n";
        std::cout << "4. Display all contract information\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n\n";
        getline(std::cin,input);
    
        c = checkSingleChar(input);
        flag = checkIfInteger(c);
        
        switch(flag){
            case 1:
            addCustomer(name, boatName, contract, paidToDate, size);
            break;

            case 2:
            editCustomer(name, boatName, contract, paidToDate, size);
            break;

            case 3:
             //call option 3 funct
            std::cout << "option 3\n";
            break;

            case 4:
             //call option 4 funct
            std::cout << "option 4\n";
            break;

            case 5:
            std::cout << "Exiting program\n";
            std::exit(0);

            default:
                std::cout << "Invalid input, please enter option from the menu.\n";
                break;
        }
    }
}