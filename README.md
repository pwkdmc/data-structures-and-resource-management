# Data Management & Analysis Tools 📊
A collection of five interactive C++ console applications for data management, statistical analysis, text processing, and a classic memory matching game. Features structured data containers, formatted table output, file export, and algorithmic problem-solving.
## 🌟 Overview
This project demonstrates practical data management with structures, vectors, maps, and sets. Applications showcase formatted console output with dynamic table generation, multi-key data grouping for statistics, Caesar cipher encryption with comprehensive text analytics, and a coordinate-based memory card game.
## 🧩 Applications
### 📈 Smart Performance Analyzer
A group academic performance analysis tool with rich formatted output:
- **Batch data entry** - input student names, subjects, and grades (2–5 scale)
- **Subject average table** - dynamically formatted grid with 5 subjects per row, auto-adjusting column widths
- **Student ranking** - sorted by overall GPA using `std::map<double, vector, greater<double>>`
- **Problematic subjects** - flags subjects with average below 3.5
- **Name truncation** - long names/subjects automatically shortened to fit table cells with proper centering
### 🔐 Text Cipher & Analyzer
Caesar cipher encryption combined with comprehensive text statistics:
- **Multi-alphabet cipher** - supports Latin (A–Z, a–z) and Cyrillic (А–Я, а–я) character sets
- **Character frequency** - counts every unique character in the text
- **Word statistics** - case-insensitive word counting with punctuation stripping, palindrome detection
- **Sentence statistics** - groups and counts identical sentences (ending with `.`, `!`, `?`)
- **Digit frequency** - counts occurrences of each digit 0–9
### 🎓 Student Database
An in-memory student record management system:
- **Add students** - name, age, and multiple subjects with average grades (2.0–5.0)
- **Duplicate subject prevention** - validates unique subject names per student
- **View all records** - formatted display of complete database
- **Name search** - exact-match lookup across all students
- **Export to file** - saves database to `StudentDatabase.txt` in readable format
- **Statistics** - two grouping views:
  - Age distribution - students grouped by age
  - Grade ranking - students sorted by overall GPA (descending)
### 📚 Library Management System
A book catalog with multi-criteria search and statistical grouping:
- **Pre-loaded collection** - 5 classic books (Chekhov, Remarque, Doyle, Roberts)
- **Add books** - author, title, year, genre, availability status
- **Three search modes** - by title, author, or genre (exact match)
- **Statistical views** - books grouped by:
  - Genre distribution
  - Publication year
  - Availability status (available vs. unavailable)
- Display format: `Author "Title" Year Genre +/-`
### 🧠 Memory Card Game
A classic concentration/matching pairs game on a 4×6 grid:
- **Dynamic card generation** - 12 pairs (numbers 1–12) randomly shuffled using reservoir sampling
- **Coordinate input** - two-digit numbers representing row+column (11–46)
- **Input validation** - checks bounds, already-revealed cards, and duplicate selections
- **Score tracking** - increments on match attempt, decrements on mismatch (max 12 = complete)
- **Visual grid** - ASCII table with row/column headers, hidden cards shown as blanks, revealed cards display their number
- **Turn reveal** - shows mismatched pair briefly before hiding again
## 🎯 Shared Features
- **Structured data** - all applications use `struct` types with meaningful field names
- **STL containers** - `vector`, `map`, `set` for storage, grouping, and sorting
- **Robust input validation** - type checking, range validation, duplicate prevention
- **Task-repeat workflow** - nested "Run again / Exit" loops after each sub-operation
- **Russian language UI** - all prompts and messages in Russian
- **Zero-based exit** - `0` consistently exits to parent menu
- **Structured bindings** - C++17 `auto [key, value]` for map/set iteration
## 📄 License
The project is intended for educational purposes. It can be used and modified freely.