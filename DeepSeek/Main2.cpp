//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//#include "word_shuffler.h"
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    // Инициализируем генератор случайных чисел
//    // time(0) возвращает текущее время в секундах
//    // Благодаря этому при каждом запуске будут получаться разные случайные числа
//    srand(time(0));
//
//    string originalWord;  // исходное слово, которое введёт пользователь
//    string shuffledWord;   // перемешанное слово
//    int attempts = 0;      // счётчик попыток (количество выведенных слов)
//
//    // Запрашиваем у пользователя слово
//    cout << "Введите слово: ";
//    cin >> originalWord;
//
//    // Сохраняем исходное слово в переменную для перемешивания
//    shuffledWord = originalWord;
//
//    // Цикл продолжается, пока перемешанное слово не совпадёт с исходным
//    do {
//        // Перемешиваем слово случайным образом
//        shuffledWord = shuffleWord(shuffledWord);
//
//        // Выводим полученное слово на экран
//        cout << shuffledWord << endl;
//
//        // Увеличиваем счётчик попыток
//        attempts++;
//
//    } while (!isWordsEqual(shuffledWord, originalWord));  // проверяем совпадение с исходным словом
//
//    // Выводим количество попыток
//    cout << attempts << " попыток" << endl;
//
//    return 0;
//}