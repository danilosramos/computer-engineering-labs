#ifndef TEMPO_H
#define TEMPO_H
class Tempo
{
private:
    int m_hora, m_minuto, m_segundo;

public:
    Tempo(); //construtor
    Tempo(int, int, int);
    void setTempo(int, int, int);
    void imprime();
    ~Tempo(){}; //destrutor
};

#endif