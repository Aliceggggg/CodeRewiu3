#include "password_generator.h"
#include <iostream>

PasswordGenerator::PasswordGenerator() : gen(static_cast<unsigned int>(std::time(0))) {}

// Генерация пароля заданного уровня сложности
std::string PasswordGenerator::generatePassword(int level) {
    if (level < 0 || level >= levels.size()) {
        throw std::out_of_range("Неверный уровень сложности");
    }

    const ComplexityLevel& params = levels[level];
    std::string possible_chars;

    // Собираем все возможные символы для данного уровня
    if (params.use_lowercase) possible_chars += lowercase_chars;
    if (params.use_uppercase) possible_chars += uppercase_chars;
    if (params.use_digits) possible_chars += digit_chars;
    if (params.use_symbols) possible_chars += symbol_chars;

    std::string password;
    for (int i = 0; i < params.length; ++i) {
        // Случайным образом выбираем символ из доступных
        password += possible_chars[gen() % possible_chars.size()];
    }

    return password;
}

// Отображение меню выбора уровня сложности
void PasswordGenerator::displayMenu() {
    std::cout << "Выберите уровень сложности пароля:\n";
    std::cout << "1. Базовый (8 символов, строчные + цифры)\n";
    std::cout << "2. Средний (12 символов, строчные + заглавные + цифры)\n";
    std::cout << "3. Продвинутый (16 символов, все символы)\n";
}
