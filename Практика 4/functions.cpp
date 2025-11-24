#include "fuc_4.h" // заголовок (чтобы работали функции)
#include <cmath>
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <random>


using namespace std; 


void setColor(int text, int background) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (background << 4) | text);
}

void resetColor() {
	setColor(7, 0);
}

void printStars(int count) {
	setColor(15, 1); // Белые звезды на синем фоне
	for (int i = 0; i < count; i++) {
		cout << "* ";
	}
}

void printStripes(int color, int width) {
	setColor(color, color);
	for (int i = 0; i < width; i++) {
		cout << " ";
	}
}

long randomNext(long &state, long &counter, long m, long i, long c) {
	state = (m * state + counter) % c;
	counter++;
	return state;
}

void ex1() {
	cout << "\t ==== Задача 1 =====\n";
	cout << "«Геометрические фигуры». Вычислить площади прямоугольника, треугольника, круга" << endl;
	const float pi = 3.141592;
	float rad, h_tr, h_rect, base_tr, width_rect, circle_area, rect_area, tr_area;
	
	cout << "Прямоугольник:\n\tВедите ширину: ";
	cin >> width_rect;
	cout << "\tВведите высоту: ";
	cin >> h_rect;

	rect_area = abs(width_rect * h_rect);
	cout << "\n\tПлощадь прямоугольника: " << rect_area << endl;

	cout << "\nТреугольник:\n\tВедите основание : ";
	cin >> base_tr;
	cout << "\tВведите высоту: ";
	cin >> h_tr;

	tr_area = abs(0.5 * base_tr * h_tr);
	cout << "\n\tПлощадь треугольника: " << tr_area << endl;

	cout << "\nКруг:\n\tВведите радиус: ";
	cin >> rad;

	circle_area = abs(pi * rad * rad);
	cout << "\n\tПлощадь круга: " << circle_area << endl;
}

void ex2() {
	int flagWidth = 60;
	int stripeHeight = 1;

	// Цвета американского флага
	// Красный - 4, Белый - 15, Синий - 1

	vector<int> stripeColors = { 15, 4, 15, 4, 15, 4, 15 }; // Красные и белые полосы

	// Верхняя часть с синим полем и звездами
	for (int row = 0; row < 7; row++) {
		// Синее поле со звездами (кантон)
		setColor(15, 1);
		if (row % 2 == 0) {
			cout << "*   *   *   *   *   *";
			printStripes(4, flagWidth - 21);
			cout << endl;
		}
		else {
			cout << "  *   *   *   *   *  ";
			printStripes(15, flagWidth - 21);
			cout << endl;
		}
	}

	// Остальные полосы
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < stripeHeight; j++) {
			printStripes(stripeColors[i % stripeColors.size()], flagWidth);
			cout << endl;
		}
	}

	resetColor();	
}

void ex3() {
	cout << "\t ==== Задача 3 =====\n";
	cout << "«Синусоида»." << endl;
	const int WIDTH = 80;
	const int HEIGHT = 20;
	const double X_MIN = -5.0;
	const double X_MAX = 5.0;
	const double Y_MIN = -2.0;
	const double Y_MAX = 2.0;

	vector<vector<char>> grid(HEIGHT, vector<char>(WIDTH, ' '));

	// Заполняем график
	for (int col = 0; col < WIDTH; ++col) {
		double x = X_MIN + (X_MAX - X_MIN) * col / (WIDTH - 1);
		double y = sin(x);

		int row = static_cast<int>((Y_MAX - y) / (Y_MAX - Y_MIN) * (HEIGHT - 1));
		if (row >= 0 && row < HEIGHT) {
			grid[row][col] = '*';
		}
	}

	// Выводим результат
	for (const auto& line : grid) {
		for (char c : line) cout << c;
		cout << '\n';
	}
}

void ex4() {
	cout << "\t ==== Задача 4 =====\n";
	cout << "«Генератор псевдослучайных чисел»" << endl;
	long m1 = 37, i1 = 3, c1 = 64;
	long m2 = 25173, i2 = 13849, c2 = 65537;

	// Тестирование варианта 1
	cout << "=== Вариант 1 ===" << endl;
	long state1 = 0, counter1 = 0;
	for (int i = 0; i < 15; i++) {
		long value = randomNext(state1, counter1, m1, i1, c1);
		cout << "s" << i << " = " << value << endl;
	}

	// Тестирование варианта 2
	cout << "\n=== Вариант 2 ===" << endl;
	long state2 = 0, counter2 = 0;
	for (int i = 0; i < 10; i++) {
		cout << "s" << i << " = " << randomNext(state2, counter2, m2, i2, c2) << endl;
	}

}

void ex5() {
	cout << "\t ==== Задача 5 =====\n";
	cout << "«Алгоритмы сортировки»" << endl;
	cout << "Открой презентацию" << endl;
}

void ex6() {
	cout << "\t ==== Задача 6 =====\n";
	cout << "«Умножение матриц»" << endl;
	// Инициализация матрицы A (продажи)
	vector<vector<int>> A = {
		{5, 2, 0, 2},
		{3, 5, 2, 2},
		{20, 0, 0, 4}
	};

	// Инициализация матрицы B (цены и комиссионные)
	vector<vector<double>> B = {
		{2.0, 0.50},
		{3.0, 0.40},
		{4.0, 1.00},
		{5.0, 0.60}
	};

	// Умножение матриц A и B
	vector<vector<double>> C(3, vector<double>(2, 0.0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	// Вывод матрицы C
	cout << "Матрица C:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}

}