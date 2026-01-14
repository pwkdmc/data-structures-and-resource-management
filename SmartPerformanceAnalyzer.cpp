#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>

struct Student {
    std::string name;
    std::vector<std::pair<std::string, std::vector<int>>> grades;
};

std::string truncateStr(std::string& str, int size) {
    if (str.size() > size) {
        return str.substr(0, size);
    }
    return str;
}

void EnteringSchoolGradeLog(std::vector<Student>& students) {
    int cnt_students = -1;
    while (cnt_students < 1) {
        std::cout << "Введите количество студентов:" << std::endl;
        std::cin >> cnt_students;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            cnt_students = -1;
        }
        if (cnt_students < 1) {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    }
    for (int i = 0; i < cnt_students; ++i) {
        std::cout << "Введите имя студента " << i + 1 << ":" << std::endl;
        std::string name;
        std::getline(std::cin, name);
        students.push_back(Student(name));
    }
    int cnt_subjects = -1;
    while (cnt_subjects < 1) {
        std::cout << "Введите количество предметов:" << std::endl;
        std::cin >> cnt_subjects;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            cnt_subjects = -1;
        }
        if (cnt_subjects < 1) {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    }
    std::set<std::string> subjects;
    for (int i = 0; i < cnt_subjects; ++i) {
        std::cout << "Введите название предмета " << i + 1 << ": " << std::endl;
        std::string name;
        std::getline(std::cin, name);
        subjects.insert(name);
    }
    for (int i_student = 0; i_student < cnt_students; ++i_student) {
        std::cout << "Студент " << students[i_student].name << ":" << std::endl;
        for (std::string subject : subjects) {
            int cnt_grades = -1;
            while (cnt_grades < 1) {
                std::cout << "Введите количество оценок по предмету \"" << subject << "\":" << std::endl;
                std::cin >> cnt_grades;
                std::cin.ignore(10000, '\n');
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    cnt_grades = -1;
                }
                if (cnt_grades < 1) {
                    std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
                }
            }
            std::vector<int> grades;
            while (grades.size() != cnt_grades) {
                std::cout << "Введите " << cnt_grades << " оценок (от 2 до 5):" << std::endl;
                grades.resize(0);
                for (int i = 0; i < cnt_grades; ++i) {
                    int grade;
                    std::cin >> grade;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        grade = -1;
                    }
                    if (grade < 2 || grade > 5) {
                        std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
                        break;
                    }
                    grades.push_back(grade);
                }
                std::cin.ignore(10000, '\n');
            }
            students[i_student].grades.push_back({subject, grades});
        }
    }
}

double Average(std::vector<int> num) {
    double sum = 0;
    for (int i = 0; i < num.size(); ++i) {
        sum += num[i];
    }
    return sum / num.size();
}

void StudentPerformanceRating(std::vector<Student>& students, std::map<double, std::vector<std::string>, std::greater<double>>& average) {
    for (Student student : students) {
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i < student.grades.size(); ++i) {
            for (int j = 0; j < student.grades[i].second.size(); ++j) {
                sum += student.grades[i].second[j];
                cnt += 1;
            }
        }
        double average_grade = round(sum / cnt * 10) / 10;
        average[average_grade].push_back(student.name);
    }
}

void ProblematicSubjects(std::vector<Student>& students, std::vector<std::pair<std::string, double>>& problematic_subjects) {
    for (int i = 0; i < students[0].grades.size(); ++i) {
        double sum = 0;
        int cnt = 0;
        for (Student student : students) {
            for (int j = 0; j < student.grades[i].second.size(); ++j) {
                sum += student.grades[i].second[j];
                ++cnt;
            }
        }
        double average_grade = round(sum / cnt * 10) / 10;
        if (average_grade < 3.5) problematic_subjects.push_back({ students[0].grades[i].first, average_grade });
    }
}

void AnalysisOutput(std::vector<Student>& students) {
    std::cout << "Средний балл по каждому предмету" << std::endl;
    for (int i = 0; i < static_cast<int>(students[0].grades.size()) - 4; i += 5) {
        std::cout << std::string(127, '-') << std::endl;
        std::cout << "|" << std::setw(21) << "|";
        for (int j = 0; j < 5; ++j) {
            std::cout << std::setw(10 + std::min(static_cast<int>(students[0].grades[i + j].first.size()), 20) / 2) << truncateStr(students[0].grades[i + j].first, 20)
                << std::setw(11 - std::min(static_cast<int>(students[0].grades[i + j].first.size()), 20) / 2) << "|";
        }
        std::cout << std::endl << std::string(127, '-') << std::endl;
        for (Student student : students) {
            std::cout << "|" << std::setw(10 + std::min(static_cast<int>(student.name.size()), 20) / 2) << truncateStr(student.name, 20)
                << std::setw(11 - std::min(static_cast<int>(student.name.size()), 20) / 2) << "|";
            for (int j = 0; j < 5; ++j) {
                std::cout << std::setw(11) << std::fixed << std::setprecision(1) << Average(student.grades[i + j].second)
                    << std::setw(10) << "|";
            }
            std::cout << std::endl << std::string(127, '-') << std::endl;
        }
    }
    if (students[0].grades.size() % 5 > 0) {
        std::cout << std::string(21 * (students[0].grades.size() % 5 + 1) + 1, '-');
        std::cout << std::endl << "|" << std::setw(21) << "|";
        for (int j = students[0].grades.size() % 5; j > 0; --j) {
            std::cout << std::setw(10 + std::min(static_cast<int>(students[0].grades[students[0].grades.size() - j].first.size()), 20) / 2) << truncateStr(students[0].grades[students[0].grades.size() - j].first, 20)
                << std::setw(11 - std::min(static_cast<int>(students[0].grades[students[0].grades.size() - j].first.size()), 20) / 2) << "|";
        }
        std::cout << std::endl << std::string(21 * (students[0].grades.size() % 5 + 1) + 1, '-') << std::endl;
        for (Student student : students) {
            std::cout << "|" << std::setw(10 + std::min(static_cast<int>(student.name.size()), 20) / 2) << truncateStr(student.name, 20)
                << std::setw(11 - std::min(static_cast<int>(student.name.size()), 20) / 2) << "|";
            for (int j = students[0].grades.size() % 5; j > 0; --j) {
                std::cout << std::setw(11) << std::fixed << std::setprecision(1) << Average(student.grades[student.grades.size() - j].second)
                    << std::setw(10) << "|";
            }
            std::cout << std::endl << std::string(21 * (students[0].grades.size() % 5 + 1) + 1, '-') << std::endl;
        }
    }
    std::cout << "Рейтинг студентов по успеваемости" << std::endl;
    std::map<double, std::vector<std::string>, std::greater<double>> average;
    StudentPerformanceRating(students, average);
    std::cout << std::string(64, '-') << std::endl;
    std::cout << "|" << std::setw(12) << "Место" << std::setw(9) << "|"
        << std::setw(13) << "Студент" << std::setw(8) << "|"
        << std::setw(16) << "Средний балл" << std::setw(5) << "|";
    std::cout << std::endl << std::string(64, '-') << std::endl;
    int cnt = 1;
    for (auto [key, value] : average) {
        for (int i = 0; i < value.size(); ++i) {
            std::cout << "|" << std::setw(10 + std::to_string(cnt).size() / 2) << cnt << std::setw(11 - std::to_string(cnt).size() / 2)
                << "|" << std::setw(10 + std::min(static_cast<int>(value[i].size()), 20) / 2) << truncateStr(value[i], 20)
                << std::setw(11 - std::min(static_cast<int>(value[i].size()), 20) / 2) << "|"
                << std::setw(11) << key << std::setw(10) << "|";
            std::cout << std::endl << std::string(64, '-') << std::endl;
        }
        ++cnt;
    }
    std::vector<std::pair<std::string, double>> problematic_subjects;
    ProblematicSubjects(students, problematic_subjects);
    if (problematic_subjects.size() > 0) {
        std::cout << "Проблемные предметы" << std::endl;
        std::cout << std::string(43, '-') << std::endl;
        std::cout << "|" << std::setw(13) << "Предмет" << std::setw(8) << "|"
            << std::setw(16) << "Средний балл" << std::setw(5) << "|";
        std::cout << std::endl << std::string(43, '-') << std::endl;
        for (auto [key, value] : problematic_subjects) {
            std::cout << "|" << std::setw(10 + std::min(static_cast<int>(key.size()), 20) / 2) << truncateStr(key, 20)
                << std::setw(11 - std::min(static_cast<int>(key.size()), 20) / 2) << "|"
                << std::setw(11) << value << std::setw(10) << "|";
            std::cout << std::endl << std::string(43, '-') << std::endl;
        }
    }
    else {
        std::cout << "Проблемных предметов нет" << std::endl;
    }
}

void SmartPerfomanceAnalyzer() {
    std::vector<Student> students;
    int issue_number;
    do
    {
        std::cout << std::endl
            << "== АНАЛИЗАТОР УСПЕВАЕМОСТИ ГРУППЫ ==" << std::endl;
        EnteringSchoolGradeLog(students);
        AnalysisOutput(students);
        do
        {
            students.resize(0);
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