#include "CartoesWeb.hpp"
#include <vector>

int main()
{
    vector<CartaoWeb*> mailist;
    mailist.push_back(new Namorados("Patricia da Silva"));
    mailist.push_back(new Namorados("Vanessa Camargo"));
    mailist.push_back(new Natal("Jefferson Soares"));
    mailist.push_back(new Aniversario("Cris de Oliveria"));
    mailist.push_back(new Divida("Cassio Batista"));
    mailist.push_back(new Natal("Alexandre o Grande"));

    for(size_t i=0; i<mailist.size(); i++)
    {
        mailist.at(i)->SendMessage();
    }

    for(size_t i=0; i<mailist.size(); i++)
        delete mailist.at(i);
    mailist.clear();

    return 0;
}
