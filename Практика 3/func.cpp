#include "fuc.h" // заголовок
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;

// C:\test_files\course_1\pr_3\num1.txt
// C:\test_files\course_1\pr_3\num2.txt
// C:\test_files\course_1\pr_3\num3.txt


int gcdByDivision(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;  
        a = temp;
    }
    return a;
}

int gcdBySubtraction(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

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
        int length = line.length();

        // Сортировка пузырьком
        for (int i = 0; i < length - 1; i++) {
            // Последние i элементов уже отсортированы
            for (int j = 0; j < length - i - 1; j++) {
                // Сравниваем соседние символы
                if (line[j] > line[j + 1]) {
                    // Меняем местами, если нужно
                    char temp = line[j];
                    line[j] = line[j + 1];
                    line[j + 1] = temp;
                }
            }
        }
        cout << line << endl;

    }

    file_test_3.close();
    return 0;
}

int ex4() {
    cout << "\t ==== Задача 4 ====" << endl;
    cout << "«Алгоритм Евклида». Задать 2 числа и найти их наибольший общий делитель двумя способами : делением и вычитанием." << endl;
    
    int  a, b, res1, res2;

    cout << "Введите первое число: " << endl;
    cin >> a;
    cout << "Введите второе число: " << endl;
    cin >> b;

    res1 = gcdByDivision(a, b);
    res2 = gcdBySubtraction(a, b);

    cout << "\nНОД делением: " << res1 << "\nНОД вычитанием: " << res2 << endl;
    return 0;
}

int ex5() {
    cout << "\t ==== Задача 5 ====" << endl;
    cout << "Найти все простые числа в диапазоне от 2 до введенного вами натурального числа." << endl;
    int num;
    

    cout << "Введите натуральное число: ";
    cin >> num;
    
    if (num < 2) {
        cout << "\nПростых чисел не найдено." << endl;
        return 0;
    }

    cout << "\n\nПростые числа найденные в дапозоне от 2 до " << num << ":" << endl;

    for (int i = 2; i <= num; i++) {
        if (isPrime(i) == true) {
            cout << i << " ";
        }
    }

    return 0;
}

int ex6() {
    cout << "\t ==== Задача 6 ====" << endl;
    cout << "«Файл». Создать файл, записать в него 10 чисел, закрыть, потом вновь открыть файл и найти сумму чисел." << endl;

    ofstream fout("numbers.txt"); // Создаём и открываем файл для записи

    // Записываем 10 чисел с клавиатуры в файл
    cout << "Введите 10 чисел:" << endl;
    for (int i = 0; i < 10; i++) {
        float num;
        cin >> num;
        fout << num << " "; // Числа разделяются пробелами
    }
    fout.close(); // Закрываем файл

    ifstream fin("numbers.txt"); // Открываем файл для чтения
    float sum = 0;

    // Считываем числа и вычисляем сумму
    for (int i = 0; i < 10; i++) {
        float num;
        fin >> num;
        sum += num;
    }
    fin.close(); // Закрываем файл

    // Выводим результат
    cout << "Сумма чисел: " << sum << endl;

    return 0;

    return 0;
}