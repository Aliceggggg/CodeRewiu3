#include "PasswordGenerator.h"
#include <random>

// Генерация случайной строки из набора символов
std::string PasswordGenerator::generateFromCharset(int length, const std::string& charset) {
    std::random_device rd;                 // Источник случайности
    std::mt19937 gen(rd());                // Генератор псевдослучайных чисел
    std::uniform_int_distribution<> dist(0, charset.size() - 1);

    std::string result;
    result.reserve(length);

    for (int i = 0; i < length; i++) {
        result += charset[dist(gen)];      // Добавляем случайный символ
    }

    return result;
}

// Основной метод генерации пароля по уровню сложности
std::string PasswordGenerator::generate(int level) {
    // Наборы символов
    const std::string lower = "abcdefghijklmnopqrstuvwxyz";
    const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string symbols = "!@#$%^&*()-_=+[]{};:,.<>/?";

    switch (level) {
    case 1: {
        // Лёгкий пароль: только буквы, длина 6
        return generateFromCharset(6, lower + upper);
    }
    case 2: {
        // Средний пароль: буквы + цифры, длина 10
        return generateFromCharset(10, lower + upper + digits);
    }
    case 3: {
        // Сложный пароль: буквы + цифры + символы, длина 16
        return generateFromCharset(16, lower + upper + digits + symbols);
    }
    default:
        return "Ошибка: неверный уровень сложности.";
    }
}
