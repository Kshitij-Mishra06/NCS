#include <iostream>
#include <string>
using namespace std;

// Function to encrypt plaintext using the Vigenère Cipher
string vigenereEncrypt(string plaintext, string keyword) {
    string ciphertext = "";
    int keywordLength = keyword.length();
    int textLength = plaintext.length();

    for (int i = 0; i < textLength; ++i) {
        // Convert characters to uppercase
        char plainChar = toupper(plaintext[i]);
        char keyChar = toupper(keyword[i % keywordLength]);

        // Encryption formula: C = (P + K) % 26
        char cipherChar = ((plainChar - 'A' + keyChar - 'A') % 26) + 'A';
        ciphertext += cipherChar;
    }

    return ciphertext;
}

int main() {
    string plaintext = "HELLOVIGENERE";
    string keyword = "KEY";

    string ciphertext = vigenereEncrypt(plaintext, keyword);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
