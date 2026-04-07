#include "WordShuffler.h"
#include <random>
#include <algorithm>
#include <iostream>

// Генерация случайной перестановки слова
std::string WordShuffler::randomShuffle(const std::string& word) {
    setlocale(LC_ALL, "ru");
    std::string shuffled = word;

    // Настраиваем генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // std::shuffle перемешивает символы случайным образом
    std::shuffle(shuffled.begin(), shuffled.end(), gen);

    return shuffled;
}

// Основной цикл перестановок до совпадения
int WordShuffler::shuffleUntilMatch(const std::string& word) {
    setlocale(LC_ALL, "ru");
    int attempts = 0;

    while (true) {
        std::string shuffled = randomShuffle(word);

        // Выводим каждую перестановку
        std::cout << shuffled << std::endl;

        attempts++;

        // Проверяем совпадение
        if (shuffled == word) {
            return attempts; // Возвращаем количество попыток
        }
    }
}