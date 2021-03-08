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
void displayContractInfo(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size);

const std::string matchContract(const float* contract, const int size, const float search);

//comments
void displayAllContracts(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size);

const float totalOfAllContracts(const float* contract, const int size);
#endif