#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>

using namespace std;

// Функция для генерации случайного числа
int randomInt(int min, int max);

// Генерация пароля
string generatePassword(int level);

#endif