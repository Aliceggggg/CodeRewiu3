#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>
#include <vector>
#include <random>
#include <ctime>

// Структура для хранения параметров уровня сложности
struct ComplexityLevel {
    int length;           // Длина пароля
    bool use_lowercase;   // Использовать строчные буквы
    bool use_uppercase;   // Использовать заглавные буквы
    bool use_digits;      // Использовать цифры
    bool use_symbols;     // Использовать специальные символы
};

// Класс генератора паролей
class PasswordGenerator {
private:
    std::string lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digit_chars = "0123456789";
    std::string symbol_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    std::random_device rd;
    std::mt19937 gen;

    // Массив доступных уровней сложности
    std::vector<ComplexityLevel> levels = {
        {8, true, false, true, false},    // Базовый
        {12, true, true, true, false},    // Средний
        {16, true, true, true, true}      // Продвинутый
    };

public:
    PasswordGenerator();
    std::string generatePassword(int level);
    void displayMenu();
};

#endif // PASSWORD_GENERATOR_H
