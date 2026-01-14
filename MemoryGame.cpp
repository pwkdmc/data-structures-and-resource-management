#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>

void MixCards(std::vector<std::vector<std::pair<int, bool>>>& field) {
    std::vector<int> available_numbers;
    for (int i = 1; i <= 12; ++i) {
        available_numbers.push_back(i);
        available_numbers.push_back(i);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            int rand_ind = rand() % available_numbers.size();
            field[i][j] = { available_numbers[rand_ind], false };
            available_numbers.erase(available_numbers.begin() + rand_ind);
        }
    }
}

void InputField(std::vector<std::vector<std::pair<int, bool>>>& field) {
    std::cout << std::string(29, '-') << std::endl;
    std::cout << "|";
    for (int i = 0; i <= 6; ++i) {
        if (i == 0) {
            std::cout << "   |";
        }
        else {
            std::cout << " " << i << " |";
        }
    }
    std::cout << std::endl << std::string(29, '-') << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "| " << i + 1 << " |";
        for (int j = 0; j < 6; ++j) {
            if (field[i][j].second) {
                std::cout << std::setw(2) << field[i][j].first << " |";
            }
            else {
                std::cout << "   |";
            }
        }
        std::cout << std::endl << std::string(29, '-') << std::endl;
    }
}

void Game() {
    std::vector<std::vector<std::pair<int, bool>>> field;
    field.resize(4);
    for (int i = 0; i < 4; ++i) {
        field[i].resize(6);
    }
    int score = 0;
    MixCards(field);
    while (score < 12) {
        std::cout << std::endl << "Счет: " << score << std::endl;
        InputField(field);
        int first = 0;
        int second = 0;
        bool check = false;
        while (!check) {
            std::cout << "Введите два двузначных числа (координаты карт, строка+столбец):" << std::endl;
            check = true;
            std::cin >> first >> second;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                first = -1;
                second = -1;
            }
            if (first % 10 < 1 || first % 10 > 6 || second % 10 < 1 || second % 10 > 6 ||
                first / 10 < 1 || first / 10 > 4 || second / 10 < 1 || second / 10 > 4 ||
                field[first / 10 - 1][first % 10 - 1].second || field[second / 10 - 1][second % 10 - 1].second ||
                first == second) {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
                check = false;
            }
        }
        field[first / 10 - 1][first % 10 - 1].second = true;
        field[second / 10 - 1][second % 10 - 1].second = true;
        ++score;
        if (field[first / 10 - 1][first % 10 - 1].first != field[second / 10 - 1][second % 10 - 1].first) {
            std::cout << std::endl;
            InputField(field);
            field[first / 10 - 1][first % 10 - 1].second = false;
            field[second / 10 - 1][second % 10 - 1].second = false;
            --score;
        }
    }
    std::cout << std::endl << "Счет: " << score << std::endl;
    InputField(field);
}

void MemoryGame() {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "== ИГРА НА ПАМЯТЬ С ДИНАМИЧЕСКИМИ СТРУКТУРАМИ ==" << std::endl;
        std::cout << "1. Начать игру" << std::endl;
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
            Game();
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    } while (issue_number != 0);
}