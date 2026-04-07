#include "word_shuffler.h"
#include <iostream>
#include <algorithm>

// Конструктор класса: сохраняет исходное слово и инициализирует генератор
WordShuffler::WordShuffler(const std::string& word)
    : original_word(word), gen(static_cast<unsigned int>(rd())) {
}

// Функция перемешивания букв в слове
std::string WordShuffler::shuffleWord(const std::string& word) {
    std::string shuffled = word;  // Создаём копию слова для перемешивания

    // Используем std::shuffle для случайного перемешивания символов
    std::shuffle(shuffled.begin(), shuffled.end(), gen);

    return shuffled;
}

// Основной алгоритм: перемешивает слово до совпадения с оригиналом
int WordShuffler::shuffleUntilMatch() {
    int attempt_count = 0;  // Счётчик попыток (не включает исходное слово)
    std::string current_word = original_word;

    do {
        // Перемешиваем текущее слово
        current_word = shuffleWord(current_word);

        // Выводим перемешанное слово
        std::cout << current_word << std::endl;

        // Увеличиваем счётчик попыток
        attempt_count++;

        // Продолжаем, пока перемешанное слово не совпадет с исходным
    } while (current_word != original_word);

    return attempt_count;
}
