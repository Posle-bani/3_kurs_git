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
};
void Starosta_Kosov::print_info() {
	cout << "\nStarosta with " << responsibilities << " responsibilities.";
}
