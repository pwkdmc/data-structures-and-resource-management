#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>

struct Book {
	std::string author;
    std::string name;
	int year;
	std::string genre;
	bool is_available;
};

void AddBook(std::vector<Book>& books) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ДОБАВЛЕНИЕ НОВОЙ КНИГИ =" << std::endl;
        std::string author;
        std::cout << "Введите автора:" << std::endl;
        std::getline(std::cin, author);
        std::string name;
        std::cout << "Введите название:" << std::endl;
        std::getline(std::cin, name);
        int year = -1;
        while (year < 1) {
            std::cout << "Введите год издания:" << std::endl;
            std::cin >> year;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                year = -1;
            }
            if (year < 1) {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            }
        }
        std::string genre;
        std::cout << "Введите жанр:" << std::endl;
        std::getline(std::cin, genre);
        int available = -1;
        while (available != 0 && available != 1) {
            std::cout << "Введите статус доступности (0 - не доступна, 1 - доступна):" << std::endl;
            std::cin >> available;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                available = -1;
            }
            if (available != 0 && available != 1) {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            }
        }
        books.push_back(Book(author, name, year, genre, (available == 0 ? false : true)));
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

void NameSearch(std::vector<Book>& books) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ПОИСК ПО НАЗВАНИЮ =" << std::endl;
        std::string name;
        std::cout << "Введите название:" << std::endl;
        std::getline(std::cin, name);
        std::vector<Book> found_books;
        for (Book book : books) {
            if (book.name == name) {
                found_books.push_back(book);
            }
        }
        if (found_books.size() == 0) {
            std::cout << "Книги не найдены" << std::endl;
        }
        else
        {
            std::cout << "Найденные книги:" << std::endl;
            for (Book book : found_books) {
                std::cout << book.author << " \"" << book.name << "\" " << book.year << " " << book.genre << " " << (book.is_available ? "+" : "-") << std::endl;
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

void AuthorSearch(std::vector<Book>& books) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ПОИСК ПО АВТОРУ =" << std::endl;
        std::string author;
        std::cout << "Введите автора:" << std::endl;
        std::getline(std::cin, author);
        std::vector<Book> found_books;
        for (Book book : books) {
            if (book.author == author) {
                found_books.push_back(book);
            }
        }
        if (found_books.size() == 0) {
            std::cout << "Книги не найдены" << std::endl;
        }
        else
        {
            std::cout << "Найденные книги:" << std::endl;
            for (Book book : found_books) {
                std::cout << book.author << " \"" << book.name << "\" " << book.year << " " << book.genre << " " << (book.is_available ? "+" : "-") << std::endl;
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

void GenreSearch(std::vector<Book>& books) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ПОИСК ПО ЖАНРУ =" << std::endl;
        std::string genre;
        std::cout << "Введите жанр:" << std::endl;
        std::getline(std::cin, genre);
        std::vector<Book> found_books;
        for (Book book : books) {
            if (book.genre == genre) {
                found_books.push_back(book);
            }
        }
        if (found_books.size() == 0) {
            std::cout << "Книги не найдены" << std::endl;
        }
        else
        {
            std::cout << "Найденные книги:" << std::endl;
            for (Book book : found_books) {
                std::cout << book.author << " \"" << book.name << "\" " << book.year << " " << book.genre << " " << (book.is_available ? "+" : "-") << std::endl;
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

void GenreStatistics(std::vector<Book>& books) {
    std::cout << std::endl << "Распределение книг по жанрам" << std::endl << std::endl;
    std::map<std::string, std::vector<Book>> books_genre;
    for (Book book : books) {
        books_genre[book.genre].push_back(book);
    }
    for (auto [key, value] : books_genre) {
        std::cout << key << std::endl;
        for (Book book : value) {
            std::cout << book.author << " \"" << book.name << "\" " << book.year << " " << book.genre << " " << (book.is_available ? "+" : "-") << std::endl;
        }
        std::cout << std::endl;
    }
}

void YearStatistics(std::vector<Book>& books) {
    std::cout << std::endl << "Распределение книг по годам" << std::endl << std::endl;
    std::map<int, std::vector<Book>> books_year;
    for (Book book : books) {
        books_year[book.year].push_back(book);
    }
    for (auto [key, value] : books_year) {
        std::cout << key << std::endl;
        for (Book book : value) {
            std::cout << book.author << " \"" << book.name << "\" " << book.year << " " << book.genre << " " << (book.is_available ? "+" : "-") << std::endl;
        }
        std::cout << std::endl;
    }
}

void AvailableStatistics(std::vector<Book>& books) {
    std::cout << std::endl << "Распределение книг по доступности" << std::endl << std::endl;
    std::map<bool, std::vector<Book>> books_available;
    for (Book book : books) {
        books_available[book.is_available].push_back(book);
    }
    for (auto [key, value] : books_available) {
        std::cout << (key ? "Доступные книги" : "Недоступные книги") << std::endl;
        for (Book book : value) {
            std::cout << book.author << " \"" << book.name << "\" " << book.year << " " << book.genre << " " << (book.is_available ? "+" : "-") << std::endl;
        }
        std::cout << std::endl;
    }
}

void StatisticsOutput(std::vector<Book>& books) {
    int issue_number;
    do
    {
        std::cout << std::endl
            << "= ВЫВОД СТАТИСТИКИ =" << std::endl;
        if (books.size() == 0) {
            std::cout << "Данных нет" << std::endl << std::endl;
        }
        else {
            GenreStatistics(books);
            YearStatistics(books);
            AvailableStatistics(books);
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

void LibraryManagementSystem() {
    std::vector<Book> books = {
        Book("Чехов Антон", "Дама с собачкой", 1899, "Рассказ", true),
        Book("Ремарк Эрих Мария", "Триумфальная арка", 1945, "Роман", false),
        Book("Дойл Артур Конан", "Этюд в багровых тонах", 1887, "Детектив", true),
        Book("Чехов Антон", "Враги", 1887, "Рассказ", true),
        Book("Робертс Нора", "Яд бессмертия", 1996, "Детектив", false)
    };
    int issue_number;
    do
    {
        std::cout << std::endl
            << "== СИСТЕМА УПРАВЛЕНИЯ БИБЛИОТЕКОЙ ==" << std::endl;
        std::cout << "1. Добавление новой книги" << std::endl;
        std::cout << "2. Поиск по названию" << std::endl;
        std::cout << "3. Поиск по автору" << std::endl;
        std::cout << "4. Поиск по жанру" << std::endl;
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
            AddBook(books);
        }
        else if (issue_number == 2)
        {
            NameSearch(books);
        }
        else if (issue_number == 3)
        {
            AuthorSearch(books);
        }
        else if (issue_number == 4)
        {
            GenreSearch(books);
        }
        else if (issue_number == 5)
        {
            StatisticsOutput(books);
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
        }
    } while (issue_number != 0);
}