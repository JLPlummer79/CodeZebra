#include "menu.h"
#include "error.h"
#include "options.h"
#include <iostream>
//#include <stdlib.h>

//drives the program

void menu(std::string* name, std::string* boatName, float* contract, float* paidToDate, const int size){
    std::string input;
    char c;
    int flag = 0;

    while(flag != 5){
        std::cout << "1. Input a customer's information\n";
        std::cout << "2. Edit a customer's information\n";
        std::cout << "3. Search for contract by value\n";
        std::cout << "4. Display all contract information\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n";
        getline(std::cin,input);
    
        c = checkSingleChar(input);
        flag = checkIfInteger(c);
        
        switch(flag){
            case 1:
            option1(name, boatName, contract, paidToDate, size);
            break;

            case 2:
            //call option 2 funct
            std::cout << "option 2\n";
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