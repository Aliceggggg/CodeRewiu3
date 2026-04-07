//#include <iostream>
//#include <fstream>
//#include <string>
//#include "expression_tree.h"
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    string filename;
//
//    // Запрашиваем имя файла
//    cout << "Введите имя файла: ";
//    cin >> filename;
//
//    // Открываем файл
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cout << "Ошибка: не удалось открыть файл " << filename << endl;
//        return 1;
//    }
//
//    // Читаем выражение из файла
//    string expression;
//    getline(file, expression);
//    file.close();
//
//    cout << "Прочитано выражение: " << expression << endl;
//
//    // Создаём дерево выражений
//    ExpressionTree tree;
//
//    // Строим дерево из префиксного выражения
//    tree.buildFromPrefix(expression);
//
//    cout << "Дерево построено!" << endl;
//
//    // Выводим дерево в инфиксной форме (для наглядности)
//    cout << "Инфиксная запись: ";
//    tree.printInfix(tree.getRoot());
//    cout << endl;
//
//    // Вычисляем и оптимизируем дерево
//    tree.evaluateAndOptimize();
//
//    cout << "Дерево оптимизировано!" << endl;
//
//    // Выводим результат
//    cout << "Инфиксная запись после оптимизации: ";
//    tree.printInfix(tree.getRoot());
//    cout << endl;
//
//    // Выводим указатель на корень
//    cout << "\nРезультат:" << endl;
//    cout << "Указатель на корень дерева: " << tree.getRoot() << endl;
//
//    return 0;
//}