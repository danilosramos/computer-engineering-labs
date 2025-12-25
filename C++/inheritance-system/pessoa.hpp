#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include <string>
using namespace std;

class Pessoa
{
protected:
    string m_name;
    string m_address;

public:
    Pessoa(string n, string a);
    ~Pessoa(){};
    void setAdress(string);
    void screen();
};

#endif