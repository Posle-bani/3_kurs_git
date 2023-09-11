#include "Group_Kosov.h"

Group::Group() {
    vector<shared_ptr<Student_Kosov>> students = {};
}

void Group::input_student(shared_ptr<Student_Kosov>& student) {
    students.push_back(student);
}

void Group::input_starosta(shared_ptr<Starosta_Kosov>& starosta) {
    students.insert(students.begin(), starosta);
} 

int Group::size_group() {
    return (int)students.size();
}

void Group::print_all(int id_starosta, int respons) {
    if (students.size() == 0) {
        cout << "Nothing to output:(\n";
    }
    for_each(students.begin(), students.end(), [id_starosta, respons](shared_ptr<Student_Kosov>& student) {
        if (id_starosta == student->get_id()) {
            cout << "\nStarosta with " << respons << " responsibilities.";
        }
        student->print_info();
        });
}

void Group::write_to_file(string way_to_file, int id_starosta, int respons) {
    for_each(students.begin(), students.end(), [way_to_file, id_starosta, respons](shared_ptr<Student_Kosov>& student) {
        student->write_to_file(way_to_file, id_starosta, respons);
        });
}

int Group::input_students_from_file(shared_ptr<Student_Kosov>& student_new) {
    int id = student_new->id;
    for (shared_ptr<Student_Kosov> st : students) {
        if (st->id == student_new->id) {
           student_new->id = (int)students.size() + 1;
           id = student_new->id;
        }
    }
    students.push_back(student_new);
    return id;
}

void Group::clearr() {
    students.clear();
}
