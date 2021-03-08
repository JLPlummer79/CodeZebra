#ifndef FORMAT_H
#define FORMAT_H
#include <string>


void format(const std::string* name, const std::string* boatName, const float* contract, const float* paidToDate, const int size, const std::string vIndex);

void heading();

void format_print(std::string name, const std::string bName, const float contra, const float ptd);

void formatTotal(const float total);

void border();

#endif