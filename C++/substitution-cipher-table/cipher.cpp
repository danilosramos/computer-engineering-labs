#include "Cipher.hpp"

Cipher::Cipher(int key) : table(key) {}

void Cipher::regenerateTable(int key)
{
    table.generateTable(key);
}

std::string Cipher::encryptText(const std::string &text)
{
    return table.encrypt(text);
}

std::string Cipher::decryptText(const std::string &text)
{
    return table.decrypt(text);
}
