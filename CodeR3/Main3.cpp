#include "tree_node.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    const std::string filename = "filename";  // Имя файла с выражением
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return 1;
    }

    std::string expression;
    inputFile >> expression;  // Читаем префиксное выражение из файла
    inputFile.close();

    if (expression.empty()) {
        std::cerr << "Ошибка: файл пуст" << std::endl;
        return 1;
    }

    // Создаём дерево из префиксного выражения
    ExpressionTree tree(expression);

    std::cout << "Исходное дерево:" << std::endl;
    tree.display();

    // Упрощаем дерево: вычисляем поддеревья с результатами 0–9
    tree.simplify();

    std::cout << "\nУпрощённое дерево:" << std::endl;
    tree.display();

    // Выводим указатель на корень полученного дерева
    std::cout << "\nУказатель на корень дерева: " << tree.getRoot() << std::endl;

    return 0;
}
