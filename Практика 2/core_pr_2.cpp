#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;


int ex1()
{
	cout << "\t===== Задача 1 =====" << endl;
	float x, a;

	cout << "введите значение а: ";
	cin >> a;
	cout << "\nвведите значение х: ";
	cin >> x;
	cout << "\n\n";

	if (abs(x) < 1 and x != 0) {
		cout << a * log(abs(x));
	}
	else if ((abs(x) >= 1) && (a - x * x > 0)) {
		cout << sqrt(a - x * x);
	}
	else {
		cout << "err. ошибка задания х и а. нарушены правила математики";
	}
	return 0;
}

int ex2() {
	cout << "\t===== Задача 2 =====" << endl;
	float b, y, x;

	cout << "введите значение b: ";
	cin >> b;
	cout << "\nвведите значение y: ";
	cin >> y;
	cout << "\nвведите значение x: ";
	cin >> x;
	cout << "\n\n";

	if ((b - y) > 0 && (b - x) >= 0) {
		cout << log(b - y) * sqrt(b - x);
	}
	else {
		cout << "err. ошибка задания b, y или x. функция неопределена";
	}
	return 0;
}

int ex3() {
	cout << "\t===== Задача 3 =====" << endl;
	float num;

	cout << "введите начальное значение N: ";
	cin >> num;

	if (num < 0) {
		num = 1;
	}

	if (num == 0) {
		num = 1;
	}

	if (int(num) != num) {
		num = int(num) + 1;
	}


	for (int i = 0; i < 10; i += 1) {
		cout << num + i << " ";
	}
	return 0;
}

int ex4() {
	cout << "\t===== Задача 4 =====" << endl;
	for (float x = -4; x <= 4; x += 0.5) {
		if (x - 1 != 0) {
			cout << "x: " << x << "\ty:" << (x * x - 2 * x + 2) / (x - 1) << endl;
		}
		else if (x - 1 == 0) {
			cout << "x: " << x << "\ty:" << "выколотая точка" << endl;
		}
	}
	return 0;
}

int ex5() {
	cout << "\t===== Задача 5 =====" << endl;
	float S, p, r;
	int  n;

	cout << "введите S (сумма долга): ";
	cin >> S;
	cout << "\nвведите p (процент): ";
	cin >> p;
	cout << "\nвведите n (кол-во лет): ";
	cin >> n;

	r = p / 100;

	if ((pow((1 + r), n) - 1) > 0) {
		cout << "\nмесячная выплата: " << (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
	}
	else if (p == 0) {
		cout << "\nмесячная выплата: " << S / (n * 12);
	}
	else if (r < 0) {
		cout << "\nмесячная выплата: " << (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
	}
	return 0;
}

int ex6() {
	cout << "\t===== Задача 6 =====" << endl;

	double S, m, left, right, p, r, monthly_payment;
	int n;

	cout << "Введите S (сумма долга): ";
	cin >> S;
	cout << "Введите m (месячная выплата): ";
	cin >> monthly_payment;
	cout << "Введите n (кол-во лет): ";
	cin >> n;

	left = -20.0;
	right = 120.0;

	while (right - left > 1e-2) {
		p = (left + right) / 2;
		r = p / 100;

		m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

		if (m < monthly_payment) {
			left = p;
		}
		if (m > monthly_payment) {
			right = p;
		}
	}

	cout << "процент: " << p << endl;

	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string ex_number;
	cout << "ведите номер задачи: (0 - выход)  == ";
	cin >> ex_number;
	system("cls");

	while (TRUE) {
		if (ex_number == "0") {
			exit(0);
		}
		else if (ex_number == "1") {
			ex1();
		}
		else if (ex_number == "2") {
			ex2();
		}
		else if (ex_number == "3") {
			ex3();
		}
		else if (ex_number == "4") {
			ex4();
		}
		else if (ex_number == "5") {
			ex5();
		}
		else if (ex_number == "6") {
			ex6();
		}

		cout << "\n \n \nведите номер задачи: (0 - выход) == "; // повторение 
		cin >> ex_number;
		system("cls"); // очистка консоли
	}


	return 0;
}