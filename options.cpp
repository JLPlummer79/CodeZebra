#include "options.h"
#include "error.h"
#include <string>
#include <iostream>

void option1(std::string *name, std::string *boatName, float* contract, float* paidToDate, const int size){
    static int customer = 0;
    int flag = 1;
    float value;
    std::string inputName, inputBName, inputContract, inputPTD;
    if(customer >= size) {
        std::cout << "Customer data base is full!\n";
        exit(0);
    }
    while(flag != 0) {
        std::cout << "Enter customer name (up to 15 characters): ";
        getline(std::cin, inputName);
        inputName = checkStringSize(inputName);
        name[customer] = inputName;

        std::cout << "\nEnter boat name (up to 15 characters): ";
        getline(std::cin, inputBName);
        inputBName = checkStringSize(inputBName);
        boatName[customer] = inputBName;

        std::cout << "\nEnter contract amount: ";
        getline(std::cin, inputContract);
        value = checkValidFloat(inputContract);
        if(value == 0){
            std::cout << "Contract value invalid.\n";
            continue;
        }
        contract[customer] = value;

        std::cout << "\nEnter amount paid to date: ";
        getline(std::cin, inputPTD);
        value = checkValidFloat(inputPTD);
        if(value = 0){
            std::cout << "Entered value invalid.\n";
            continue;
        }
        paidToDate[customer] = value;
        flag = 0;
        ++customer;
    }
}

void option2(std::string *name, std::string *boatName, float* contract, float* paidToDate, const int size){
    std::string customer,field;
    std::cout << "\nEnter customer name you wish to edit: ";
    getline(std::cin, customer);
    //need a function to take the name array, customer name and size
    //match the name and then return the index number.
    std::cout <<"\nWhich field do you wish to edit: ";
    getline(std::cin, field); //possibly create a mini number menu here
    //reuse the digit checking code

}