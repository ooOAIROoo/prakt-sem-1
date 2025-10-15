#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>
#include <cstdlib>



using namespace std;
// подготовка библиотек и пространства имен
// дальше идут функции заданий


// вспомогательные функции
float eq_type(float a, float b, float c) // возвращает тип уравнения - для 4 го задания (ошибки включены в проверку)
{
	int tpe = 0;

	if (a != 0) {
		tpe = 1;
	}

	else if (a == 0 and b != 0) {
		tpe = 2;
	}

	else if (a == 0 and b == 0 and c == 0) {
		tpe = 3;
	}

	else if (a == 0 and b == 0 and c != 0) {
		tpe = 4;
	}

	return tpe;
}

float get_discriminant(float a, float b, float c) // возвращает дискриминант - для 4-го задания
{
	return (b * b) - (4 * a * c);
}

// функции заданий
// первое задание
int ex1()
{
	cout << "\t===== Задача 1 =====" << endl;
	string name;

	cout << "введите ваше имя?" << endl;
	cin >> name;
	cout << "\nПривет, " << name;
	return 0;
}

// второе задание
int ex2()
{
	cout << "\t===== Задача 2 =====" << endl;

	float num1 = 0;
	float num2 = 0;

	cout << "введите первое число: ";
	cin >> num1;
	cout << "\nвведите второе число: ";
	cin >> num2;
	cout << "\n";

	if (num2 != 0) {
		cout << "сумма: " << num1 + num2 << "\nразность: " << num1 - num2;
		cout << "\nумножение: " << num1 * num2 << "\nделение: " << num1 / num2 << endl;
	}
	else if (num2 == 0) {
		cout << "сумма: " << num1 + num2 << "\nразность: " << num1 - num2;
		cout << "\nделение: делить на ноль нелья";
	}
	else if (num1 == 0 && num2 == 0) {
		cout << "ничего. ноль с нулём складываем, вычитаем и тп, как это посчитать?";
	}
	return 0;
}

// третье задание
int ex3()
{
	cout << "\t===== Задача 3 =====" << endl;
	float B = 0;
	float C = 0;
	float x = 0;

	cout << "введите число В: ";
	cin >> B;
	cout << "\nвведите число С: ";
	cin >> C;

	if (B != 0) {
		x = (-1 * C) / B;
		cout << "x = " << x;
	}
	else if (B == 0) {
		cout << "уравнение не имеет решений. на ноль делить нельзя";
	}
	else if (B != 0 && C == 0) {
		cout << "уравнение имеет бесконечно много решений";
	}
	return 0;
}
// задание 4
int ex4()
{
	cout << "\t===== Задача 4 =====" << endl;
	float a = 0;
	float b = 0;
	float c = 0;
	float x0 = 0;
	float x1 = 0;
	float x2 = 0;
	float D = 0;
	int type;

	cout << "введите числа a, b и c\n";
	cin >> a >> b >> c;

	type = eq_type(a, b, c); // вызов вспомогательных функций
	D = get_discriminant(a, b, c);
	if (D < 0) {
		cout << "err. discr. < 0, действительных решений не найдено";
	}
	else if (type == 1 && D >= 0) { // тип 1 - про квадратные ур

		x1 = ((-1) * b - sqrt(D)) / (2 * a);
		x2 = ((-1) * b + sqrt(D)) / (2 * a);

		cout << "x1 = " << x1 << "\nx2 = " << x2;
	}

	else if (type == 2) { // тип 2 - линейные 
		x0 = (-1) * c / (b);

		cout << "x = " << x0;
	}

	else if (type == 3) {
		cout << "a, b и c равны нулю ==> х - все действ. числа";
	}

	else if (type == 4) {
		cout << "err. коэффы перед х равны нулю. нет корней";
	}

	return 0;
}

// пятое задание
int ex5()
{
	cout << "\t===== Задача 5 =====" << endl;
	char day;
	char winws;
	char lamp;

	cout << "на улице день? (Y/N): ";
	cin >> day;
	cout << "\nокна открыты? (Y/N): ";
	cin >> winws;
	cout << "\nвключена лапа? (Y/N): ";
	cin >> lamp;

	day = toupper(day);  // учет нижнего регистра (на всякий случай)
	winws = toupper(winws);
	lamp = toupper(lamp);

	if ((day == 'Y' && winws == 'Y') || lamp == 'Y') {
		cout << "в комнате светло";
	}
	else {
		cout << "в комнате темно";
	}

	return 0;
}

int ex6()
{
	cout << "\t===== Задача 6 =====" << endl;
	float R, r, h, volume, surf_area, pi;
	pi = 3.1415926535;
	cout << "введите значение R:  ";
	cin >> R;
	cout << "\nвведите значение r:  ";
	cin >> r;
	cout << "\nвведите значение h:  ";
	cin >> h;

	if (R > 0 && r > 0 && R != r && h > 0) {
		volume = (static_cast<float>(1) / 3) * pi * h * (R * R + R * r + r * r);
		surf_area = pi * (R * R + r * r) + pi * (R + r) * sqrt(h * h + (R - r) * (R - r));

		cout << "\n";
		cout << "объём: " << volume << "\nплощадь: " << surf_area;
	}
	else {
		cout << "err. такого усеченного конуса не существует";
	}
	return 0;
}


// главная функция в которой вызываются задания
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string ex_number;
	cout << "ведите номер задачи: (0 - выход)  == ";
	cin >> ex_number;

	while (TRUE) {
		// вызовы функций 
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