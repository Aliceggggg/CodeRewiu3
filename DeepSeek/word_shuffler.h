#ifndef WORD_SHUFFLER_H
#define WORD_SHUFFLER_H

#include <string>

using namespace std;

/**
 * @brief Перемешивает буквы в слове случайным образом
 * @param word Исходное слово для перемешивания
 * @return Новое слово с переставленными буквами
 */
string shuffleWord(string word);

/**
 * @brief Проверяет, совпадают ли два слова
 * @param word1 Первое слово
 * @param word2 Второе слово
 * @return true если слова одинаковые, false если разные
 */
bool isWordsEqual(string word1, string word2);

#endif