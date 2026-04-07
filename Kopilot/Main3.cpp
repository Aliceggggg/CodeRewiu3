//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include "ExpressionTree.h"
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    std::ifstream file("filename.txt");
//
//    if (!file.is_open()) {
//        std::cout << "Не удалось открыть файл\n";
//        return 1;
//    }
//
//    // Считываем всё выражение в строку
//    std::string expr;
//    std::getline(file, expr);
//
//    std::stringstream ss(expr);
//
//    ExpressionTree tree;
//
//    // Строим дерево
//    Node* root = tree.buildTree(ss);
//
//    // Упрощаем дерево
//    root = tree.simplify(root);
//
//    // Выводим указатель на корень
//    std::cout << "Корень дерева: " << root << std::endl;
//    std::cout << "Значение корня: " << root->value << std::endl;
//
//    // Освобождаем память
//    tree.freeTree(root);
//
//    return 0;
//}
