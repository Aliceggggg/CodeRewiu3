#include "word_shuffler.h"
#include <cstdlib>  // для функций rand() и srand()
#include <ctime>    // для функции time()
#include <algorithm> // для функции swap()

using namespace std;

/**
 * @brief Генерирует случайное число в заданном диапазоне
 * @param min Минимальное значение
 * @param max Максимальное значение
 * @return Случайное целое число
 */
int getRandomNumber(int min, int max) {
    // rand() % (max - min + 1) даёт число от 0 до (max-min)
    // прибавляем min и получаем число от min до max
    return min + rand() % (max - min + 1);
}

/**
 * @brief Перемешивает буквы в слове случайным образом
 * @param word Исходное слово для перемешивания
 * @return Новое слово с переставленными буквами
 */
string shuffleWord(string word) {
    int length = word.length();  // получаем длину слова

    // Перебираем каждую позицию в слове
    for (int i = 0; i < length; i++) {
        // Выбираем случайную позицию от i до конца слова
        int randomPos = getRandomNumber(i, length - 1);

        // Меняем местами буквы на позициях i и randomPos
        // Используем встроенную функцию swap для обмена значениями
        swap(word[i], word[randomPos]);
    }

    return word;  // возвращаем перемешанное слово
}

/**
 * @brief Проверяет, совпадают ли два слова
 * @param word1 Первое слово
 * @param word2 Второе слово
 * @return true если слова одинаковые, false если разные
 */
bool isWordsEqual(string word1, string word2) {
    // Просто сравниваем строки
    return word1 == word2;
}