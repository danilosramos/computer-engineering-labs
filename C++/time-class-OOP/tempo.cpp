#include <iostream>
#include "tempo.hpp"
using namespace std;

Tempo::Tempo()
{
    m_hora = 0;
    m_minuto = 0;
    m_segundo = 0;
} // constructor

Tempo::Tempo(int hh, int mm, int ss)
{
    setTempo(hh, mm, ss);
}
void Tempo::setTempo(int hh, int mm, int ss)
{
    m_hora = hh;
    m_minuto = mm;
    m_segundo = ss;
}
void Tempo::imprime()
{
    cout << m_hora << ":" << m_minuto << ":" << m_segundo << endl;
}