#include "Utils.h"
#include "Group_Kosov.h"

using namespace std;

int main()
{
    int choise, flag = 0, id = 0;
    Student_Kosov student;
    Group group;
    while (flag != 1) {
        cout << "\nChoose next:\n1. Input new student.\n2. Output students.\n3. Input students from file.\n4. Output student in file.\n5. Clear.\n0. Exit.\n";
        while (!(cin >> choise)) {
            cin_clear("Try again...\n");
        };
        switch (choise) {
        case 1: {
            student.init_student(++id);
            Student_Kosov* ptr = new Student_Kosov;
            *ptr = student;
            group.input_student(ptr);
            break;
        }
        case 2: {
            group.print_all();
            break;
        }
        case 3: {
            string way_to_file;
            cout << "Input way to file:\n";
            cin >> way_to_file;
            ifstream file(way_to_file);
            if (!file.is_open()) {
                cerr << "Can`t open file.\n";
                break;
            }
            while (file >> student) {
                id = check_id(student.get_id(), group.size_group());
                student.id = id;
                Student_Kosov* ptr = new Student_Kosov;
                *ptr = student;
                group.input_student(ptr);
            }
            file.close();
            cout << "Success\n";
            break;
        }
        case 4: {
            string way_to_file;
            cout << "Input way to file:\n";
            cin >> way_to_file;
            ofstream file(way_to_file);
            if (!file.is_open()) {
                cerr << "Can`t open file.\n";
                break;
            }
            file << "";
            group.write_to_file(way_to_file);
            file.close();
            cout << "Success\n";
            break;
        }
        case 5: {
            id = 0;
            group.clearr();
            cout << "Success\n";
            break;
        }
        case 0: {
            flag = 1;
            cout << "Exit...";
            break;
        }
        default: {
            cout << "Try again...\n";
            break;
        }
        }
    }
    return 0;
};