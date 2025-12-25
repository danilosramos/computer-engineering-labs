#include "aluno.hpp"
#include <string>

Aluno::Aluno(string n, string a, string c, int m) : Pessoa{n, a}, m_curso{c}, m_matricula{m} {}

void Aluno::setCurso(string c)
{
    m_curso = c;
}