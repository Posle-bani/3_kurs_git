#include "Student_Kosov.h"

Student_Kosov::Student_Kosov() {
     id = -1;
     first_name = "";
     second_name = "";
     age = -1;
     several_mark = -1.0;   
}

void Student_Kosov::init_student(int valueId) {
    id = valueId;
    cout << "Input first name:\n";
    cin >> first_name;
    cout << "Input second name:\n";
    cin >> second_name;
    cout << "Input age:\n";
    while (!(cin >> age) || (age < 0)) {
        cin_clear("Try again...\n");
    };
    cout << "Input several mark:\n";
    while (!(cin >> several_mark) || (several_mark < 0)) {
        cin_clear("Try again...\n");
    };
}

int Student_Kosov::get_id() {
    return id;
};

void Student_Kosov::print_info() {
    cout << "\nid: " << id << "\nfirst name: " << first_name <<
        "\nsecond name: " << second_name << "\nage: " << age <<
        "\nseveral mark: " << several_mark << "\n";
};


ifstream& operator>>(ifstream& input, Student_Kosov& student) {
    input >> student.id >> student.first_name >> student.second_name >> student.age >> student.several_mark;
    return input;
};

void Student_Kosov::write_to_file(string nameFile, int id_starosta, int respons) {
    ofstream outputFile(nameFile, ios::app);
    if (!outputFile) {
        cerr << "\nError open. Try again\n" << endl;
        return;
    }
    (id == id_starosta) ? outputFile << respons << endl << id << endl << first_name << endl << second_name << endl << age << endl << several_mark << endl : 
        outputFile << id << endl << first_name << endl << second_name << endl << age << endl << several_mark << endl;
    outputFile.close();
}

