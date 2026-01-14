#pragma once

// Структура для хранения информации по одной книге
struct Book;

// Добавление книги
void AddBook(std::vector<Book>& books);

// Поиск по названию
void NameSearch(std::vector<Book>& books);

// Поиск по автору
void AuthorSearch(std::vector<Book>& books);

// Поиск по жанру
void GenreSearch(std::vector<Book>& books);

// Вывод распределения по жанру
void GenreStatistics(std::vector<Book>& books);

// Вывод распределения по годам
void YearStatistics(std::vector<Book>& books);

// Вывод распределения по доступности
void AvailableStatistics(std::vector<Book>& books);

// Обработка задачи для вывода статистики
void StatisticsOutput(std::vector<Book>& books);

// Интерактивный цикл для системы управления библиотекой
void LibraryManagementSystem();