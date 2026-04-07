#include "password_generator.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cctype>

using namespace std;

// Функция для генерации случайного числа
int randomInt(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(0));
        first = false;
    }
    return min + rand() % (max - min + 1);
}

// Генерация пароля
string generatePassword(int level) {
    string chars;  // набор символов для пароля
    int length;    // длина пароля

    // Настройка уровня сложности
    if (level == 1) {
        // Лёгкий: только строчные буквы, 8 символов
        chars = "abcdefghijklmnopqrstuvwxyz";
        length = 8;
    }
    else if (level == 2) {
        // Средний: строчные + заглавные + цифры, 12 символов
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        length = 12;
    }
    else {
        // Сложный: строчные + заглавные + цифры + символы, 16 символов
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
        length = 16;
    }

    // Генерация пароля
    string password = "";
    for (int i = 0; i < length; i++) {
        int index = randomInt(0, chars.length() - 1);
        password += chars[index];
    }

    return password;
}