#ifndef WORD_SHUFFLER_H
#define WORD_SHUFFLER_H

#include <string>
#include <random>

// Класс для перемешивания букв в слове
class WordShuffler {
private:
    std::string original_word;  // Исходное слово
    std::random_device rd;       // Устройство для получения случайных данных
    std::mt19937 gen;          // Генератор случайных чисел (Mersenne Twister)

public:
    // Конструктор: принимает исходное слово и инициализирует генератор случайных чисел
    WordShuffler(const std::string& word);

    // Перемешивает буквы в слове случайным образом
    std::string shuffleWord(const std::string& word);

    // Запускает процесс перемешивания до совпадения с исходным словом
    int shuffleUntilMatch();
};

#endif // WORD_SHUFFLER_H
