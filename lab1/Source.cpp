#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;

struct Student {
	string surname;
	string name;
	string adress;
	int phoneNumber;
};
string model, producer;
int price;

void RW(string type_file) {
	string answer;
	if (type_file == "DAT") {
		Student student;
		ofstream file_open("INFO.DAT", ios::app);
		do
		{
			cout << "Введiть прiзвище, iм'я, адреса та телефон студента" << endl;

			cout << "Прiзвище: ";
			cin >> student.surname;
			cout << "Iм'я: ";
			cin >> student.name ;
			cout << "Адреса: ";
			cin >> student.adress;
			cout << "Телефон: ";
			cin >> student.phoneNumber;

			file_open << student.surname << " " << student.name << " " << student.adress << " " << student.phoneNumber << endl;

			cout << "Бажаєте додати ще студента?(y/n) ";
			cin >> answer;
			cout << endl;
		} while (answer == "y");

		file_open.close();
	}
	if (type_file == "TXT") {
		ofstream file_open("INFO.TXT", ios::app);
		do
		{
			cout << "Введiть марку, цiну та виробника телевiзора" << endl;

			cout << "Марка: ";
			cin >> model;
			cout << "Цiна: ";
			cin >> price;
			cout << "Виробник: ";
			cin >> producer;
			
			file_open << model << " " << price << " " << producer << endl;

			cout << "Бажаєте додати ще телевiзор?(y/n) ";
			cin >> answer;
			cout << endl;
		} while (answer == "y");

		file_open.close();


	}
}
void RD(string type_file){
	if (type_file == "DAT") {
		string line;
		int count = 0;
		Student *student = new Student[100];
		ifstream file_open("INFO.DAT");

		while (file_open >> student[count].surname >> student[count].name >> student[count].adress >> student[count].phoneNumber)
		{
			count++;
		}


		for (int i = 0; i <= count; i++) 
			for (int j = 0; j <= count - i; j++) 
				if (student[j].phoneNumber < student[j + 1].phoneNumber) {
					Student temp = student[j];
					student[j] = student[j + 1];
					student[j + 1] = temp;
				}
		


	/*
		for (int j = count-1; j >= 0; j--) 
			for (int i = 0; i < j; i++)*/
			/*	if (student[i].phoneNumber > student[i + 1].phoneNumber)
				{
					Student temp = student[i];
					student[i] = student[i + 1];
					student[i + 1] = temp;
				}*/
			
		/*	for (int j = 0; j <= count; j++) 
				for (int i = 0; i < count - j - 1; i++)*/

		for (int i = 0; i < count; i++)
		{
			cout << student[i].surname << " " << student[i].name << " " << student[i].adress << " " << student[i].phoneNumber << endl;
		}

		file_open.close();	
	}
	if (type_file == "TXT") {
		ifstream file_open("INFO.TXT");
		int count = 0, max_price = 0;
		string max_price_model;
		while (file_open >> model >> price >> producer)
			if (price > max_price) {
				max_price = price;
				max_price_model = model;
			}
			
		cout << "Найдорожчий телевiзор: " << max_price_model << " " << max_price;
		file_open.close();
	}
}



void main() {
	setlocale(LC_ALL, "ukr");
	string action, type_file, DAT;

	cout << "З яким файлом ви хочете працювати (DAT/TXT) ";
	cin >> type_file;

	if (type_file == "DAT" || type_file == "dat")       // DAT
	{
		cout << "Що ви хочете зробити (ADD/READ) ";
		cin >> action;
		cout << endl;

		if (action == "ADD" || action == "add")
		{
			RW("DAT");
		}
		else if (action == "READ" || action == "read")
		{
			RD("DAT");
		}
	}


	if (type_file == "TXT" || type_file == "txt")      //TXT
	{
		cout << "Що ви хочете зробити (ADD/READ) ";
		cin >> action;
		cout << endl;
		if (action == "ADD" || action == "add")
		{
			RW("TXT");
		}
		else if (action == "READ" || action == "read")
		{
			RD("TXT");
		}
	}
	
}