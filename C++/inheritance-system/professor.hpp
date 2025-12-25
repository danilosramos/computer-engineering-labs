#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "pessoa.hpp"

class Professor : public Pessoa
{
private:
    int siape;
    int categoria;
    string instituto;

public:
    Professor(string, string, int, int, string);
    ~Professor() {}
    int promover() { return ++categoria; }
    void setInstituto(string i) { instituto = i; }
    void screen();
};
#endif