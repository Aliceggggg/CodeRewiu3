#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <string>
#include <sstream>

// Узел дерева выражения
struct Node {
    int value;      // либо число 0–9, либо код операции (-1 ... -6)
    Node* left;     // левый потомок
    Node* right;    // правый потомок

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
public:
    // Построение дерева из префиксной записи
    Node* buildTree(std::stringstream& ss);

    // Преобразование дерева: вычисление поддеревьев
    Node* simplify(Node* root);

    // Вычисление значения операции
    int evaluate(int op, int a, int b);

    // Освобождение памяти
    void freeTree(Node* root);
};

#endif
