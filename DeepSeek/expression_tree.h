#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <string>
#include <vector>

using namespace std;

// Структура узла дерева
struct TreeNode {
    int value;              // Значение узла (число или код операции)
    TreeNode* left;         // Левый потомок
    TreeNode* right;        // Правый потомок

    // Конструктор для создания узла
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Коды операций
const int ADD = -1;        // сложение
const int SUB = -2;        // вычитание
const int MUL = -3;        // умножение
const int DIV = -4;        // деление нацело
const int MOD = -5;        // остаток от деления
const int POW = -6;        // возведение в степень

class ExpressionTree {
private:
    TreeNode* root;         // Корень дерева
    int position;           // Текущая позиция при разборе

    /**
     * @brief Рекурсивно строит дерево из вектора чисел
     * @param tokens Вектор с числами (операнды и коды операций)
     * @return Указатель на построенный узел
     */
    TreeNode* buildTree(const vector<int>& tokens);

    /**
     * @brief Вычисляет значение узла дерева
     * @param node Указатель на узел
     * @return Результат вычисления
     */
    int evaluate(TreeNode* node);

    /**
     * @brief Выполняет арифметическую операцию
     * @param op Код операции
     * @param left Левый операнд
     * @param right Правый операнд
     * @return Результат операции
     */
    int calculate(int op, int left, int right);

    /**
     * @brief Оптимизирует дерево, заменяя поддеревья со значениями 0-9 на листья
     * @param node Указатель на узел
     * @return Оптимизированный узел
     */
    TreeNode* optimize(TreeNode* node);

    /**
     * @brief Очищает дерево (освобождает память)
     * @param node Указатель на узел
     */
    void clear(TreeNode* node);

public:
    // Конструктор
    ExpressionTree();

    // Деструктор
    ~ExpressionTree();

    /**
     * @brief Строит дерево из префиксного выражения
     * @param expression Строка с выражением в префиксной форме
     */
    void buildFromPrefix(const string& expression);

    /**
     * @brief Вычисляет и оптимизирует дерево
     */
    void evaluateAndOptimize();

    /**
     * @brief Возвращает указатель на корень дерева
     * @return Указатель на корень
     */
    TreeNode* getRoot();

    /**
     * @brief Выводит дерево для отладки (инфиксная запись)
     * @param node Указатель на узел
     */
    void printInfix(TreeNode* node);
};

#endif