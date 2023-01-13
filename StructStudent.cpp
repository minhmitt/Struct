#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct fullName{
    string lastName;
    string midName;
    string firstName;
};

struct score{
    double math;
    double cPlusplus;
    double english;
};

struct address{
    string wards;
    string district;
    string city;
};

struct student{
    fullName fullname;
    score score;
    address address;
    string major;
};

void showHeader(){
    cout << left << setw(15) << "Last name" << setw(15) << "Mid name" <<
            setw(15) << "First name" << setw(20) << "Wards" << setw(20)
            << "District" << setw(20) << "City" << setw(10) << "Math" << 
            setw(10) << "C++" << setw(10) << "Eng" << setw(12) << "Major" << endl;
}

student addNewStudent(){
    student s;
    cin.ignore();
    cout << "Last name: ";
    getline(cin, s.fullname.lastName);
    cout << "Mid name: ";
    getline(cin, s.fullname.midName);
    cout << "First name: ";
    getline(cin, s.fullname.firstName);
    cout << "Wards: ";
    getline(cin, s.address.wards);
    cout << "District: ";
    getline(cin, s.address.district);
    cout << "City: ";
    getline(cin, s.address.city);
    cout << "Math: ";
    cin >> s.score.math;
    cout << "C++: ";
    cin >> s.score.cPlusplus;
    cout << "English: ";
    cin >> s.score.english;
    cin.ignore();
    cout << "Major: ";
    getline(cin, s.major);
    return s;
};

//hiển thị thông tin của 1 sinh viên
void showInfo(student s){
    cout << left << setw(15) << s.fullname.lastName << setw(15) <<s.fullname.midName <<
            setw(15) << s.fullname.firstName << setw(20) << s.address.wards << setw(20)
            << s.address.district << setw(20) << s.address.city << setw(10) << s.score.math << 
            setw(10) << s.score.cPlusplus << setw(10) << s.score.english << setw(12) << s.major << endl;
}

double sumGpa(student s){
    return s.score.cPlusplus + s.score.math + s.score.english;
}

void sortByGpa(student *students, const int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if(sumGpa(students[j]) > sumGpa(students[j-1])){
                swap(students[j], students[j-1]); 
            }
        }
        
    }
}

student createFakeStudent(string first, string mid, string last,
	string wards, string district, string city, double math, double eng, double c, string major) {
	student s;
	s.fullname.firstName = first;
	s.fullname.midName = mid;
	s.fullname.lastName = last;
	s.address.city = city;
	s.address.district = district;
	s.address.wards = wards;
	s.score.math = math;
	s.score.english = eng;
	s.score.cPlusplus = c;
	s.major = major;
	return s;
}

void createFakeData(student *students, int& n){
    students[n++] = createFakeStudent("Nam", "Van", "Nguyen", 
		"Minh Khai", "Bac Tu Liem", "Ha Noi", 3.5, 6.5, 7.5, "CNTT");
	students[n++] = createFakeStudent("Minh", "Duc", "Tran",
		"Co Nhue", "Bac Tu Liem", "Ha Noi", 7.5, 7.5, 7.5, "CNTT");
	students[n++] = createFakeStudent("Nhung", "Hong", "Pham",
		"Minh Khai", "Bac Tu Liem", "Ha Noi", 8, 8.5, 8.5, "CNTT");
	students[n++] = createFakeStudent("Mai", "Thi", "Pham",
		"La Khe", "Ha Dong", "Da nang", 8, 6.5, 5.5, "CNTT");
	students[n++] = createFakeStudent("Lam", "Van", "Nguyen",
		"Trung Kinh", "Cau Giay", "Thai Nguyen", 6, 6.5, 5.5, "CNTT");
	students[n++] = createFakeStudent("Linh", "Thuy", "Hoang",
		"Van Chuong", "Hoan Kiem", "Thai Nguyen", 8.5, 7, 9.5, "CNTT");
}
 
 void sortByName(student *students, const int n){//sắp xếp a-z
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if(students[j - 1].fullname.firstName.compare(students[j].fullname.firstName) > 0){
                swap(students[j-1], students[j]);
            }
        }
    }
 }

 void sortByGpaAndName(student *students, const int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if(sumGpa(students[j-1]) < sumGpa(students[j])){
                swap(students[j-1], students[j]);
            }
            else if(sumGpa(students[j-1]) == sumGpa(students[j])){
                int compareName = students[j-1].fullname.firstName.compare(students[j].fullname.firstName);
                if(compareName > 0){
                    swap(students[j-1], students[j]);
                }
                else if(compareName == 0){
                    int compareLastName = students[j-1].fullname.lastName.compare(students[j].fullname.lastName);
                    if(compareLastName > 0){
                        swap(students[j-1], students[j]);
                    }
                }
            }
        }
    }  
 }

string tolower(string s){
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std :: tolower(c); });
    return s;
}

void searchByName(student *students, const int n, student *result, int& m, string key){
    key = tolower(key);
    for (int i = 0; i < n; i++)
    {
        if(tolower(students[i].fullname.firstName).compare(key) == 0){
            result[m++] = students[i];
        }
    }
}

void searchByCity(student *students, const int n, student *result, int& m, string key){
    key = tolower(key);
    for (int i = 0; i < n; i++)
    {
        if(tolower(students[i].address.city).compare(key) == 0){
            result[m++] = students[i];
        }
    }
}

//xóa sinh viên theo first name 
void remove(student *students, int& n, string key){
    key = tolower(key);
    for (int i = 0; i < n; i++)
    {
        if(tolower(students[i].fullname.firstName).compare(key) == 0){
            cout << "Ban co chac muon xoa sinh vien " << students[i].fullname.firstName << "?\n";
            cout << "Y: Chac chan xoa.\nN: Huy bo.\n";
            char choice;
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){
                for (int j = i; j < n - 1; j++)
                {
                    students[j] = students[j+1];
                }
                cout << "Xoa thanh cong!\n";
                n--;
            }
            else{
                cout << "Huy bo thao tac xoa.\n";
            }
            break;
        }
    }
}

struct statistic{
    string city;
    int numOfStudent;
    double mark;
};

void statisticByCity(student *students, const int n, statistic *result, int& m){
    // b1: lọc ra các tỉnh
    for (int i = 0; i < n; i++)
    {
        string city = students[i].address.city;
        bool isExisted = false;
        for (int j = 0; j < m; j++)
        {
            if(city.compare(result[j].city) == 0){
                result[j].numOfStudent++;
                isExisted = true;
                break;
            }
        }
        if(isExisted == false){// b2 : thêm thành phố đang xét vào danh sách thống kê
            statistic stat;
            stat.city = city;
            stat.numOfStudent = 1;
            result[m++] = stat;
        }
    }
    // b3 : sắp xếp 
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = m - 1; j > i; j--)
        {
            if(result[j].numOfStudent < result[j-1].numOfStudent){
                swap(result[j], result[j-1]);
            }
        }
        
    }
}

void statisticByEnglish(student *students, const int n, statistic *result, int& m){
    //lọc ra các sinh viên điểm tiếng anh
    for (int i = 0; i < n; i++)
    {
        double eGpa = students[i].score.english;
        bool isExisted = false;
        for (int j = 0; j < m; j++)
        {
            if(result[j].mark == eGpa){
                result[j].numOfStudent++;
                isExisted = true;
                break;
            }
        }
        if(isExisted == false){
            statistic stat;
            stat.mark = eGpa;
            stat.numOfStudent = 1;
            result[m++] = stat;
        }
    }
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = m - 1; j > i; j--)
        {
            if(result[j].mark > result[j-1].mark){
                swap(result[j], result[j-1]);
            }
        }
        
    }
}

void showStatisticByEnglishMark(statistic *result, const int n){
    cout << left << setw(15) << "Eng Mark" << setw(15) << "So SV" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << result[i].mark << setw(15) << result[i].numOfStudent << endl;
    }
}

void showStatistic(statistic *stat, const int m){
    cout << left << setw(15) << "City" << setw(25) << "Number of students" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << left << setw(15) << stat[i].city<< setw(25) << stat[i].numOfStudent << endl;
    }
}

bool updateMark(student *students, const int n, string key, double newMark){
    key = tolower(key);
    for (int i = 0; i < n; i++)
    {
        if(tolower(students[i].fullname.firstName).compare(key) == 0){
            students[i].score.cPlusplus = newMark;
            return true;
        }
    }
    cout << "Khong tim thay sinh vien co ten " << key << endl;
    return false;
}

void menu(){
    student *students = new student[200];
    int n = 0;
    createFakeData(students, n); // tao thong tin sinh vien fake
    int choice;
    do{
        cout << "===================MENU===================\n";
        cout << "1. Them moi sinh vien vao DS.\n";
        cout << "2. Hien thi danh sach sinh vien.\n";
        cout << "3. Sap xep danh sach sinh vien theo tong diem.\n";
        cout << "4. Sap xep danh sach sinh vien theo ten a-z.\n";
        cout << "5. Sap xep danh sach sinh vien theo tong diem va ten a-z.\n";
        cout << "6. Tim sinh vien theo ten.\n";
        cout << "7. Tim sinh vien theo tinh.\n";
        cout << "8. Xoa sinh vien theo ma sinh vien.\n";
        cout << "9. Liet ke luong sinh vien theo tinh.\n";
        cout << "10. Liet ke luong sinh vien theo dau diem tieng anh.\n";
        cout << "11. Sua thong tin diem C++ cho sinh vien.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "Xin moi chon: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                student s = addNewStudent();
                students[n++] = s;
                break;
            }
            case 2:
            {
                showHeader();
                for (int i = 0; i < n; i++)
                {
                    showInfo(students[i]);
                }
                break;
            }
            case 3:
            {
                if(n > 0){
                    cout << "DS sinh vien: \n";
                    sortByGpa(students, n);
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 4:
            {
                if(n > 0){
                    sortByName(students, n);
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 5:
            {
                if(n > 0){
                    sortByGpaAndName(students, n);
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 6:
            {
                if(n > 0){
                    string key;
                    cin.ignore();
                    cout << "Nhap ten can tim: ";
                    getline(cin, key);
                    student *result = new student[200];
                    int resultSize = 0;
                    searchByName(students, n, result, resultSize, key);
                    if(resultSize > 0){
                        cout << "Tim thay " << resultSize << " ket qua: \n";
                        showHeader();
                        for (int i = 0; i < resultSize; i++)
                        {
                            showInfo(result[i]);
                        }
                    }
                    else{
                        cout << "Khong tim thay ket qua nao.\n";
                    }
                    delete[] result;
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 7:
            {
                if(n > 0){
                    string key;
                    cin.ignore();
                    cout << "Nhap thanh pho tim: ";
                    getline(cin, key);
                    student *result = new student[200];
                    int resultSize = 0;
                    searchByCity(students, n, result, resultSize, key);
                    if(resultSize > 0){
                        cout << "Tim thay " << resultSize << " ket qua: \n";
                        showHeader();
                        for (int i = 0; i < resultSize; i++)
                        {
                            showInfo(result[i]);
                        }
                    }
                    else{
                        cout << "Khong tim thay ket qua nao.\n";
                    }
                    delete[] result;
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 8:
            {
                if(n > 0){
                    string key;
                    cin.ignore();
                    cout << "Nhap ten sinh vien can xoa: ";
                    getline(cin, key);
                    remove(students, n, key);
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 9:
            {
                if(n > 0){
                    statistic *stat = new statistic[64];// 64 tỉnh thành 
                    int numOfStudent = 0;
                    statisticByCity(students, n, stat, numOfStudent);
                    cout << "So luong sinh vien theo tung tinh: \n";
                    showStatistic(stat, numOfStudent);
                    delete[] stat;
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 10:
            {
                if(n > 0){
                    statistic *stat = new statistic[64];// 64 tỉnh thành 
                    int numOfStudent = 0;
                    statisticByEnglish(students, n, stat, numOfStudent);
                    cout << "So luong sinh vien theo diem: \n";
                    showStatisticByEnglishMark(stat, numOfStudent);
                    delete[] stat;
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 11:
            {
                if(n > 0){
                        cin.ignore();
                        string key;
                        double newMark;
                        cout << "Ten sinh vien muon update diem c++: ";
                        getline(cin, key);
                        cout << "Diem c++ muon update: ";
                        cin >> newMark;
                        bool updateResult = updateMark(students, n, key, newMark);
                        if(updateResult == true){
                            cout << "Cap nhat diem c++ cho sinh vien " << key << " thanh cong!\n";
                        }
                        else{
                            cout << "Cap nhat that bai!\n";
                        }
                }
                else{
                    cout << "DS rong.\n";
                }
                break;
            }
            case 0:
            {
                cout << "Xin chao va hen gap lai!\n";
            }
        }
    }while(choice != 0);
    
    delete[] students;
}

int main(){
    menu();

    return 0;
}