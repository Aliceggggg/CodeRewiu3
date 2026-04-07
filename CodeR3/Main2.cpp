//#include "word_shuffler.h"
//#include <iostream>
//
//int main() {
//    // Устанавливаем локаль для корректного отображения кириллицы в консоли
//    setlocale(LC_ALL, "Russian");
//
//    std::string input_word;
//
//    // Запрос ввода слова от пользователя
//    std::cout << "Введите слово: ";
//    std::cin >> input_word;
//
//    // Создаём объект класса WordShuffler с введённым словом
//    WordShuffler shuffler(input_word);
//
//    // Запускаем процесс перемешивания и получаем количество попыток
//    int attempts = shuffler.shuffleUntilMatch();
//
//    // Выводим итоговое количество попыток
//    std::cout << attempts << " попыток" << std::endl;
//
//    return 0;
//}
