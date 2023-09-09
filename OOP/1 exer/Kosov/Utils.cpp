#include "Utils.h"

void cin_clear(string title) {
    cin.clear();
    cin.ignore(32767, '\n');
    cout << "\nError! " << title;
}

int check_id(int id, int size) {
    if (id <= size) {
        id = size + 1;
    }
    return id;
}