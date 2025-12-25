#include "professor.hpp"
#include <iostream>
using namespace std;
Professor::Professor(string n, string a, int s, int c, string i) : Pessoa{n, a}
{
    siape = s;
    categoria = c;
    instituto = i;
}
void Professor::screen()
{
    Pessoa::screen();
    cout << siape << endl;
    cout << categoria << endl;
    cout << instituto << endl;
}