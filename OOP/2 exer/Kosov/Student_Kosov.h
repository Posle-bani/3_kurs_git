#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utils.h"

class Student_Kosov {
private:
    string first_name;
    string second_name;
    int age;
    double several_mark;

public:
    Student_Kosov();
    int id;
    void init_student(int valueId);
    int get_id();
    void print_info();
    friend ifstream& operator>>(ifstream& input, shared_ptr<Student_Kosov>& student);
    void write_to_file(string nameFile, int id_starosta, int respons);
};

