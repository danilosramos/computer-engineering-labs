#ifndef CONVERSIONTABLE_HPP
#define CONVERSIONTABLE_HPP

#include <string>
#include <vector>
using namespace std;

class ConversionTable
{
private:
    vector<int> table;

public:
    ConversionTable(int key);
    void generateTable(int key);
    string encrypt(const string &text);
    string decrypt(const string &text);
};

#endif
