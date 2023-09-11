#include "Starosta_Kosov.h"

Starosta_Kosov::Starosta_Kosov() {
	responsibilities = 0;
}

void Starosta_Kosov::set_respon() {
	cout << "Input amount of responsibilities:\n";
	while (!(cin >> responsibilities) || (responsibilities < 0)) {
		cin_clear("Try again...\n");
	};
}

void Starosta_Kosov::set_respon_from_file(int value) {
	responsibilities = value;
}

int Starosta_Kosov::get_respon() {
	return responsibilities;
}

void Starosta_Kosov::print_info() {
	cout << "\nStarosta with " << responsibilities << " responsibilities." 
		<< "\nid: " << get_id() << "\nfirst name: " << get_first_name() <<
		"\nsecond name: " << get_second_name() << "\nage: " << get_age() <<
		"\nseveral mark: " << get_several_mark() << "\n";
};

ifstream& operator>>(ifstream& input, Starosta_Kosov& starosta) {
	string first_name, second_name;
	int age, id;
	double several_mark;
	input >> starosta.responsibilities >> id >> first_name >> second_name >> age >> several_mark;
	starosta.set_id(id);
	starosta.set_first_name(first_name);
	starosta.set_second_name(second_name);
	starosta.set_age(age);
	starosta.set_several_mark(several_mark);
	return input;
};