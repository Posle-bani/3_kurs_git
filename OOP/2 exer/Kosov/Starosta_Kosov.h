#pragma once
#include "Student_Kosov.h"

class Starosta_Kosov : public Student_Kosov {
private:
	int responsibilities;

public:
	Starosta_Kosov();
	void set_respon();
	int get_respon();
	void set_respon_from_file(int value);
	void print_info() override;
	friend ifstream& operator>>(ifstream& input, Starosta_Kosov& starosta);
};