#include <iostream>
#include <conio.h>
#include <String>
using namespace std;

string decrypt(string cyphertext, string key);

int main() {

    string cyphertext = "LXFOPVEFRNHR";
    string key = "LEMON";

    string decrypttext = decrypt(cyphertext, key);
    cout << "decrypted text: -" << decrypttext << endl;

    return 0;
}

string decrypt(string cyphertext, string key) {
    string plaintext = "";
    int keyLength = key.length();
    int textLength = cyphertext.length();

    for (int i = 0; i < textLength; i++)
    {
        char chartext = toupper(cyphertext[i]);
        char keychar = toupper(key[i % keyLength]);

        // Decryption formula: P = (C - K + 26) % 26
        char plainchar = ((chartext - keychar + 26) % 26) + 'A';
        plaintext += plainchar;

    }
    

    return plaintext;
}