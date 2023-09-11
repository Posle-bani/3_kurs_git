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
    int id;

public:
    Student_Kosov();
    void init_student(int valueId);
    int get_id();
    void set_id(int value);
    string get_first_name();
    void set_first_name(string value);
    string get_second_name();
    void set_second_name(string value);
    int get_age();
    void set_age(int value);
    double get_several_mark();
    void set_several_mark(double value);
    virtual void print_info();
    friend ifstream& operator>>(ifstream& input, Student_Kosov& student);
    void write_to_file(string nameFile, int id_starosta, int respons);
};

