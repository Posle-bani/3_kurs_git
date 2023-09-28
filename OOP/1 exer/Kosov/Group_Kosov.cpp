#include "Group_Kosov.h"

Group_Kosov::Group_Kosov() {
    vector<Student_Kosov*> students = {};
}

void Group_Kosov::input_student(Student_Kosov* student) {
    students.push_back(student);
}

int Group_Kosov::size_group() {
    return (int)students.size();
}

void Group_Kosov::print_all() {
    if (students.size() == 0) {
        cout << "Nothing to output:(\n";
    }
    for_each(students.begin(), students.end(), [](Student_Kosov* student) {
        student->print_info();
        });
}

void Group_Kosov::write_to_file(string way_to_file) {
    for_each(students.begin(), students.end(), [way_to_file](Student_Kosov* student) {
        student->write_to_file(way_to_file);
        });
}

void Group_Kosov::clearr() {
    for (Student_Kosov* student : students) {
        delete student;
    }
    students.clear(); //попробовать
}
