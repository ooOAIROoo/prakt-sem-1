#include "fuc_5.h" // заголовок (чтобы работали функции)
#include <cmath>
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <unordered_map>


using namespace std;

bool isValidRoNum(const string roman) { 
    // добавить регулярные выражения
    vector<string> inValid = {
        "IIII", "VV", "XXXX", "LL",
        "CCCC", "DD", "MMMM",
        "IL", "IC", "ID", "IM",
        "XD", "XM", "VX", "VL",
        "VC", "VD", "VM", "LC",
        "LD", "LM", "DM"
    };

    for (int i = 0; i < inValid.size(); i++) {
        size_t pos = roman.find(inValid[i]);

        if (pos != std::string::npos) {
            return false;
        }
    }

    return true;
}

int romanToDecimal(const string roman) {
    // Карта значений римских цифр
    unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int n = roman.length();

    for (int i = 0; i < n; i++) {
        // Проверяем, есть ли следующий символ и образуют ли они вычитаемую пару
        if (i + 1 < n) {
            // Проверяем все возможные вычитаемые пары
            if (roman[i] == 'I' && roman[i + 1] == 'V') {
                total += 4; // 5 - 1
                i++; // Пропускаем следующий символ
                continue;
            }
            if (roman[i] == 'I' && roman[i + 1] == 'X') {
                total += 9; // 10 - 1
                i++;
                continue;
            }
            if (roman[i] == 'X' && roman[i + 1] == 'L') {
                total += 40; // 50 - 10
                i++;
                continue;
            }
            if (roman[i] == 'X' && roman[i + 1] == 'C') {
                total += 90; // 100 - 10
                i++;
                continue;
            }
            if (roman[i] == 'C' && roman[i + 1] == 'D') {
                total += 400; // 500 - 100
                i++;
                continue;
            }
            if (roman[i] == 'C' && roman[i + 1] == 'M') {
                total += 900; // 1000 - 100
                i++;
                continue;
            }
        }

        // Если не было вычитаемой пары, просто добавляем значение текущего символа
        total += values[roman[i]];
    }

    return total;
}

void ex1() 
{
	cout << "\t ==== Задача 1 =====\n";
	cout << "Задание «Автоматный распознаватель»" << endl;
    int num;
	string Input_num, Num_str;
	char Current_char;
	

	cout << "Введите римское число: ";
	cin >> Input_num;

	for (int i = 0; i <= Input_num.size(); i++) {
		Current_char = toupper(Input_num[i]);
		Num_str.push_back(Current_char);
	}

    if ( !isValidRoNum(Num_str) ) {
        cout << "Неправильное римское число." << endl;
        return;
    }


    num = romanToDecimal(Num_str);
    
    cout << "\nЧисло: " << num << endl;
    return;
}

void ex2()
{
	cout << "\t ==== Задача 2 =====\n";
	cout << "Задание «Системы счисления»" << endl;
    int old_base, new_base, num;

    cout << "Введите основание исходного числа: ";
    cin >> old_base;
    cout << "\nИсходное число: ";
    cin >> num;
    cout << "\nВведите новое основание: ";
    cin >> new_base;


}

void ex3()
{
	cout << "\t ==== Задача 3 =====\n";
	cout << "Задание «Обработка текстовых файлов»" << endl;
}

void ex4()
{
	cout << "\t ==== Задача 4 =====\n";
	cout << "Задание «Ряды»" << endl;
}

void ex5()
{
	cout << "\t ==== Задача 5 =====\n";
	cout << "5.5 Задание «Файлы»" << endl;
}

void ex6()
{
	cout << "\t ==== Задача 6 =====\n";
	cout << "Задание «Шарики»" << endl;
}