#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string input_keyword() {
    int flag = 0;
    string key;
    while (!flag) {
        cout << "Input keyword:\n";
        cin >> key;
        for (auto symb : key) {
            if ((symb >= 'A' && symb <= 'Z') || (symb >= 'a' && symb <= 'z')) {
                symb = tolower(symb);
                flag = 1;
            }
            else {
                cout << "Invalid character detected, please enter alphabet only\n";
                flag = 0;
                break;
            }
        }
    }
    return key;
}

bool is_alpha(char symb) {
    return (symb >= 'A' && symb <= 'Z') || (symb >= 'a' && symb <= 'z');
}

void to_shifr(ifstream& file, ofstream& file_2, string key) {
    char symb, symb_key;
    int i = 0;
    while (file >> symb) {
        if (is_alpha(symb)) {
            symb_key = key[i % key.length()];
            file_2 << (char)((int)symb + ((int)symb_key - (int)'a'));
        }
        else {
            file_2 << symb;
        }
        i++;
    }
}



int main()
{
    int choice = 0, flag = 0;
    string key, text, shifr, file_input, file_output;
    cout << "Input name of file with text:\n";
    cin >> file_input;
    ifstream file(file_input);
    while (!file.is_open()) {
        cout << "Error with name of file. Try again\n";
    }
    cout << "Input name of file with shifr:\n";
    cin >> file_output;
    ofstream file_2(file_output);
    while (!file_2.is_open()) {
        cout << "Error with name of file. Try again\n";
    }
    key = input_keyword();
    cout << "New key:" << key << endl;
    cout << "Choose next:\n 1. Shifr. 2. Deshifr. 0. Exit";
    while (!(cin >> choice)) {
        cout << "Error. Try again!\n";
    }
    while (!flag) {
        switch (choice) {
        case 1: {
            to_shifr(file, file_2, key);
            break;
        }
        case 2: {
            break;
        }
        case 0: {
            cout << "Exit\n";
            flag = 1;
            break;
        }
        default: {
            cout << "Try again\n";
            break;
        }

        }
    }

    //cout << "1. Shifr.\n2. Deshifr";

    //cout << to_shifr("bc", "a") << endl;
}

 