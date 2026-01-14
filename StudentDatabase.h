#pragma once

// Структура для хранения информации по одному студенту
struct StudentData;

// Интерактивный цикл для базы данных студентов
void StudentDatabase();

// Добавление студента в базу данных
void AddStudent(std::vector<StudentData>& students);

// Вывод базы данных
void ViewDatabase(std::vector<StudentData>& students);

// Поиск студента по имени
void StudentSearch(std::vector<StudentData>& students);

// Экспорт базы данных в файл
void ExportToFile(std::vector<StudentData>& students);

// Вывод статистики по возрастам
void AgeStatistics(std::vector<StudentData>& students);

// Поиск общего среднего балла студента
double AverageGrade(StudentData& student);

// Вывод статистики по средним баллам
void GradeStatistics(std::vector<StudentData>& students);

/// Обработка задачи для вывода статистики
void StatisticsOutput(std::vector<StudentData>& students);

// Интерактивный цикл для базы данных студентов
void StudentDatabase();