#ifndef WORD_SHUFFLER_H
#define WORD_SHUFFLER_H

#include <string>
#include <vector>

class WordShuffler {
public:
    // Запускает процесс случайных перестановок до совпадения
    static int shuffleUntilMatch(const std::string& word);

private:
    // Возвращает новую случайную перестановку слова
    static std::string randomShuffle(const std::string& word);
};

#endif
