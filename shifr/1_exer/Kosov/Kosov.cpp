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

ifstream correct_ifstream(string& name_file, int choice) {
    choice == 1 ? cout << "Input name of file with text:\n" : cout << "Input name of file with shifr:\n";
    cin >> name_file;
    ifstream file(name_file);
    int flag = 0;
    while (flag == 0) {
        if (!file.is_open()) {
            cout << "Error with name of file. Try again\n";
            cout << "Input name of file with text:\n";
            cin >> name_file;
        }
        else {
            flag = 1;
        }
    }
    return file;
}

void deshifr(ifstream& file, ofstream& file_2, string key) {
    char symb, symb_key;
    int i = 0;
    file_2 << "";
    while (file.get(symb)) {
        symb_key = key[i % key.length()];
        //cout << (int)symb << "__" << ((int)symb_key - (int)'a') << endl;
        // int symbole = (int)symb + ((int)symb_key - (int)'a');
        //  if (symbole > (int)'z') { symbole = symbole - 26; }
        int symbole = ((int)symb - (int)symb_key) % 127;
        if (symbole < 0) { symbole = 127 + symbole; }
        file_2 << (char)(symbole);
        i++;
    }
}

void to_shifr(ifstream& file, ofstream& file_2, string key) {
    char symb, symb_key;
    int i = 0;
    file_2 << "";
    while (file.get(symb)) {
        //symb = tolower(symb);
        //if (is_alpha(symb)) {
        symb_key = key[i % key.length()];
        //cout << (int)symb << "__" << ((int)symb_key - (int)'a') << endl;
        // int symbole = (int)symb + ((int)symb_key - (int)'a');
        //  if (symbole > (int)'z') { symbole = symbole - 26; }
        file_2 << (char)(((int)symb + (int)symb_key) % 127);

        //}
        //else {
        //file_2 << symb;
        //}
        i++;
    }
}

void process(int choice, string key) {
    string text, shifr;
    if (choice == 1) {
        ifstream file = correct_ifstream(text, choice);
        cout << "Input name of file with shifr:\n";
        cin >> shifr;
        ofstream file_2(shifr);
        to_shifr(file, file_2, key);
    }
    else {
        ifstream file = correct_ifstream(shifr, choice);
        cout << "Input name of file with text:\n";
        cin >> text;
        ofstream file_2(text);
        deshifr(file, file_2, key);
    }
}

int main()
{
    int choice = 0, flag = 0;
    string key, text, shifr, file_text, file_shifr;
    cout << "Choose next:\n 1. Shifr. 2. Deshifr. 0. Exit\n";
    while (!(cin >> choice)) {
        cout << "Error. Try again!\n";
    }
    key = input_keyword();
    //cout << "New key:" << key << endl;
    while (!flag) {
        switch (choice) {
        case 1: {
            process(choice, key);
            cout << "Process is over.\n";
            flag = 1;
            break;
        }
        case 2: {
            process(choice, key);
            cout << "Process is over.\n";
            flag = 1;
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
}

 