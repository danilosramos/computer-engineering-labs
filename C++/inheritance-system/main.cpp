#include "pessoa.hpp"
#include "aluno.hpp"
#include "professor.hpp"
#include <iostream>

using namespace std;

int main()
{
    Pessoa p1{"João", "São Gonçalo-RJ"};
    Aluno a1{"Pedro", "Campinas-SP", "ENC", 123456};
    a1.screen();
    Professor pr1{"Jose", "Sao Paulo-SP", 678910, 3, "ICA"};
    pr1.screen();
    return 0;
}