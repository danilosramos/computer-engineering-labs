#include "ConversionTable.hpp"
using namespace std;

ConversionTable::ConversionTable(int key)
{
    generateTable(key);
}

void ConversionTable::generateTable(int key)
{
    table.clear();
    int sum = 23206638 + key;
    for (int i = 0; i < 128; ++i)
    {
        table.push_back((i + sum) % 128);
    }
}

string ConversionTable::encrypt(const string &text)
{
    string encryptedText;
    for (char c : text)
    {
        if (c == ' ')
        {
            encryptedText += '_';
        }
        else
        {
            encryptedText += static_cast<char>(table[static_cast<unsigned char>(c)]);
        }
    }
    return encryptedText;
}

string ConversionTable::decrypt(const string &text)
{
    string decryptedText;
    for (char c : text)
    {
        if (c == '_')
        {
            decryptedText += ' ';
        }
        else if (c >= 32 && c <= 126)
        {
            for (size_t i = 0; i < table.size(); ++i)
            {
                if (table[i] == static_cast<unsigned char>(c))
                {
                    decryptedText += static_cast<char>(i);
                    break;
                }
            }
        }
        else
        {
            decryptedText += c;
        }
    }
    return decryptedText;
}
