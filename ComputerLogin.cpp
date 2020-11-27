#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;


int main() {
	typedef int* IntPter;
	const int labSize = 4;

	IntPter labNum[labSize];

	labNum[0] = new int[5];
	labNum[1] = new int[6];
	labNum[2] = new int[4];
	labNum[3] = new int[3];
	int id;
	int lab;
	int computer;
	char ans;
	do {
		do {
			cout << "Enter your id. It must be a positive nonzero number." << endl;
			cin >> id;
			if (id <= 0) {
				cout << "Invalid id." << endl;
			}
		} while (id <= 0);


		do {
			cout << "Which lab are you logging into?" << endl;
			cin >> lab;
			if (lab < 1 || lab > 4) {
				cout << "Invalid lab location." << endl;
			}
		} while (lab < 1 || lab > 4);


		do {
			cout << "Which computer from lab " << lab << " are you logging into?" << endl;
			cin >> computer;
			if (computer < 1 || computer > sizeof(labNum[lab])) {
				cout << "Invalid computer." << endl;
			}
		} while (computer < 1 || computer > sizeof(labNum[lab]));

		labNum[lab - 1][computer - 1] = id;

		do {
			cout << "Do you want to log into another computer? Y/N" << endl;
			cin >> ans;
			if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n') {
				cout << "Invalid answer." << endl;
			}
		} while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
	} while (ans == 'Y' || ans == 'y');


	cout << "Lab#" << setw(20) << "Computer Stations" << endl;
	for (int i = 0; i < sizeof(*labNum); i++) {
		cout << i + 1 << setw(8);
		for (int j = 0; j < sizeof(labNum[i]); j++) {
			cout << j + 1 << ": ";
			if (labNum[i][j] < 0) {
				cout << "empty" << setw(3);
			}
			else { cout << labNum[i][j] << setw(3); }
		}
		cout << endl;
	}
}