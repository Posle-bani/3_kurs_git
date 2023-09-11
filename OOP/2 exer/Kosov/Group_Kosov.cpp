#include "Group_Kosov.h"

Group::Group() {
    vector<shared_ptr<Student_Kosov>> students = {};
}

void Group::input_student(shared_ptr<Student_Kosov> ptr) {
    students.push_back(ptr);
}

void Group::input_starosta(shared_ptr<Starosta_Kosov> starosta) {
    students.insert(students.begin(), starosta);
} 

int Group::size_group() {
    return (int)students.size();
}

void Group::print_all() {
    if (students.size() == 0) {
        cout << "Nothing to output:(\n";
    }
    for (auto& student : students) {
        student->print_info();
    }
}

void Group::write_to_file(string way_to_file, int id_starosta, int respons) {
    for_each(students.begin(), students.end(), [way_to_file, id_starosta, respons](shared_ptr<Student_Kosov>& student) {
        student->write_to_file(way_to_file, id_starosta, respons);
        });
}

int Group::input_students_from_file(shared_ptr<Student_Kosov> student_new) {
    int id = student_new->get_id();
    for (shared_ptr<Student_Kosov> st : students) {
        if (st->get_id() == student_new->get_id()) {
           student_new->set_id((int)students.size() + 1);
           id = student_new->get_id();
        }
    }
    students.push_back(student_new);
    return id;
}

void Group::clearr() {
    students.clear();
}
