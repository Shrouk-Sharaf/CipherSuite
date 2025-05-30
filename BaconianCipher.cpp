#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string encode(const string& plaintext) {
    unordered_map<char, string> en_Dict = {
            {'A', "aaaaa"}, {'B', "aaaab"}, {'C', "aaaba"}, {'D', "aaabb"}, {'E', "aabaa"},
            {'F', "aabab"}, {'G', "aabba"}, {'H', "aabbb"}, {'I', "abaaa"}, {'J', "abaab"},
            {'K', "ababa"}, {'L', "ababb"}, {'M', "abbaa"}, {'N', "abbab"}, {'O', "abbba"},
            {'P', "abbbb"}, {'Q', "baaaa"}, {'R', "baaab"}, {'S', "baaba"}, {'T', "baabb"},
            {'U', "babaa"}, {'V', "babab"}, {'W', "babba"}, {'X', "babbb"}, {'Y', "bbaaa"},
            {'Z', "bbaab"}
    };
    string encoded;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char upperC = toupper(c);
            encoded += en_Dict[upperC] + " ";
        }
        else
            encoded += c;
    }
    return encoded;
}
string decode(const string& encodedText) {
    unordered_map<string, char> de_Dict = {
            {"aaaaa", 'A'}, {"aaaab", 'B'}, {"aaaba", 'C'}, {"aaabb", 'D'}, {"aabaa", 'E'},
            {"aabab", 'F'}, {"aabba", 'G'}, {"aabbb", 'H'}, {"abaaa", 'I'}, {"abaab", 'J'},
            {"ababa", 'K'}, {"ababb", 'L'}, {"abbaa", 'M'}, {"abbab", 'N'}, {"abbba", 'O'},
            {"abbbb", 'P'}, {"baaaa", 'Q'}, {"baaab", 'R'}, {"baaba", 'S'}, {"baabb", 'T'},
            {"babaa", 'U'}, {"babab", 'V'}, {"babba", 'W'}, {"babbb", 'X'}, {"bbaaa", 'Y'},
            {"bbaab", 'Z'}
    };
    string decryptedText, letter;
    for (char c : encodedText) {
        if (isalpha(c)) {
            letter += c;
            if (letter.length() == 5) {
                decryptedText += de_Dict[letter];
                letter.clear();
            }
        } else
            decryptedText += c;
    }
    return decryptedText;
}

int main() {
    string  plaintext, encodedText;
    int choice;
    while (true) {
        while(true){
            cout << "Choose an option:\n1. Encode\n2. Decode\n3. Exit\n";
            if(!(cin >> choice) || !(choice == 1 || choice == 2 || choice == 3)){
                cout << "Enter a valid choice" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else
                break;
        }
        cin.ignore();
        if (choice == 1) {
            cout << "Enter a word to encode\n";
            getline(cin, plaintext);
            cout << "Encoded sentence\n" << encode(plaintext) << endl;
        } else if (choice == 2) {
            cout << "Enter a word to decode\n";
            getline(cin, encodedText);
            cout << "Decoded sentence\n" << decode(encodedText) << endl;
        } else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        } else
            cout << "Invalid choice\n";
    }
    return 0;
}