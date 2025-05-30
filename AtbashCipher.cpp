#include <iostream>
#include <string>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";
const string re_alpha_1 = "zyxwvutsrqponmlkjihgfedcba";
const string re_alpha_2 = "mlkjihgfedcbazyxwvutsrqpon";

string encrypt_1_version(const string& text) {
    string encrypted;
    for (int j = 0; j < text.length(); j++) {
        bool found = false;
        for (int i = 0; i < alpha.length(); i++) {
            if (text[j] == alpha[i]) {
                encrypted += toupper(re_alpha_1[i]);
                found = true;
                break;
            }
        }
        if (!found)
            encrypted += toupper(text[j]);
    }
    return encrypted;
}
string decrypt_1_version(const string& text) {
    string decrypted;
    for (int j = 0; j < text.length(); j++) {
        bool found = false;
        for (int i = 0; i < re_alpha_1.length(); i++) {
            if (tolower(text[j]) == re_alpha_1[i]) {
                decrypted += alpha[i];
                found = true;
                break;
            }
        }
        if (!found)
            decrypted += text[j];
    }
    return decrypted;
}
string encrypt_2_version(const string& text) {
    string encrypted;
    for (int j = 0; j < text.length(); j++) {
        bool found = false;
        for (int i = 0; i < alpha.length(); i++) {
            if (text[j] == alpha[i]) {
                encrypted += toupper(re_alpha_2[i]);
                found = true;
                break;
            }
        }
        if (!found)
            encrypted += toupper(text[j]);
    }
    return encrypted;
}
string decrypt_2_version(const string& text) {
    string decrypted;
    for (int j = 0; j < text.length(); j++) {
        bool found = false;
        for (int i = 0; i < re_alpha_2.length(); i++) {
            if (tolower(text[j]) == re_alpha_2[i]) {
                decrypted += alpha[i];
                found = true;
                break;
            }
        }
        if (!found)
            decrypted += text[j];
    }
    return decrypted;
}

int main() {
    string text, encrypted, de_text, decrypted;
    while (true) {
        int v_choice;
        while (true){
            cout << "Choose a version:\n1. Version 1 \n2. Version 2\n3. Exit\n";
            if(!(cin >> v_choice) || !(v_choice == 1 || v_choice == 2 || v_choice == 3)){
                cout << "Enter a valid choice" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else
                break;
        }
        cin.ignore();
        if (v_choice == 1 || v_choice == 2) {
            while (true){
                cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n3. choose from versions\n";
                if(!(cin >> v_choice) || !(v_choice == 1 || v_choice == 2 || v_choice == 3)){
                    cout << "Enter a valid choice" << endl;
                    cin.clear();
                    while (cin.get() != '\n');
                }
                else
                    break;
            }
            int choice;
            if (choice == 1) {
                cout << "Enter the text to encrypt\n";
                getline(cin, text);
                if (v_choice == 1)
                    encrypted = encrypt_1_version(text);
                else
                    encrypted = encrypt_2_version(text);
                cout << "The encrypted sentence\n" << encrypted << endl;
            } else if (choice == 2) {
                cout << "Enter the text to decrypt\n";
                getline(cin, de_text);
                if (v_choice == 1)
                    decrypted = decrypt_1_version(de_text);
                else
                    decrypted = decrypt_2_version(de_text);
                cout << "The decrypted sentence\n" << decrypted << endl;
            } else if (choice == 3)
                continue;
            else
                cout << "Please enter a valid choice" << endl;
        } else if (v_choice == 3)
            break;
        else
            cout << "Please enter a valid choice" << endl;
    }
    return 0;
}