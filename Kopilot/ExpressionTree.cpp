#include "ExpressionTree.h"
#include <cmath>
#include <iostream>

// Построение дерева из префиксной записи
Node* ExpressionTree::buildTree(std::stringstream& ss) {
    std::string token;
    ss >> token;

    // Если токен — оператор
    if (token == "+" || token == "-" || token == "*" ||
        token == "/" || token == "%" || token == "^") {

        int opCode = 0;

        if (token == "+") opCode = -1;
        if (token == "-") opCode = -2;
        if (token == "*") opCode = -3;
        if (token == "/") opCode = -4;
        if (token == "%") opCode = -5;
        if (token == "^") opCode = -6;

        Node* node = new Node(opCode);

        // Рекурсивно строим левое и правое поддерево
        node->left = buildTree(ss);
        node->right = buildTree(ss);

        return node;
    }

    // Иначе — это число
    return new Node(std::stoi(token));
}

// Вычисление операции
int ExpressionTree::evaluate(int op, int a, int b) {
    switch (op) {
    case -1: return a + b;
    case -2: return a - b;
    case -3: return a * b;
    case -4: return b == 0 ? 0 : a / b;
    case -5: return b == 0 ? 0 : a % b;
    case -6: return static_cast<int>(pow(a, b));
    }
    return 0;
}

// Упрощение дерева: вычисляем поддеревья, если результат ∈ [0;9]
Node* ExpressionTree::simplify(Node* root) {
    if (!root) return nullptr;

    // Лист — число
    if (root->value >= 0) return root;

    // Рекурсивно упрощаем поддеревья
    root->left = simplify(root->left);
    root->right = simplify(root->right);

    // Если оба поддерева — числа, можно вычислить
    if (root->left->value >= 0 && root->right->value >= 0) {
        int result = evaluate(root->value, root->left->value, root->right->value);

        // Если результат ∈ [0;9], заменяем поддерево одним узлом
        if (result >= 0 && result <= 9) {
            freeTree(root->left);
            freeTree(root->right);
            root->left = root->right = nullptr;
            root->value = result;
        }
    }

    return root;
}

// Освобождение памяти
void ExpressionTree::freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
