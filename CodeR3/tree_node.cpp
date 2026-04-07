#include "tree_node.h"
#include <iostream>
#include <cctype>
#include <cmath>
#include <string>

// Константы для кодирования операций
const int ADD = -1;
const int SUB = -2;
const int MUL = -3;
const int DIV = -4;
const int MOD = -5;
const int POW = -6;

// Вспомогательная функция: проверяет, является ли символ операцией
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Вспомогательная функция: преобразует символ операции в код
int operatorToCode(char op) {
    switch (op) {
    case '+': return ADD;
    case '-': return SUB;
    case '*': return MUL;
    case '/': return DIV;
    case '%': return MOD;
    case '^': return POW;
    default: return 0;
    }
}

// Рекурсивно строит дерево из префиксной записи
TreeNode* ExpressionTree::buildFromPrefix(const std::string& expression, int& index) {
    if (index >= static_cast<int>(expression.size())) return nullptr;

    char current = expression[index++];

    if (isOperator(current)) {
        // Если текущий символ — операция, создаём узел с кодом операции
        TreeNode* node = new TreeNode(operatorToCode(current));
        // Рекурсивно строим левое и правое поддеревья
        node->left = buildFromPrefix(expression, index);
        node->right = buildFromPrefix(expression, index);
        return node;
    }
    else if (std::isdigit(static_cast<unsigned char>(current))) {
        // Если текущий символ — цифра, создаём узел с её значением
        return new TreeNode(current - '0');  // Преобразуем символ в число
    }
    return nullptr;
}

// Конструктор: читает выражение из строки и строит дерево
ExpressionTree::ExpressionTree(const std::string& prefixExpression) {
    int index = 0;
    root = buildFromPrefix(prefixExpression, index);
}

// Деструктор: освобождает память, занятую деревом
ExpressionTree::~ExpressionTree() {
    deleteTree(root);
}

void ExpressionTree::deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Вычисляет значение поддерева
int ExpressionTree::evaluateSubtree(TreeNode* node) {
    if (!node) return 0;

    // Если узел — операнд, возвращаем его значение
    if (node->value >= 0 && node->value <= 9) {
        return node->value;
    }

    // Рекурсивно вычисляем значения левого и правого поддеревьев
    int leftVal = evaluateSubtree(node->left);
    int rightVal = evaluateSubtree(node->right);

    // Выполняем операцию в зависимости от кода
    switch (node->value) {
    case ADD: return leftVal + rightVal;
    case SUB: return leftVal - rightVal;
    case MUL: return leftVal * rightVal;
    case DIV: return rightVal != 0 ? leftVal / rightVal : 0;
    case MOD: return rightVal != 0 ? leftVal % rightVal : 0;
    case POW: return static_cast<int>(std::pow(leftVal, rightVal));
    default: return 0;
    }
}

// Преобразует дерево: заменяет поддеревья их значениями, если результат в диапазоне 0–9
void ExpressionTree::simplifyTree(TreeNode*& node) {
    if (!node) return;

    // Рекурсивно упрощаем левое и правое поддеревья
    simplifyTree(node->left);
    simplifyTree(node->right);

    // Если узел — операция и оба его потомка — числа
    if (node->value < 0 && node->left && node->right) {
        int result = evaluateSubtree(node);
        // Если результат в диапазоне 0–9, заменяем поддерево узлом с этим значением
        if (result >= 0 && result <= 9) {
            delete node->left;
            delete node->right;
            node->left = nullptr;
            node->right = nullptr;
            node->value = result;
        }
    }
}

// Публичный метод: запускает упрощение дерева
void ExpressionTree::simplify() {
    simplifyTree(root);
}

// Выводит дерево в отладочном формате (с отступами по глубине)
void ExpressionTree::printTree(TreeNode* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << node->value << std::endl;
    printTree(node->left, depth + 1);
    printTree(node->right, depth + 1);
}

// Публичный метод: выводит всё дерево
void ExpressionTree::display() {
    printTree(root, 0);
}
