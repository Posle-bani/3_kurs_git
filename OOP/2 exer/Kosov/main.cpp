#include "Utils.h"
#include "Group_Kosov.h"

using namespace std;

int main()
{
    int choise, flag = 0, id = 0, choise_starosta = 0, id_starosta = 0, flag_starosta = 0;
    bool is_starosta_created = 0;
    Student_Kosov student;
    //student = make_shared
    Starosta_Kosov starosta;
    Group group;
    while (flag != 1) {
        cout << "\nChoose next:\n1. Input new student.\n2. Output students.\n3. Input students from file.\n4. Output student in file.\n5. Clear.\n0. Exit.\n";
        while (!(cin >> choise)) { cin_clear("Try again...\n"); };
        switch (choise) {
        case 1: {
            if (is_starosta_created == 1) {
                student.init_student(++id);
                shared_ptr<Student_Kosov> ptr = make_shared<Student_Kosov>(student);
                group.input_student(ptr);
            } else {
                cout << "1. Create starosta." << endl
                    << "2. Create student.\n";
                while (!(cin >> choise_starosta)) { cin_clear("Try again...\n"); };
                switch (choise_starosta) {
                case 1: {
                    is_starosta_created = 1;
                    starosta.init_student(++id);
                    id_starosta = id;
                    starosta.set_respon();
                    shared_ptr<Starosta_Kosov> ptr = make_shared<Starosta_Kosov>(starosta);
                    group.input_starosta(ptr);
                    break;
                }
                case 2: {
                    student.init_student(++id);
                    shared_ptr<Student_Kosov> ptr = make_shared<Student_Kosov>(student);
                    group.input_student(ptr);
                    break;
                }
                default: {
                    cout << "Error...\n";
                    break;
                }
                }
            }
            break;
        }
        case 2: {
            group.print_all();
            break;
        }
        case 3: {
            string way_to_file, line;
            is_starosta_created = 1;
            cout << "Input way to file:\n";
            cin >> way_to_file;
            ifstream file(way_to_file);
            if (!file.is_open()) {
                cerr << "Can`t open file.\n";
                break;
            }
            if (file >> starosta) {
                shared_ptr<Starosta_Kosov> ptr = make_shared<Starosta_Kosov>(starosta);
                id = group.input_students_from_file(ptr);
                id = 1;
            }
            while (file >> student) {
                shared_ptr<Student_Kosov> ptr = make_shared<Student_Kosov>(student);
                id = group.input_students_from_file(ptr);
            }
            file.close();
            cout << "Success\n";
            break;
        }
        case 4: {
            if (is_starosta_created == 0) {
                cout << "Error! Starosta not created.\n";
                break;
            }
            string way_to_file;
            cout << "Input way to file:\n";
            cin >> way_to_file;
            ofstream file(way_to_file);
            if (!file.is_open()) {
                cerr << "Can`t open file.\n";
                break;
            }
            file << "";
            group.write_to_file(way_to_file, id_starosta, starosta.get_respon());
            file.close();  
            cout << "Success\n";
            break;
        }
        case 5: {
            is_starosta_created = 0, id = 0, id_starosta = 0, flag_starosta = 0;
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