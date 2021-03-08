#include "format.h"
#include <iostream>
#include <iomanip>
#include <string>
//#include <windows.h>

//*******************************************************
// name: format
// called by: displayAllContractInfo, displayAllContracts
// passed: const std::string* name, 
// passed: const std::string* boatName, 
// passed: const float* contract, const float* paidToDate, 
// passed: const int size, const std::string vIndex
// returns: nothing
// The format function prints a formatted heading       *
// then prints a 2nd formatted heading.  Lastly, it     *
// passes data to a function in parallel for printing   *
//*******************************************************
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
//*******************************************************
// name: heading
// called by: format 
// passed: nothing
// returns: nothing
// The heading function prints a formatted heading to   *
// signify customer data being displayed.               *
// note: the line GetSystemMetrics(0)/9 calculates the  *
// delimiter for the heading based on the screen size   *
// unfortunately this did not work on GDBonline and thus*
// is commented out.  If compiling code on a windows    *
// system it is effective, but you must also use        *
// #include <windows.h>, also commented out  -JLP       * 
//*******************************************************
void heading() {
    // using the windows library here was nice on a Windows machine... not so much on GBD loved researching it though!
    //int width = GetSystemMetrics(0)/9 - GetSystemMetrics(0)%10;

    int width = 144;
    const std::string heading = "\nYacht Club Client Information\n";
    
   std::cout << std::setfill('=') << std::setw(width) << '\n';
   std::cout << std::setfill(' ') << std::setw(width) << heading << '\n';
   std::cout << std::setfill('=') << std::setw(width) << '\n' << std::setfill(' ');
}
//*******************************************************
// name: border
// called by: formatTotal, menu
// passed: nothing
// returns: nothing
// The border function prints a formatted header/footer *
// to improve data readability                          *
// see note about re: GetSystemMetrics(0) -JLP
//*******************************************************
void border() {
    //int width = GetSystemMetrics(0)/9 - GetSystemMetrics(0)%10;
    int width = 144;
    std::cout << '\n' << std::setfill('-') << std::setw(width) << '\n' << std::setfill(' ');
}

//*******************************************************
// name: format_print
// called by: format
// passed: std::string name, const std::string bName, 
// passesd:const float contra, const float ptd
// returns: nothing
// The format_print function recieves data to be printed*
// in a neat, consistent, orderly format.  The name     *
// parameter is not const because if it is less than 10 *
// elements, it is reformatted with it contents and     *
// spaces to reach 10, for formatting purposes          *
//*******************************************************
void format_print(std::string name, const std::string bName, const float contra, const float ptd) {
    //print args with US currency, 2 decimal place formatting, widths specified
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
    //border();

}
//*******************************************************
// name: formatTotal
// called by: displayAllContracts
// passed: const float total
// returns: nothing
// The formatTotal function prints the argument in a    *
// specifically formatted for user consumption          *
//*******************************************************
void formatTotal(const float total) {
    //print total with US currency & 2 decimal place formatting
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout.precision(2);
    std::cout << "\nTotal Contract Value: "<< std::put_money(total*100);
    border();
}