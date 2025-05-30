#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;
// Function to perform encryption on a text using a Simple Substitution Cipher
string encryption(string text, string key) {
    // Array containing alphabets from A to Z
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};
    // Create a modified alphabet by excluding characters present in the key
    string modified_alpha;
    // Iterate through each character in the standard alphabet
    for (char i : alpha) {
        // Set the variable flag to true
        bool flag = true;
        // Iterate through each character in the key
        for (char j : key) {
            // Check if the standard alphabet character is present in the key
            if (i == j) {
                flag = false;
                break;
            }
        }
        // If the standard alphabet character is not in the key, append it to the modified alphabet
        if (flag)
            modified_alpha += i;
    }
    // Append the modified alphabet to the key, creating the complete substitution key
    key += modified_alpha;
    // Iterate through each character in the input text
    for (int i = 0; i < text.size(); i++) {
        char ch = text[i];
        // Make sure the character is an alphabetic character
        if (isalpha(ch)) {
            ch = tolower(ch);
            // Get the index of the character in the standard alphabet
            int index = ch - 'a';
            // Check if the index is within the valid range
            if (0 <= index && index < 26)
                // Substitute the character with the corresponding character from the key
                text[i] = key[index];
        }
    }
    // Return the encrypted text
    return text;
}
// Function to perform decryption on encrypted text using a key
string decryption(string text, string key) {
    // Array containing alphabets from a to z
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};
    // Create a modified alphabet by excluding characters present in the key
    string modified_alpha;
    // Iterate through each character in the standard alphabet
    for (char i : alpha) {
        // Set the variable flag to true
        bool flag = true;
        // Iterate through each character in the key
        for (char j : key) {
            // Check if the standard alphabet character is present in the key
            if (i == j) {
                flag = false;
                break;
            }
        }
        // If the standard alphabet character is not in the key, append it to the modified alphabet
        if (flag)
            modified_alpha += i;
    }
    // Append the modified alphabet to the key
    key += modified_alpha;
    // Create an array to map characters from the key back to their original positions in the standard alphabet
    char alpha_dict[26];
    // Populate the alpha_dict array
    for (int i = 0; i < 26 && i < key.size(); ++i)
        alpha_dict[key[i] - 'a'] = alpha[i];
    // Iterate through each character in the input text
    for (int i = 0; i < text.size(); ++i) {
        char ch = text[i];
        // Make sure the character is an alphabetic character
        if (isalpha(ch)) {
            ch = tolower(ch);
            // Get the index of the character in the key
            int index = ch - 'a';
            // Check if the index is within the valid range
            if (0 <= index && index < 26)
                // Substitute the character with the corresponding character from the alpha_dict array
                text[i] = alpha_dict[index];
        }
    }
    // Return the decrypted text
    return text;
}
string encrypt_decrypt(string original, string key) {
    string text;
    for (int i = 0; i < original.size(); i++) {
        text += (original[i] ^ key[i % key.size()]);
    }
    return text;
}
string hex_to_string(const string& hexString) {
    string result;
    for (int i = 0; i < hexString.size(); i += 2) {
        string byteString = hexString.substr(i, 2);
        char byte = static_cast<char>(stoi(byteString, nullptr, 16));
        result += byte;
    }
    return result;
}
string stringToHex(const string& inputString) {
    stringstream hexStream;
    for (const char& c : inputString) {
        hexStream << hex << setw(2) << setfill('0') << static_cast<int>(c);
    }
    return hexStream.str();
}
string encryptWord(const string& word, const string& keyword) {
    string encryptedResult;

    for (int i = 0; i < word.length(); i++) {
        if (isalpha(word[i])) { // Check if the character is alphabetic
            char base = isupper(word[i]) ? 'A' : 'a'; // Determine base value based on case
            char encryptedChar = ((word[i] - base + (keyword[i % keyword.length()] - 'A')) % 26) + base; // Calculate encrypted character
            encryptedResult += toupper(encryptedChar); // Append encrypted character to result, converting to uppercase
        } else {
            encryptedResult += word[i]; // Append non-alphabetic characters unchanged
        }
    }

    return encryptedResult;
}
string decryptMessage(const string& encryptedResult, const string& keyword) {
    string decryptedResult;

    for (int i = 0; i < encryptedResult.length(); i++) {
        if (isalpha(encryptedResult[i])) {
            char base = isupper(encryptedResult[i]) ? 'A' : 'a';
            char decryptedChar = ((encryptedResult[i] - base - (keyword[i % keyword.length()] - 'A') + 26) % 26) + base;
            decryptedResult += toupper(decryptedChar);
        } else {
            decryptedResult += encryptedResult[i];
        }
    }

    return decryptedResult;
}
int Valid_option() {
    int option;
    while (true) {
        if (!(cin >> option) ||!(option == 1 || option == 2 || option == 3)) {
            cout << "Please enter a valid choice.\n";
            cin.clear();
            while (cin.get() != '\n');
        } else {
            break;
        }
    }
    return option;
}

int main() {
    cout << "***  Welcome to the Cipher/Decipher program  ***\n\n";
    while (true) {
        cout << "What would you like to do today?\n1) Cipher a message.\n2) Decipher a message.\n3) Exit.\n";
        int op1 = Valid_option();
        if (op1 == 3) {
            cout << "<< Thanks for using the program >>";
            break;
        }
        cout << "Which cipher would you like to choose?\n1) Simple substitution cipher\n2) XOR cipher\n3) Vigenere cipher\n";
        int op2 = Valid_option();
        if (op2 == 1) {
            // initialize the variables key and text with type string
            string key, text;
            cout << "Enter the key word.\n";
            getline(cin, key);
            // set isValidKey to false
            bool isValidKey = false;
            // create a loop that depends on the value of isValidKey
            while (!isValidKey) {
                // get the value of key
                getline(cin, key);
                isValidKey = true;
                // make sure that the key size is equal to 5
                if (key.size() != 5) {
                    isValidKey = false;
                    cout << "Please enter a valid key (5 unique characters).\n";
                } else {
                    // iterate through each character in the key and make sure it is lower case
                    for (char ch: key) {
                        if (!isalpha(ch)) {
                            isValidKey = false;
                            cout << "Please enter a valid key (5 unique characters).\n";
                            break;
                        }
                    }
                }
                // check if there aren't repeated characters in the key
                if (isValidKey) {
                    for (int i = 0; i < key.size(); ++i) {
                        for (int j = i + 1; j < key.size(); ++j) {
                            if (key[i] == key[j]) {
                                isValidKey = false;
                                cout << "Please enter a valid key (5 unique characters).\n";
                                break;
                            }
                        }
                        if (!isValidKey) {
                            break;
                        }
                    }
                }
            }
            cout << "Enter the sentence.\n";
            // get the sentence that will be encrypted or decrypted
            getline(cin, text);
            if (op1 == 1) {
                string encryptedText = encryption(text, key);
                cout << "The encrypted sentence: " << encryptedText << endl;
            } else if (op1 == 2) {
                string decryptedText = decryption(text, key);
                cout << "The decrypted sentence: " << decryptedText << endl;
            }
        }
        else if (op2 == 2) {
            if (op1 == 1) {
                string original;
                cout << "Enter the sentence to be encrypted: " << endl;
                cin.ignore();
                getline(cin, original);
                cout << "Enter the keyword: " << endl;
                string key;
                while (true) {
                    getline(cin, key);
                    bool flag = true;
                    for (int i = 0; i < key.length(); i++) {
                        if (!isalpha(key[i])) {
                            cout << "Invalid key. Please enter a valid key." << endl;
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                cout << "The ciphered sentence: " << encrypt_decrypt(original, key) << endl;
                cout << "The Hexa string is: " << stringToHex(encrypt_decrypt(original, key)) << endl;
            } else if (op1 == 2) {
                cout << "Enter the Hexa string to be decrypted: " << endl;
                string hex;
                while (true) {
                    cin >> hex;
                    bool flag = true;
                    for (int i = 0; i < hex.length(); i++) {
                        if (!isxdigit(hex[i])) {
                            cout << "Invalid hexa string. Please enter a valid hexa string." << endl;
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                cout << "Enter the keyword: " << endl;
                string key;
                getline(cin, key);
                while (true) {
                    getline(cin, key);
                    bool flag = true;
                    for (int i = 0; i < key.length(); i++) {
                        if (!isalpha(key[i])) {
                            cout << "Invalid key. Please enter a valid key." << endl;
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                cout << "The decrypted sentence: " << encrypt_decrypt(hex_to_string(hex), key) << endl;
            }
        }
        else if (op2 == 3) {
            if (op1 == 1) {
                string word, keyword;
                cout << "Please enter the sentence to be Encrypted." << endl;
                cin.ignore();
                getline(cin, word);
                cout << "Please enter the keyword" << endl;
                while (true) {
                    getline(cin, keyword);
                    bool flag = true;
                    for (int i = 0; i < keyword.length(); i++) {
                        if (!isalpha(keyword[i]) || !isupper(keyword[i])) {
                            cout << "Invalid keyword. Please enter only uppercase alphabetic characters." << endl;
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                string encryptedWord = encryptWord(word, keyword);
                cout << "The encrypted sentence: " << encryptedWord << endl;
            } else if (op1 == 2) {
                string encryptedResult;
                cout << "Please enter the sentence to be decrypted. " << endl;
                cin.ignore();
                getline(cin, encryptedResult);
                string keyword;
                cout << "Please enter the keyword: " << endl;
                while (true) {
                    getline(cin, keyword);
                    bool flag = true;
                    for (int i = 0; i < keyword.length(); i++) {
                        if (!isalpha(keyword[i])) {
                            flag = false;
                            cout
                                    << "Invalid, Please enter a valid keyword (only alphabets without white spaces or numbers)."
                                    << endl;
                            break;
                        }
                        if (!isupper(keyword[i])) {
                            cout << "Invalid, please enter the keyword with only capital letters." << endl;
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                string decryptedResult = decryptMessage(encryptedResult, keyword);
                cout << "The decrypted sentence: " << decryptedResult << endl;
            }
        }
    }
    return 0;
}