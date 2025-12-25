#include <iostream>

using namespace std;

class CartaoWeb
{
protected:
    string m_dest;
public:
    CartaoWeb(string dest) : m_dest(dest) {};
    virtual void SendMessage() = 0;
};

class Namorados : public CartaoWeb
{
public:
    Namorados(string dest) : CartaoWeb(dest) {};
    void SendMessage()
    {
        cout << "Querido(a) " << m_dest << ". Amo vc, hoje eh um dia xxxxxx." << endl;
    }
};

class Natal : public CartaoWeb
{
public:
    Natal(string dest) : CartaoWeb(dest) {};
    void SendMessage()
    {
        cout << "Prezado " << m_dest << ". Que as esperancas xxxxxxx do Natal se renovem xxxxxx." << endl;
    }
};

class Aniversario : public CartaoWeb
{
public:
    Aniversario(string dest) : CartaoWeb(dest) {};
    void SendMessage()
    {
        cout << "Querido(a) " << m_dest << ". Feliz aniversario." << endl;
    }
};


class Divida : public CartaoWeb
{
public:
    Divida(string dest) : CartaoWeb(dest) {};
    void SendMessage()
    {
        cout << "Sr." << m_dest << ". Pague me o que deve ou....." << endl;
    }
};
