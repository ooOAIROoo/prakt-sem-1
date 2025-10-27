#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include "fuc.h"

using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string ex_num;

	cout << "	====== ПРАКТИКА 3 ======\n" << "ведите номер задачи: (0 - выход)  == ";
	cin >> ex_num;
	system("cls");

	while (true) {
		if (ex_num == "0") {
			exit(0);
		}
		if (ex_num == "1") {
			ex1();
		}
		if (ex_num == "2") {
			ex2();
		}
		if (ex_num == "3") {
			ex3();
		}
		if (ex_num == "4") {
			ex4();
		}
		if (ex_num == "5") {
			ex5();
		}
		if (ex_num == "6") {
			ex6();
		}

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << "\n\nведите номер задачи: (0 - выход)  == ";
		cin >> ex_num;
		system("cls");

	}

	return 0;
}