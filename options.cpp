#include "options.h"
#include "error.h"
#include "format.h"
#include <string>
#include <iostream>

//*******************************************************
// name:        addCustomer
// called by:   menu
// passed:      std::string *name, std::string *boatName, 
// passed:      float* contract, float* paidToDate, 
// passed:      const int size
// returns:     nothing
// The addCustomer function prompts the user for the    *
// customer name (a string), boat name (a string),      *
// the contract value (a float), and the amount         *
// paid to date (a float), stores each of these values  *
// in 4 seperate arrays and validates the data          *
//*******************************************************
void addCustomer(std::string *name, std::string *boatName, float* contract, float* paidToDate, const int size){
    static int customer = 1;
    int flag = 1;
    float value;
    std::string inputName, inputBName, inputContract, inputPTD;
    if(customer >= size) {
        std::cout << "Customer data base is full!\n";
        exit(0);
    }
    while(flag != 0) {
        std::cout << "Enter customer name (up to 10 characters): ";
        std::getline(std::cin, inputName);
        inputName = checkStringSize(inputName);
        name[customer] = inputName;

        std::cout << "\nEnter boat name (up to 10 characters): ";
        std::getline(std::cin, inputBName);
        inputBName = checkStringSize(inputBName);
        boatName[customer] = inputBName;

        std::cout << "\nEnter contract amount: ";
        std::getline(std::cin, inputContract);
        value = checkValidFloat(inputContract);
        if(value == 0){
            std::cout << "Contract value invalid.\n";
            continue;
        }
        contract[customer] = value;

        std::cout << "\nEnter amount paid to date: ";
        std::getline(std::cin, inputPTD);
        value = checkValidFloat(inputPTD);

        if(value == 0){
            std::cout << "Entered value invalid.\n";
            continue;
        }
        paidToDate[customer] = value;
        flag = 0;
        ++customer;
    }
}

//*******************************************************
// name:        editCustomer
// called by:   menu
// passed:      std::string *name, std::string *boatName, 
// passed:      float* contract, float* paidToDate, 
// passed:      const int size
// returns:     nothing
// The editCustomer function takes 4 arrays: name,      *
// boatName, contract, paidToDate, and a const int size.*
// It edits the existing customer's data and validates  *
// the user entry.
//*******************************************************
void editCustomer(std::string *name, std::string *boatName, float* contract, float* paidToDate, const int size){
    std::string customer,entry;
    int index = -1;
    int flag = 1;
    int field;
    float value;
    
    while(flag != 0) {
        std::cout << "\nEnter customer name you wish to edit: ";
        std::getline(std::cin, customer);
        
        //find & match customer index
        index = matchCustomer(name, customer, size);
        if(index == -1){
            continue;
        }
        
        field = editCustomerMenu();
        switch(field){
            case 0:
                flag = 0;   //will this break us out of the while loop?
            break;
            case 1:
                std::cout << "Enter customer name: ";
                std::getline(std::cin, entry);
                entry = checkStringSize(entry);
                name[index] = entry;
                flag = 0;
            break;
            case 2:
                std::cout << "\nEnter updated boat name: ";
                std::getline(std::cin,entry);
                entry = checkStringSize(entry);
                boatName[index] = entry;
                flag = 0;
            break;
            case 3:
                std::cout << "\nEnter updated contract value: ";
                std::getline(std::cin, entry);
                value = checkValidFloat(entry);
                if(value == 0) {
                    std::cout << "Invalid contract amount.\n";
                    continue;
                }
                contract[index] = value;
                flag = 0;
            break;
            case 4:
                std::cout <<"\nEnter updated paid to date amount: ";
                std::getline(std::cin, entry);
                value = checkValidFloat(entry);
                
                if(value == 0) {
                    std::cout << "Invalid paid to date amount.\n";
                    continue;
                }
                paidToDate[index] = value;
                flag = 0;
            break;
            default:
                std::cout << "Unknown error.  A glitch in the Matrix perhaps?\n";
            break;

        }
    }

}
//*******************************************************
// name:        matchCustomer
// called by:   editCustomer
// passed:      std::string *name, 
// passed:      const std::string customer, 
// passed:      const int size
// returns:     int
// The matchCustomer function takes the array name      *
// the string customer, and the size of the array       *
// and compares customer to the names in name           *
// if customer matches an element in name, the index    *
// is returned. If no matches are found, -1 is returned *
//*******************************************************
int matchCustomer(std::string *name, const std::string customer, const int size){
    for(auto i = 0; i < size; ++i){
        if(name[i] == customer){
            return i;
        }
    }
    std::cout << "Customer not found.\n";
    return -1;
}
//*******************************************************
// name: editCustomerMenu
// called by: editCustomer
// passed: nothing
// returns: int
// The editCustomerMenu function prints a menu for      *
// selecting which field the user wants to edit.  After *
// validating the selection, an int is returned to      *
// editCustomer.
//*******************************************************
int editCustomerMenu(){
    int flag = 0;
    std::string input;
    char c;
    //editCustomer menu
    while(flag != 5){
        std::cout << "         Edit Customer Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Edit customer name\n";
        std::cout << "2. Edit boat name\n";
        std::cout << "3. Edit contract value\n";
        std::cout << "4. Edit paid to date amount\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "----------------------------------------\n\n";
        
        std::getline(std::cin, input);
        //validate entry
        c = checkSingleChar(input);
        //return mechanism
        flag = checkIfInteger(c);
        switch(flag){
            case 1: 
            case 2: 
            case 3:
            case 4:
                return flag;
                break;
            case 5:
                flag = 5;
                break;
            default:
                std::cout << "Invalid entry.  Please enter a menu option.\n";
                break;
        }
    }
    return 0;
}
//*******************************************************
// name: displayContractInfo
// called by: menu
// passed: std::string *name, std::string *boatName, 
// passed: float* contract, float* paidToDate, 
// passed: const int size
// returns:     nothing
// The displayContractInfo function prompts the user to *
// enter a minimum amount to search for in the contracts*
// array, verifies the user input, then calls another   *
// function to do the search, then takes the result and *
// calls another function to display (on screen) the    *
// user requested data.                                 *
//*******************************************************
void displayContractInfo(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size) {
    std::string input, nums;
    float value = 0;
    int index = 0;
    
    std::cout << "\nEnter contract amount to search: ";
    
    std::getline(std::cin, input);

    value = checkValidFloat(input);
    nums = matchContract(contract, size, value);
    format(name, boatName, contract, paidToDate, size, nums);
}
/*******************************************************
// name: matchContract
// called by: displayContractInfo, displayAllContracts  
// passed: const float* contract, const int size, 
// passed: const float search
// returns: const std::string
// The matchContract function takes the array contract  *
// and checks if an element meets the user chriteria.   *
// When it does, that index value is saved in validIndex*
// When the traversal is done, validIndex is returned   *
//*******************************************************/
const std::string matchContract(const float* contract, const int size, const float search) {
    std::string validIndex;
    
    for(int i = 0; i < size; ++i){

        if(compareFloats(contract[i], search)){
            validIndex.push_back(i);
        }
    }
    return validIndex;
}
//*******************************************************
// name: displayAllContracts
// called by: menu
// passed: const std::string* name, 
// passed: const std::string* boatName, 
// passed: const float* contract, 
// passed: const float* paidToDate, const int size
// returns: nothing
// The displayAllContracts function displays all data in*
// the argument arrays, then displays the data, next    *
// totals & displays the data of the contract array     *
//*******************************************************
void displayAllContracts(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size){
    std::string num = matchContract(contract, size, 1);
    float total;
    format(name, boatName, contract, paidToDate, size, num);
    total =  totalOfAllContracts(contract, size);
    
    formatTotal(total);
}
//*******************************************************
// name: totalOfAllContracts
// called by: displayAllContracts
// passed: const float* contract, const int size
// returns: const float
// The totalOfAllContracts function calculates the sum  *
// of all the contracts and returns the sum             *
//*******************************************************
const float totalOfAllContracts(const float* contract, const int size){
    float sum = 0;
    for(auto i = 0; i < size; ++i){
        sum = sum + contract[i];
    }
    return sum;
}
