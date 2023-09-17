#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

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

void Vijener(ifstream& file, ofstream& file_2, string key, int choice) {
    char symb, symb_key;
    int i = 0;
    file_2 << "";
    while (file.get(symb)) {
        symb_key = key[i % key.size()];
        choice == 2 ? file_2.put((symb - symb_key + 128) % 128) : file_2.put((symb + symb_key) % 128);
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
        Vijener(file, file_2, key, choice);
    }
    else {
        ifstream file = correct_ifstream(shifr, choice);
        cout << "Input name of file with text:\n";
        cin >> text;
        ofstream file_2(text);
        Vijener(file, file_2, key, choice);
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
    cout << "Input keyword:\n";
    cin >> key;
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

 