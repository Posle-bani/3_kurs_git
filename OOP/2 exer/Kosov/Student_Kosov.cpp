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

void Student_Kosov::set_id(int value) {
    id = value;
}

string Student_Kosov::get_first_name() {
    return first_name;
};

void Student_Kosov::set_first_name(string value) {
    first_name = value;
};

string Student_Kosov::get_second_name() {
    return second_name;
};

void Student_Kosov::set_second_name(string value) {
    second_name = value;
};

int Student_Kosov::get_age() {
    return age;
};

void Student_Kosov::set_age(int value) {
    age = value;
};

double Student_Kosov::get_several_mark() {
    return several_mark;
};

void Student_Kosov::set_several_mark(double value) {
    several_mark = value;
};

void Student_Kosov::print_info() {
    cout << "\nid: " << get_id() << "\nfirst name: " << get_first_name() <<
        "\nsecond name: " << get_second_name() << "\nage: " << get_age() <<
        "\nseveral mark: " << get_several_mark() << "\n";
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

