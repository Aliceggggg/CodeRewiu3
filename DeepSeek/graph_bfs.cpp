#include "graph_bfs.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Конструктор графа
Graph::Graph(int size) : n(size) {
    // Инициализируем матрицу смежности нулями
    matrix.resize(n, vector<int>(n, 0));
}

// Добавление дуги
void Graph::addEdge(int from, int to, int weight) {
    if (from >= 0 && from < n && to >= 0 && to < n) {
        matrix[from][to] = weight;
    }
}

// Поиск в ширину (BFS)
vector<int> Graph::bfs(int startVertex) {
    // Проверка корректности начальной вершины
    if (startVertex < 0 || startVertex >= n) {
        return vector<int>();
    }

    // Массив посещённых вершин
    vector<bool> visited(n, false);

    // Очередь для BFS
    queue<int> q;

    // Вектор для хранения порядка обхода
    vector<int> traversalOrder;

    // Начинаем с начальной вершины
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        // Извлекаем вершину из очереди
        int current = q.front();
        q.pop();

        // Добавляем текущую вершину в порядок обхода
        traversalOrder.push_back(current);

        // Вектор для хранения соседей текущей вершины
        vector<int> neighbors;

        // Находим всех соседей (вершины, в которые есть дуги)
        for (int i = 0; i < n; i++) {
            if (matrix[current][i] != 0 && !visited[i]) {
                neighbors.push_back(i);
            }
        }

        // Сортируем соседей в порядке возрастания номеров
        // (согласно условию: если несколько равноправных вершин, 
        //  перечислять их в порядке возрастания)
        sort(neighbors.begin(), neighbors.end());

        // Добавляем соседей в очередь
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return traversalOrder;
}

// Загрузка графа из файла
Graph* Graph::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return nullptr;
    }

    // Читаем количество вершин
    int n;
    file >> n;

    if (n <= 0) {
        cout << "Ошибка: неверное количество вершин" << endl;
        file.close();
        return nullptr;
    }

    // Создаём граф
    Graph* graph = new Graph(n);

    // Читаем матрицу смежности
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            file >> weight;
            if (weight != 0) {
                graph->addEdge(i, j, weight);
            }
        }
    }

    file.close();
    return graph;
}

// Вывод матрицы смежности (для отладки)
void Graph::printMatrix() {
    cout << "\nМатрица смежности:" << endl;
    cout << "   ";
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}