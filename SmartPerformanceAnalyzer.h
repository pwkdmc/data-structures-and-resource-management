#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>

// Структура для хранения информации по одному студенту
struct Student;

// Сокращение строки до определенного числа символов
std::string truncateStr(std::string& str, int size);

// Ввод журнала оценок
void EnteringSchoolGradeLog(std::vector<Student>& studentss);

// Поиск среднего арифметического в массиве чисел
double Average(std::vector<int> num);

// Подсчет среднего арифметического каждого студента и сортировка по убыванию
void StudentPerformanceRating(std::vector<Student>& students, std::map<double, std::vector<std::string>, std::greater<double>>& average);

// Подсчет среднего арифметического по каждому предмету и определение проблемных
void ProblematicSubjects(std::vector<Student>& students, std::vector<std::pair<std::string, double>>& problematic_subjects);

// Вывод анализа
void AnalysisOutput(std::vector<Student>& students);

// Интерактивный цикл для умного анализатора успеваемости
void SmartPerfomanceAnalyzer();