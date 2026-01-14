#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <fstream>

struct StudentData {
    std::string name;
    int age;
    std::vector<std::pair<std::string, double>> grades;
};

void AddStudent(std::vector<StudentData>& students) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ДОБАВЛЕНИЕ НОВОГО СТУДЕНТА =" << std::endl;
        std::string name;
        std::cout << "Введите имя студента:" << std::endl;
        std::getline(std::cin, name);
        int age = -1;
        while (age < 1) {
            std::cout << "Введите возраст студента:" << std::endl;
            std::cin >> age;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                age = -1;
            }
            if (age < 1) {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            }
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
        std::vector<std::pair<std::string, double>> grades;
        for (int i = 0; i < cnt_subjects; ++i) {
            std::string name_subject;
            bool check = true;
            do {
                check = true;
                std::cout << "Введите название предмета " << i + 1 << ":" << std::endl;
                std::getline(std::cin, name_subject);
                for (auto [first, second] : grades) {
                    if (first == name_subject) {
                        check = false;
                        std::cout << "ОШИБКА: Такой предмет уже существует" << std::endl;
                        break;
                    }
                }
            } while (!check);
            double average_grade = -1;
            while (average_grade < 2 || average_grade > 5) {
                std::cout << "Введите средний балл (от 2 до 5):" << std::endl;
                std::cin >> average_grade;
                std::cin.ignore(10000, '\n');
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    average_grade = -1;
                }
                if (average_grade < 2 || average_grade > 5) {
                    std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
                }
            }
            grades.push_back({ name_subject, round(average_grade * 10) / 10 });
        }
        students.push_back(StudentData(name, age, grades));
        do
        {
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

void ViewDatabase(std::vector<StudentData>& students) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ПРОСМОТР БАЗЫ ДАННЫХ =" << std::endl;
        if (students.size() == 0) {
            std::cout << "Данных нет" << std::endl;
        }
        else
        {
            for (StudentData student : students) {
                std::cout << std::endl << "Имя студента: " << student.name << std::endl;
                std::cout << "Возраст студента: " << student.age << std::endl;
                std::cout << "Предметы и средние баллы:" << std::endl;
                for (auto [name, average_grade] : student.grades) {
                    std::cout << name << " " << average_grade << std::endl;
                }
            }
        }
        do
        {
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

void StudentSearch(std::vector<StudentData>& students) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ПОИСК СТУДЕНТА =" << std::endl;
        std::string name;
        std::cout << "Введите имя студента:" << std::endl;
        std::getline(std::cin, name);
        std::vector<StudentData> found_students;
        for (StudentData student : students) {
            if (student.name == name) {
                found_students.push_back(student);
            }
        }
        if (found_students.size() == 0) {
            std::cout << "Студенты не найдены" << std::endl;
        }
        else
        {
            std::cout << "Найденные студенты:" << std::endl;
            for (StudentData student : found_students) {
                std::cout << std::endl << "Имя студента: " << student.name << std::endl;
                std::cout << "Возраст студента: " << student.age << std::endl;
                std::cout << "Предметы и средние баллы:" << std::endl;
                for (auto [name, average_grade] : student.grades) {
                    std::cout << name << " " << average_grade << std::endl;
                }
            }
        }
        do
        {
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

void ExportToFile(std::vector<StudentData>& students) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ЭКСПОРТ БАЗЫ ДАННЫХ В ФАЙЛ =" << std::endl;
        std::ofstream file;
        file.open("StudentDatabase.txt");
        if (file.is_open())
        {
            for (StudentData student : students) {
                file << "Имя студента: " << student.name << std::endl;
                file << "Возраст студента: " << student.age << std::endl;
                file << "Предметы и средние баллы:" << std::endl;
                for (auto [name, average_grade] : student.grades) {
                    file << name << " " << average_grade << std::endl;
                }
                file << std::endl;
            }
        }
        else {
            std::cout << "ОШИБКА: Не удалось открыть файл" << std::endl;
        }
        file.close();
        do
        {
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

void AgeStatistics(std::vector<StudentData>& students) {
    std::cout << std::endl << "Распределение студентов по возрастам" << std::endl << std::endl;
    std::map<int, std::vector<StudentData>> students_age;
    for (StudentData student : students) {
        students_age[student.age].push_back(student);
    }
    int cnt = 1;
    for (auto [key, value] : students_age) {
        std::cout << cnt << ". Возраст: " << key << std::endl;
        ++cnt;
        for (StudentData student : value) {
            std::cout << std::endl << "Имя студента: " << student.name << std::endl;
            std::cout << "Возраст студента: " << student.age << std::endl;
            std::cout << "Предметы и средние баллы:" << std::endl;
            for (auto [name, average_grade] : student.grades) {
                std::cout << name << " " << average_grade << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

double AverageGrade(StudentData& student) {
    double sum = 0;
    for (auto [name, average_grade] : student.grades) {
        sum += average_grade;
    }
    return round(sum / student.grades.size() * 10) / 10;
}

void GradeStatistics(std::vector<StudentData>& students) {
    std::cout << "Рейтинг студентов по среднему баллу" << std::endl << std::endl;
    std::map<double, std::vector<StudentData>, std::greater<double>> students_grades;
    for (StudentData student : students) {
        students_grades[AverageGrade(student)].push_back(student);
    }
    int cnt = 1;
    for (auto [key, value] : students_grades) {
        std::cout << cnt << ". Средний балл: " << key << std::endl;
        ++cnt;
        for (StudentData student : value) {
            std::cout << std::endl << "Имя студента: " << student.name << std::endl;
            std::cout << "Возраст студента: " << student.age << std::endl;
            std::cout << "Предметы и средние баллы:" << std::endl;
            for (auto [name, average_grade] : student.grades) {
                std::cout << name << " " << average_grade << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void StatisticsOutput(std::vector<StudentData>& students) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ВЫВОД СТАТИСТИКИ =" << std::endl;
        if (students.size() == 0) {
            std::cout << "Данных нет" << std::endl << std::endl;
        }
        else {
            AgeStatistics(students);
            GradeStatistics(students);
        }
        do
        {
            std::cout << "Задача завершена" << std::endl;
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

void StudentDatabase() {
    std::vector<StudentData> students;
    int issue_number;
    do
    {
        std::cout << std::endl
            << "== БАЗА ДАННЫХ СТУДЕНТОВ ==" << std::endl;
        std::cout << "1. Добавление нового студента" << std::endl;
        std::cout << "2. Просмотр базы данных" << std::endl;
        std::cout << "3. Поиск студента" << std::endl;
        std::cout << "4. Экспорт базы данных в файл" << std::endl;
        std::cout << "5. Вывод статистики" << std::endl;
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
            AddStudent(students);
        }
        else if (issue_number == 2)
        {
            ViewDatabase(students);
        }
        else if (issue_number == 3)
        {
            StudentSearch(students);
        }
        else if (issue_number == 4)
        {
            ExportToFile(students);
        }
        else if (issue_number == 5)
        {
            StatisticsOutput(students);
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    } while (issue_number != 0);
}