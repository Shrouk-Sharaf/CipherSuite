#include <iostream>
#include <string>
using namespace std;

bool is_uppercased(const string& text_) {
    for (char i: text_) {
        if (!isupper(i))
            return false;
    }
    return true;
}
string cipher(string text, int a, int b) {
    string cipheredtext;
    for (int i = 0; i < text.size(); ++i) {
        int textvalue = int(text[i]) - 65;
        textvalue = ((a * textvalue) + b) % 26;
        cipheredtext += char(textvalue + 65);
    }
    return cipheredtext;
}
string decipher(string text, int b, int c) {
    string decipheredtext;
    for (int i = 0; i < text.size(); ++i) {
        int textvalue = int(text[i]) - 65;
        textvalue = (c * (textvalue - b));
        while (textvalue < 0)
            textvalue += 26;
        textvalue %= 26;
        decipheredtext += char(textvalue + 65);
    }
    return decipheredtext;
}

int main() {
    int a, b, c, choice;
    string text;
    while (true) {
        cout << "Enter the values of a, b and c" << endl;
        if (!(cin >> a) || !(cin >> b) || !(cin >> c) || !(isdigit(a) || !isdigit(b) || !isdigit(c)) || (a * c) % 26 != 1 ) {
            cout << "Enter valid integers for A, B, and C such that (A * C) % 26 equals 1." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else
            break;
    }
    cin.ignore();
    while (true) {
        while (true){
            cout << "What would you like to do?\n1. Encrypt\n2. Decrypt\n3. Exit\n";
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
            while (true) {
                cout << "Enter the text to be encrypted\n";
                getline(cin, text);
                if (!is_uppercased(text)) {
                    cout << "Enter uppercase letters only" << endl;
                } else {
                    cout << "Encrypted text: " << cipher(text, a, b) << endl;
                    break;
                }
            }
        }
        else if (choice == 2) {
            while (true) {
                cout << "Enter the text to be decrypted\n";
                getline(cin, text);
                if (!is_uppercased(text)) {
                    cout << "Enter uppercase letters only" << endl;
                } else {
                    cout << "Decrypted text: " << decipher(text, b, c) << endl;
                    break;
                }
            }
        }else if (choice == 3) {
            cout << "Exiting the program...." << endl;
            break;
        }
    }
    return 0;
}