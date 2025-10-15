#include "fuc.h" // заголовок
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int ex1() {
    SetConsoleOutputCP(65001);

    cout << "\t ==== Задача 1 ===\n";
    cout << "«Копирование файла». Создать на диске текстовый файл и скопировать его на экран." << endl;
    // C:\test_files\course_1\pr_3\num1.txt


    wstring filename;

    cout << "Укажите путь к файлу: ";
    wcin >> filename;

    // Используем wifstream для широких символов
    wifstream file_test_1(filename);

    if (!file_test_1.is_open()) { // проверка открытия файла
        cout << "Ошибка открытия файла!" << endl;
    }

    wstring line;
    int lineNumber = 1;

    while (getline(file_test_1, line)) {
        cout << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    file_test_1.close();
    return 0;
}


int ex2() {
    cout << "\t ==== Задача 2 ===" << endl;
    cout << "«Фильтр». Вывести на экран только числа из созданного Вами на диске текстового файла, содержащего буквы и числа.";

    wstring filename;

    cout << "Укажите путь к файлу: ";
    wcin >> filename;

    wifstream file_test_2(filename);

    if (!file_test_2.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    return 0;
}

int ex3() {
    cout << "\t ==== Задача 3 ===" << endl;
    cout << "«Сортировка букв». Задать строку из 30 букв и расставить их в алфавитном порядке.";



    return 0;
}

int ex4() {
    cout << "\t ==== Задача 4 ===" << endl;
    cout << "«Алгоритм Евклида». Задать 2 числа и найти их наибольший общий делитель двумя способами : делением и вычитанием.";


    return 0;
}

int ex5() {
    cout << "\t ==== Задача 5 ===" << endl;
    cout << "«Решето Эратосфена». Найти все простые числа в диапазоне от 2 до введенного вами натурального числа.";


    return 0;
}

int ex6() {
    cout << "\t ==== Задача 6 ===" << endl;
    cout << "«Файл». Создать файл, записать в него 10 чисел, закрыть, потом вновь открыть файл и найти сумму чисел.";


    return 0;
}