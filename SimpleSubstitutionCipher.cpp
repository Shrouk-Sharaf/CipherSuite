#include <iostream>
using namespace std;

char alpha_sub[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'}; // Original alphabet for substitution

string encode_substitution(string text, string key_) {
    // Create a modified alphabet by excluding characters present in the key
    string modified_alpha;
    for (char i : alpha_sub) {
        bool flag = true;
        for (char j : key_) {
            if (i == j) {
                flag = false;
                break;
            }
        }
        if (flag)
            modified_alpha += i;
    }
    // Append the modified alphabet to the key
    key_ += modified_alpha;
    // Encrypt the text by replacing each character with the corresponding key character
    for (int i = 0; i < text.size(); i++){
        char ch = text[i];
        if (isalpha(ch)) {
            ch = tolower(ch);
            int index = ch - 'a';
            if (0 <= index && index < 26)
                text[i] = key_[index];
        }
    }
    return text;
}
string decode_substitution(string text, string key_) {
    // Create a modified alphabet by excluding characters present in the key
    string modified_alpha;
    for (char i : alpha_sub) {
        bool flag = true;
        for (char j : key_) {
            if (i == j) {
                flag = false;
                break;
            }
        }
        if (flag)
            modified_alpha += i;
    }
    // Append the modified alphabet to the key
    key_ += modified_alpha;
    // Create a dictionary to map key characters to the original alphabet characters
    char alpha_dict[26];
    for (int i = 0; i < 26 && i < key_.size(); ++i)
        alpha_dict[key_[i] - 'a'] = alpha_sub[i];
    // Decrypt the text by replacing each character with the corresponding dictionary value
    for (int i = 0; i < text.size(); ++i) {
        char ch = text[i];
        if (isalpha(ch)) {
            ch = tolower(ch);
            int index = ch - 'a';
            if (0 <= index && index < 26)
                text[i] = alpha_dict[index];
        }
    }
    return text;
}

int main() {
    string text, key;
    cout << "Enter key (5 unique letters):\n";
    cin >> key;
    cout << "Enter text to encrypt:\n";
    cin.ignore();
    getline(cin, text);

    string ciphertext = encode_substitution(text, key);
    cout << "Encrypted: " << ciphertext << endl;

    string plaintext = decode_substitution(ciphertext, key);
    cout << "Decrypted: " << plaintext << endl;
    return 0;
}
