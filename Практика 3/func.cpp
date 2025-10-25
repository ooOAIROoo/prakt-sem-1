#include "fuc.h" // заголовок
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

// C:\test_files\course_1\pr_3\num1.txt
// C:\test_files\course_1\pr_3\num2.txt
// C:\test_files\course_1\pr_3\num3.txt

int ex1() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << u8"\t ==== Задача 1 =====\n";
    cout << u8"«Копирование файла». Создать на диске текстовый файл и скопировать его на экран." << endl;

    string filename;

    cout << u8"Укажите путь к файлу: ";
    cin >> filename;
    cout << "\n" << endl;

    ifstream file_test_1(filename);

    if (!file_test_1.is_open()) {
        cout << u8"Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    while (getline(file_test_1, line)) {
        cout << line << endl;
    }

    file_test_1.close();
    return 0;
}


int ex2() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << u8"\t ==== Задача 2 ====" << endl;
    cout << u8"«Фильтр». Вывести на экран только числа из созданного Вами на диске текстового файла, содержащего буквы и числа." << endl;

    wstring filename;

    cout << u8"Укажите путь к файлу: ";
    wcin >> filename;

    ifstream file_test_2(filename);

    if (!file_test_2.is_open()) {
        cout << u8"Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    
    cout << u8"Все цифры в файле: ";
    while (getline(file_test_2, line)) {
        for (char c : line) {
            if (c >= '0' && c <= '9') {
                cout << c;
            }
        }

    }

    file_test_2.close();
    return 0;
}

int ex3() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << u8"\t ==== Задача 3 ====" << endl;
    cout << u8"«Сортировка букв». Задать строку из 30 букв и расставить их в алфавитном порядке." << endl;

    wstring filename;

    cout << u8"Укажите путь к файлу: ";
    wcin >> filename;

    ifstream file_test_3(filename);

    if (!file_test_3.is_open()) {
        cout << u8"Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    while (getline(file_test_3, line)) {
        sort(line.begin(), line.end());
        cout << line;

    }

    file_test_3.close();
    return 0;

    return 0;
}

int ex4() {
    cout << "\t ==== Задача 4 ====" << endl;
    cout << "«Алгоритм Евклида». Задать 2 числа и найти их наибольший общий делитель двумя способами : делением и вычитанием.";


    return 0;
}

int ex5() {
    cout << "\t ==== Задача 5 ====" << endl;
    cout << "«Решето Эратосфена». Найти все простые числа в диапазоне от 2 до введенного вами натурального числа.";


    return 0;
}

int ex6() {
    cout << "\t ==== Задача 6 ====" << endl;
    cout << "«Файл». Создать файл, записать в него 10 чисел, закрыть, потом вновь открыть файл и найти сумму чисел.";


    return 0;
}