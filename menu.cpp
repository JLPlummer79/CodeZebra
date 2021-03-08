#include "menu.h"
#include "error.h"
#include "options.h"
#include "format.h"
#include <iostream>


//*******************************************************
// name: menu
// called by: main
// passed: std::string* name, std::string* boatName, 
// passed: float* contract, float* paidToDate
// passed: const int size
// returns: nothing
// The menu function controls the flow of the program   *
// using an initial Main Menu, validating user input and*
// functions to process user requests and enter data    *
//*******************************************************

void menu(std::string* name, std::string* boatName, float* contract, float* paidToDate, const int size){
    std::string input;
    char c;
    int flag = 0;

    while(flag != 5) {
        std::cout << "\n\n              Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Input a customer's information\n";
        std::cout << "2. Edit a customer's information\n";
        std::cout << "3. Search for contract by value\n";
        std::cout << "4. Display all contract information\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n\n";
        std::getline(std::cin,input);
    
        c = checkSingleChar(input);
        flag = checkIfInteger(c);
        //border();
        
        switch(flag){
            case 1:
            addCustomer(name, boatName, contract, paidToDate, size);
            break;

            case 2:
            editCustomer(name, boatName, contract, paidToDate, size);
            break;

            case 3:
            displayContractInfo(name, boatName, contract, paidToDate, size);
            break;

            case 4:
            displayAllContracts(name,boatName, contract, paidToDate, size);
            break;

            case 5:
            std::cout << "Exiting program\n";
            border();
            std::exit(0);

            default:
                std::cout << "Invalid input, please enter option from the menu.\n";
                break;
        }
    }
}