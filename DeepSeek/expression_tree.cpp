#include "expression_tree.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Конструктор
ExpressionTree::ExpressionTree() : root(nullptr), position(0) {}

// Деструктор
ExpressionTree::~ExpressionTree() {
    clear(root);
}

// Очистка дерева
void ExpressionTree::clear(TreeNode* node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

// Рекурсивное построение дерева
TreeNode* ExpressionTree::buildTree(const vector<int>& tokens) {
    if (position >= tokens.size()) return nullptr;

    int current = tokens[position];
    position++;

    // Создаём узел с текущим значением
    TreeNode* node = new TreeNode(current);

    // Если это операция (отрицательное число), то у неё есть потомки
    if (current < 0) {
        node->left = buildTree(tokens);
        node->right = buildTree(tokens);
    }
    // Если это число (0-9), то это лист, потомков нет

    return node;
}

// Выполнение арифметической операции
int ExpressionTree::calculate(int op, int left, int right) {
    switch (op) {
    case ADD:  // сложение
        return left + right;
    case SUB:  // вычитание
        return left - right;
    case MUL:  // умножение
        return left * right;
    case DIV:  // деление нацело
        if (right != 0) return left / right;
        else return 0;  // защита от деления на ноль
    case MOD:  // остаток от деления
        if (right != 0) return left % right;
        else return 0;  // защита от деления на ноль
    case POW:  // возведение в степень
        return (int)pow(left, right);
    default:
        return 0;
    }
}

// Вычисление значения узла
int ExpressionTree::evaluate(TreeNode* node) {
    if (node == nullptr) return 0;

    // Если это лист (число от 0 до 9), возвращаем его значение
    if (node->value >= 0 && node->value <= 9) {
        return node->value;
    }

    // Если это операция, вычисляем потомков
    int leftVal = evaluate(node->left);
    int rightVal = evaluate(node->right);

    // Вычисляем результат операции
    return calculate(node->value, leftVal, rightVal);
}

// Оптимизация дерева
TreeNode* ExpressionTree::optimize(TreeNode* node) {
    if (node == nullptr) return nullptr;

    // Сначала оптимизируем потомков
    node->left = optimize(node->left);
    node->right = optimize(node->right);

    // Если это лист (число), возвращаем как есть
    if (node->value >= 0 && node->value <= 9) {
        return node;
    }

    // Если это операция, вычисляем её значение
    int result = evaluate(node);

    // Если результат в диапазоне 0-9, заменяем поддерево на лист
    if (result >= 0 && result <= 9) {
        delete node->left;   // удаляем левое поддерево
        delete node->right;  // удаляем правое поддерево
        node->left = nullptr;
        node->right = nullptr;
        node->value = result;  // заменяем операцию на число
    }

    return node;
}

// Построение дерева из строки выражения
void ExpressionTree::buildFromPrefix(const string& expression) {
    // Очищаем существующее дерево
    clear(root);
    root = nullptr;
    position = 0;

    // Разбиваем строку на токены
    vector<int> tokens;
    stringstream ss(expression);
    int num;

    while (ss >> num) {
        tokens.push_back(num);
    }

    // Строим дерево
    root = buildTree(tokens);
}

// Вычисление и оптимизация
void ExpressionTree::evaluateAndOptimize() {
    root = optimize(root);
}

// Получение корня
TreeNode* ExpressionTree::getRoot() {
    return root;
}

// Вывод дерева в инфиксной форме (для отладки)
void ExpressionTree::printInfix(TreeNode* node) {
    if (node == nullptr) return;

    // Если это число, просто выводим его
    if (node->value >= 0 && node->value <= 9) {
        cout << node->value;
        return;
    }

    // Если это операция, выводим в скобках
    cout << "(";
    printInfix(node->left);

    // Выводим знак операции
    switch (node->value) {
    case ADD: cout << " + "; break;
    case SUB: cout << " - "; break;
    case MUL: cout << " * "; break;
    case DIV: cout << " / "; break;
    case MOD: cout << " % "; break;
    case POW: cout << " ^ "; break;
    }

    printInfix(node->right);
    cout << ")";
}