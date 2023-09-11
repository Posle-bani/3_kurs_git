#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "Starosta_Kosov.h"

using namespace std;

class Group {
private:
    vector<shared_ptr<Student_Kosov>> students;
public:
    Group();
    void input_starosta(shared_ptr<Starosta_Kosov> starosta);
    void input_student(shared_ptr<Student_Kosov> ptr);
    int size_group();
    void print_all(int id_starosta, int respons);
    void write_to_file(string way_to_file, int id_starosta, int respons);
    void clearr();
    int input_students_from_file(shared_ptr<Student_Kosov> student);
};
