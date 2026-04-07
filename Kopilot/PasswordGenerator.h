#pragma once
#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>

// Класс для генерации паролей разных уровней сложности
class PasswordGenerator {
public:
    // Генерация пароля по уровню сложности (1, 2 или 3)
    static std::string generate(int level);

private:
    // Генерация строки случайных символов из переданного набора
    static std::string generateFromCharset(int length, const std::string& charset);
};

#endif
