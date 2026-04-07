#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <string>

// Узел дерева: может быть операндом (число 0–9) или операцией (кодируется отрицательными числами)
struct TreeNode {
    int value;           // Значение узла: число или код операции
    TreeNode* left;      // Левый потомок (для бинарных операций)
    TreeNode* right;     // Правый потомок (для бинарных операций)

    // Конструктор узла
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Класс для работы с деревом выражений
class ExpressionTree {
private:
    TreeNode* root;  // Корень дерева

    // Вспомогательные функции
    TreeNode* buildFromPrefix(const std::string& expression, int& index);
    int evaluateSubtree(TreeNode* node);
    void simplifyTree(TreeNode*& node);
    void printTree(TreeNode* node, int depth = 0);
    void deleteTree(TreeNode* node);

public:
    // Конструктор: строит дерево из префиксного выражения
    ExpressionTree(const std::string& prefixExpression);

    // Деструктор: освобождает память
    ~ExpressionTree();

    // Преобразует дерево, вычисляя поддеревья с результатом 0–9
    void simplify();

    // Выводит дерево (для отладки)
    void display();

    // Возвращает указатель на корень дерева
    TreeNode* getRoot() const { return root; }
};

#endif // TREE_NODE_H
