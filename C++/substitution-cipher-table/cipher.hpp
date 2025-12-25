#ifndef CIPHER_HPP
#define CIPHER_HPP

#include "ConversionTable.hpp"
#include <string>

class Cipher
{
private:
    ConversionTable table;

public:
    Cipher(int key);
    void regenerateTable(int key);
    std::string encryptText(const std::string &text);
    std::string decryptText(const std::string &text);
};

#endif
