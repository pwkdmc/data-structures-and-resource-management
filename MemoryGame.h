#pragma once

// Генерация карт
void MixCards(std::vector<std::vector<std::pair<int, bool>>>& field);

// Вывод поля
void InputField(std::vector<std::vector<std::pair<int, bool>>>& field);

// Обработка хода игры
void Game();

// Интерактивный цикл для игры на память
void MemoryGame();