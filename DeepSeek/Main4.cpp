#include <iostream>
#include <string>
#include "graph_bfs.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    string filename;
    int k;

    // Ввод имени файла
    cout << "Введите имя файла: ";
    cin >> filename;

    // Загрузка графа из файла
    Graph* graph = Graph::loadFromFile(filename);

    if (graph == nullptr) {
        cout << "Ошибка при загрузке графа!" << endl;
        return 1;
    }

    // Вывод матрицы смежности (для наглядности)
    graph->printMatrix();

    // Ввод начальной вершины
    cout << "\nВведите номер начальной вершины (k): ";
    cin >> k;

    // Выполнение поиска в ширину
    vector<int> result = graph->bfs(k);

    // Вывод результата
    cout << "\nРезультат поиска в ширину от вершины " << k << ":" << endl;

    if (result.empty()) {
        cout << "Вершина " << k << " не существует в графе!" << endl;
    }
    else {
        cout << "Достижимые вершины в порядке обхода: ";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;

        cout << "\nВсего достижимых вершин: " << result.size() << endl;
    }

    // Очистка памяти
    delete graph;

    return 0;
}