#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct student {
	string id;
	string fullname;
	double gpa;

	void fillInfo() {
		cout << "Ho ten sinh vien: ";
		getline(cin, fullname);
		cout << "Ma sinh vien: ";
		getline(cin, id);
		cout << "Diem trung binh: ";
		cin >> gpa;
		cin.ignore();
	}

	void showInfo() {
		cout << left << setw(15) << id << setw(20) << fullname
			 << setw(10) << gpa << endl;
	}
};

void showHeader() {
	cout << left << setw(15) << "Ma SV" << setw(20) << "Ho ten"
		 << setw(10) << "GPA" << endl;
}

int main() {
	student s;
	s.fillInfo();
	showHeader();

	s.showInfo();
	return 0;
}

