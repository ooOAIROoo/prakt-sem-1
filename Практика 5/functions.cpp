#include "fuc_5.h" // заголовок (чтобы работали функции)
#include <cmath>
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <unordered_map>
#include <regex>


using namespace std;

// Вспомогательная функция для конвертации символа
int chToInt(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

// Проверка валидности римского числа
bool isValidRoNum(const string& roman) {
    // Основной паттерн
    regex pattern("^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
    if (!regex_match(roman, pattern)) return false;

    // Невалидные комбинации
    vector<regex> invalidPatterns = {
        regex("IIII"), regex("VV"), regex("XXXX"), regex("LL"),
        regex("CCCC"), regex("DD"), regex("MMMM"),
        regex("IL"), regex("IC"), regex("ID"), regex("IM"),
        regex("XD"), regex("XM"), regex("VX"), regex("VL"),
        regex("VC"), regex("VD"), regex("VM"), regex("LC"),
        regex("LD"), regex("LM"), regex("DM")
    };

    for (const auto& invalidPattern : invalidPatterns) {
        if (regex_search(roman, invalidPattern)) {
            return false;
        }
    }
    return true;
}

// Конвертация римского в арабское
int roToAr(string str) {
    if (!isValidRoNum(str)) {
        return 0;
    }

    if (str.empty()) return 0;

    int num = chToInt(str[0]);

    for (int i = 1; i < str.length(); i++) {
        int curr = chToInt(str[i]);
        int pre = chToInt(str[i - 1]);

        if (curr <= pre) {
            num += curr;
        }
        else {
            num = num - pre * 2 + curr;
        }
    }
    return num;
}

long long toDecimal(const string& number, int base) {
    long long result = 0;
    long long power = 1;

    for (int i = number.length() - 1; i >= 0; i--) {
        char digit = number[i];
        int value;

        if (isdigit(digit)) {
            value = digit - '0';
        }
        else if (isalpha(digit)) {
            char upperDigit = toupper(digit);
            value = 10 + (upperDigit - 'A');
        }
        else {
            throw invalid_argument("Недопустимый символ в числе");
        }

        if (value >= base) {
            throw invalid_argument("Цифра превышает допустимое значение для данной системы счисления");
        }

        result += value * power;
        power *= base;
    }

    return result;
}

string fromDecimal(long long number, int base) {
    if (number == 0) return "0";

    string result = "";
    while (number > 0) {
        int remainder = number % base;
        char digit;

        if (remainder < 10) {
            digit = '0' + remainder;
        }
        else {
            digit = 'A' + (remainder - 10);
        }

        result = digit + result;
        number /= base;
    }

    return result;
}

// Функция проверки допустимости основания системы счисления
bool isValidBase(int base) {
    return base >= 2 && base <= 36;
}

// Функция проверки, что число соответствует указанной системе счисления
bool isValidNumber(const string& number, int base) {
    for (char digit : number) {
        int value;

        if (isdigit(digit)) {
            value = digit - '0';
        }
        else if (isalpha(digit)) {
            char upperDigit = toupper(digit);
            value = 10 + (upperDigit - 'A');
        }
        else {
            return false;
        }

        if (value >= base) {
            return false;
        }
    }
    return true;
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

    for (int i = 0; i < Input_num.size(); i++) {
        Current_char = toupper(Input_num[i]);
        Num_str.push_back(Current_char);
    }

    if (!isValidRoNum(Num_str)) {
        cout << "Неправильное римское число." << endl;
        return;
    }

    num = roToAr(Num_str);

    cout << "\nЧисло: " << num << endl;
    return;
}

void ex2() {
    cout << "\t ==== Задача 2 =====\n";
    cout << "Задание «Системы счисления»" << endl;

    int old_base, new_base;
    string num;

    cout << "Введите основание исходного числа (2-36): ";
    cin >> old_base;

    // Проверка основания исходного числа
    if (!isValidBase(old_base)) {
        cout << "Ошибка: Основание системы счисления должно быть от 2 до 36" << endl;
        return;
    }

    cout << "Исходное число: ";
    cin >> num;

    // Проверка, что число соответствует старой системе счисления
    if (!isValidNumber(num, old_base)) {
        cout << "Ошибка: Число не соответствует указанной системе счисления!" << endl;
        return;
    }

    cout << "Введите новое основание (2-36): ";
    cin >> new_base;

    // Проверка нового основания
    if (!isValidBase(new_base)) {
        cout << "Ошибка: Основание системы счисления должно быть от 2 до 36" << endl;
        return;
    }

    try {
        // Преобразование в десятичную систему
        long long decimalValue = toDecimal(num, old_base);

        // Преобразование из десятичной в новую систему
        string result = fromDecimal(decimalValue, new_base);

        // Вывод результата
        cout << "Результат: " << result << endl;

    }
    catch (const exception& e) {
        cout << "Ошибка при преобразовании: " << e.what() << endl;
    }
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