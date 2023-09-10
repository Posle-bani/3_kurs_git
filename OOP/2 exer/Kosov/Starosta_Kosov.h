#pragma once
#include "Student_Kosov.h"

class Starosta_Kosov : public Student_Kosov {
private:
	int responsibilities;

public:
	Starosta_Kosov();
	void set_respon();
	int get_respon();
	void print_info();
	void set_respon_from_file(int value);
};