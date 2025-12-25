#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;

class Aluno : public Pessoa
{
private:
    string m_curso;
    int m_matricula;

public:
    Aluno(string n, string a, string c, int m);
    void setCurso(string);
};
#endif