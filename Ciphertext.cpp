#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>

void CaesarСipher(const std::string& text) {
    int shift = -1;
    while (shift < 0) {
        std::cout << "Введите сдвиг:" << std::endl;
        std::cin >> shift;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            shift = -1;
        }
        if (shift < 0) {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    }
    std::cout << "Зашифрованный текст" << std::endl;
    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {
            std::cout << static_cast<char>('A' + (c - 'A' + shift) % ('Z' - 'A'));
        }
        else if (c >= 'a' && c <= 'z') {
            std::cout << static_cast<char>('a' + (c - 'a' + shift) % ('z' - 'a'));
        }
        else if (c >= 'А' && c <= 'Я') {
            std::cout << static_cast<char>('А' + (c - 'А' + shift) % ('Я' - 'А'));
        }
        else if (c >= 'а' && c <= 'я') {
            std::cout << static_cast<char>('а' + (c - 'а' + shift) % ('я' - 'а'));
        }
        else {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

void StatisticsCharacters(const std::string& text) {
    std::map<char, int> characters;
    for (char c : text) {
        ++characters[c];
    }
    std::cout << std::endl << "Статистика символов в тексте" << std::endl;
    std::cout << "Общее количество символов: " << text.size() << std::endl;
    for (auto [key, value] : characters) {
        std::cout << "Символ: \'" << key << "\' Количество повторений: " << value << std::endl;
    }
}

bool CheckPalindrome(const std::string& word)
{
    int left = 0;
    int right = word.size() - 1;
    while (right > left)
    {
        if (word[right] == word[left])
        {
            --right;
            ++left;
            continue;
        }
        return false;
    }
    return true;
}

void StatisticsWords(const std::string& text) {
    std::map<std::string, int> words;
    std::set<std::string> palindromes;
    std::string word;
    int cnt_words = 0;
    for (char c : text) {
        if (c!= '(' && c != ')' &&c != '.' && c != ' ' && c != '!' && c != '?' && c != ',' && c != ';' && c != ':' && c != '\"' && c != '\'' && c != '«' && c != '»') {
            if (c >= 'A' && c <= 'Z') {
                word.push_back(c - ('A' - 'a'));
            }
            else if (c >= 'А' && c <= 'Я') {
                word.push_back(c - ('А' - 'а'));
            }
            else {
                word.push_back(c);
            }
        }
        else {
            if (word.size() != 0) {
                ++words[word];
                ++cnt_words;
                if (CheckPalindrome(word)) {
                    palindromes.insert(word);
                }
            }
            word.resize(0);
        }
    }
    if (word.size() != 0) {
        ++words[word];
        ++cnt_words;
        if (CheckPalindrome(word)) {
            palindromes.insert(word);
        }
    }
    std::cout << std::endl << "Статистика слов в тексте" << std::endl;
    if (words.size() == 0) {
        std::cout << "Слов в тексте нет" << std::endl;
    }
    else 
    {
        std::cout << "Общее количество слов: " << cnt_words << std::endl;
        for (auto [key, value] : words) {
            std::cout << "Слово: \"" << key << "\" Количество повторений: " << value << std::endl;
        }
    }
    if (palindromes.size() == 0) {
        std::cout << "Палиндромов в тексте нет" << std::endl;
    } else
    {
        std::cout << "Палиндромы" << std::endl;
        for (std::string word : palindromes) {
            std::cout << "\"" << word << "\"" << std::endl;
        }
    }
}

void StatisticsSentences(const std::string& text) {
    std::map<std::string, int> sentences;
    std::string sentence;
    int cnt_sentences = 0;
    for (char c : text) {
        if (c != '.' && c != '!' && c != '?') {
            if (!(c == ' ' && sentence.size() == 0)) sentence.push_back(c);
        }
        else {
            if (sentence.size() != 0) {
                sentence.push_back(c);
                ++sentences[sentence];
                ++cnt_sentences;
            }
            sentence.resize(0);
        }
    }
    std::cout << std::endl << "Статистика предложений в тексте" << std::endl;
    if (sentences.size() == 0) {
        std::cout << "Предложений в тексте нет" << std::endl;
    }
    else
    {
        std::cout << "Общее количество предложений: " << cnt_sentences << std::endl;
        for (auto [key, value] : sentences) {
            std::cout << "Предложение: \"" << key << "\"" << std::endl << "Количество повторений: " << value << std::endl;
        }
    }
}

void StatisticsNumbers(const std::string& text) {
    std::map<int, int> numbers;
    int cnt_numbers = 0;
    for (char c : text) {
        if (c >= '0' && c <= '9') {
            ++cnt_numbers;
            ++numbers[c - '0'];
        }
    }
    std::cout << std::endl << "Статистика цифр в тексте" << std::endl;
    if (numbers.size() == 0) {
        std::cout << "Цифр в тексте нет" << std::endl;
    }
    else
    {
        std::cout << "Общее количество цифр: " << cnt_numbers << std::endl;
        for (auto [key, value] : numbers) {
            std::cout << "Цифра: \"" << key << "\" Количество повторений: " << value << std::endl;
        }
    }
}

void Cliphertext() {
    std::string text;
    int issue_number;
    do
    {
        std::cout << std::endl
            << "== ТЕКСТ-ШИФРОВАЛЬЩИК ==" << std::endl;
        std::cout << "Введите текст:" << std::endl;
        std::getline(std::cin, text);
        CaesarСipher(text);
        StatisticsCharacters(text);
        StatisticsWords(text); 
        StatisticsSentences(text);
        StatisticsNumbers(text);
        do
        {
            text.resize(0);
            std::cout << std::endl
                << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}