#include "format.h"
#include <iostream>
#include <iomanip>
#include <string>
//#include <windows.h>

void format(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size, const std::string vIndex){
heading();

int index = 0;
std::cout << "Name      " << std::setw(27) << "Boat Name " << std::setw(54) 
    << "Contract Value" << std::setw(52) << "Paid To Date"  << '\n';
//loop through the valid indexes, sending the results print neatly.
    for(auto i = 0; i < vIndex.size(); ++i) {
        index = vIndex[i];
        format_print(name[index], boatName[index], contract[index], paidToDate[index]);
    }

}

void heading() {
    // using the windows library here was nice on a Windows machine... not so much on GBD loved researching it though!
    //int width = GetSystemMetrics(0)/9 - GetSystemMetrics(0)%10;

    int width = 144;
    const std::string heading = "\nYacht Club Client Information\n";
    
   std::cout << std::setfill('=') << std::setw(width) << '\n';
   std::cout << std::setfill(' ') << std::setw(width) << heading << '\n';
   std::cout << std::setfill('=') << std::setw(width) << '\n' << std::setfill(' ');
}


void format_print(std::string name, std::string bName, float contra, float ptd) {
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout.precision(2);
    if(name.size()-1 < 10) {
        for(auto i = name.size()-1; i < 10; ++i){
            name.push_back(' ');
        }
    }
    std::cout << name << std::setw(25) << bName
    << std::setw(54) << std::showbase
    << std::put_money(contra*100) 
    << std::setw(52) << std::showbase
    << std::put_money(ptd*100) << '\n';

}