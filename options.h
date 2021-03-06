#ifndef OPTIONS_H
#define OPTIONS_H
#include <string>

//comments
void addCustomer(std::string* name, std::string* boatName, float* contract, float* paidToDate, const int size);
//comments
void editCustomer(std::string* name, std::string* boatName, float* contract, float* paidToDate, const int size);

int matchCustomer(std::string *name, const std::string customer, const int size);

int editCustomerMenu();

//comments
void displayContractInfo(std::string* name, std::string* boatName, float* contract, float* paidToDate, const int size);

const std::string matchContract(float* contract, const int size, const float search);

//comments
int* option4(std::string* name, std::string* boatName, std::string* contract, std::string* paidToDate, const int size);


#endif