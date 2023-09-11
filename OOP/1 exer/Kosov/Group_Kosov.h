#pragma once
#include <vector>
#include <algorithm>
#include "Student_Kosov.h"

using namespace std;

class Group {
private:
    vector<Student_Kosov*> students;
public:
    Group();
    void input_student(Student_Kosov* student);
    int size_group();
    void print_all();
    void write_to_file(string way_to_file);
    void clearr();
};
