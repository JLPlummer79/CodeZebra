#include "format.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

void format(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size, const std::string vIndex){
// 1st print a preset heading, using printf it is formatacular
const char* n = "Name";
const char* bn = "Boat Name";
const char* cv = "Contract Value";
const char* ptd = "Paid To Date";
std::printf("\t[%-10s]\t\t[%-10s]\t[%-10s]\t\t[%-10s]",n,bn,cv,ptd);

}

void heading() {
    const std::string row = "\n============================================================\n";
    const std::string heading = "Yacht Club Client Information";

    std::cout << row << '\n';
    std::cout << std::setw(45) << heading << '\n';
    std::cout << row << '\n';
}

void printMoney(const float contnum) {
     std::cout.imbue(std::locale("en_US.UTF-8"));
     std::cout.precision(2);
    std::cout << std::fixed << std::showbase
    << std::put_money(contnum*100) << '\n';
    std::cout << "Printing money\n";
}