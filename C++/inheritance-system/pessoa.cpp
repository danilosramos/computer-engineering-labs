#include "pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;

Pessoa::Pessoa(string n, string a) : m_name{n}, m_address{a} {}

void Pessoa::setAdress(string a)
{
    m_address = a;
}

void Pessoa::screen()
{
    cout << m_name << endl;
    cout << m_address << endl;
}