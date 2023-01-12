#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct daysOfWeek{
	int dayID;
	string dayInEn;
	string dayInVi;
};

void createADate(daysOfWeek& day, int dayID) {
	string nameInEn[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	string nameInVi[] = {"Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay", "Chu Nhat"};
	day.dayID = dayID;
	day.dayInEn = nameInEn[dayID - 1];
	day.dayInVi = nameInVi[dayID - 1];
}

void createDaysOfWeek(daysOfWeek* dow) {
	for (int i = 1; i <= 7; i++)
	{
		createADate(dow[i], i);
	}
}

int main() {
	int day;
	daysOfWeek* dow = new daysOfWeek[7];
	createDaysOfWeek(dow);
	do {
		cout << "Nhap ngay trong tuan.\n";
		cin >> day;
		if (day >= 1 && day <= 7) {
			cout << dow[day].dayInEn << "-" << dow[day].dayInVi << endl;
		}
		else if (day != 0) {
			cout << "Vui long nhap lai ngay trong tuan !\n";
		}
	} while (day != 0);
	delete[] dow;

	return 0;
}