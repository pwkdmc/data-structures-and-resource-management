#pragma once

// Шифрование текста шифром Цезаря
void CaesarСipher(const std::string& text);

// Вывод статистики символов
void StatisticsCharacters(const std::string& text);

// Проверка слова на палиндром
bool CheckPalindrome(const std::string& word);

// Вывод статистики слов
void StatisticsWords(const std::string& text);

// Вывод статистики предложений
void StatisticsSentences(const std::string& text);

// Вывод статистики цифр
void StatisticsNumbers(const std::string& text);

// Интерактивный цикл для умного анализатора успеваемости
void Cliphertext();