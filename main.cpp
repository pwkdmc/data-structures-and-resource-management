#include <iostream>
#include "SmartPerformanceAnalyzer.h"
#include "Ciphertext.h"
#include "StudentDatabase.h"
#include "LibraryManagementSystem.h"
#include "MemoryGame.h"

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int issue_number;
    do
    {
        std::cout << std::endl
            << "=== ЛАБОРАТОРНАЯ РАБОТА 4 ===" << std::endl;
        std::cout << "1. Умный анализатор успеваемости" << std::endl;
        std::cout << "2. Текст-шифровальщик" << std::endl;
        std::cout << "3. База данных студентов" << std::endl;
        std::cout << "4. Система управления библиотекой" << std::endl;
        std::cout << "5. Игра на память с динамическими структурами" << std::endl;
        std::cout << "0. Выход" << std::endl
            << std::endl;
        std::cout << "Выберите действие: " << std::endl;
        std::cin >> issue_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            issue_number = -1;
        }
        if (issue_number == 1)
        {
            SmartPerfomanceAnalyzer();
        }
        else if (issue_number == 2)
        {
            Cliphertext();
        }
        else if (issue_number == 3)
        {
            StudentDatabase();
        }
        else if (issue_number == 4)
        {
            LibraryManagementSystem();
        }
        else if (issue_number == 5)
        {
            MemoryGame();
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    } while (issue_number != 0);
    return 0;
}