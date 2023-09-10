#pragma once
#include <vector>
#include <algorithm>
#include "Starosta_Kosov.h"

using namespace std;

class Group {
private:
    vector<Student_Kosov> students;
public:
    Group();
    void input_starosta(Starosta_Kosov& starosta);
    void input_student(Student_Kosov& student);
    int size_group();
    void print_all(int id_starosta, int respons);
    void write_to_file(string way_to_file, int id_starosta, int respons);
    void clearr();
    int input_students_from_file(Student_Kosov& student);
};
