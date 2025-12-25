#include <iostream>
#include <string>
#include "Cipher.hpp"

using namespace std;

int main()
{
    int key;
    cout << "Insert key: ";
    cin >> key;
    cin.ignore();
    Cipher cipher(key);
    int choice;
    string text;
    bool e = false;

    while (!e)
    {
        cout << "Menu:\n"
                "1. Text to encrypt\n"
                "2. Change key\n"
                "3. Decrypt\n"
                "4. Leave\n";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Type the text to encrypt: ";
            getline(cin, text);
            cout << "Encrypted text: " << cipher.encryptText(text) << "\n";
            break;
        case 2:
            cout << "New key: ";
            cin >> key;
            cin.ignore();
            cipher.regenerateTable(key);
            break;
        case 3:
            cout << "Type text to decrypt: ";
            getline(cin, text);
            cout << "Decrypted text: " << cipher.decryptText(text) << "\n";
            break;
        case 4:
            e = true;
            break;
        }
    }

    return 0;
}
