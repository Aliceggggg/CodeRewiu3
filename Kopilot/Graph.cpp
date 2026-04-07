#include "Graph.h"
#include <fstream>
#include <queue>
#include <algorithm>

// Загрузка графа из файла
bool Graph::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    file >> n;

    m.assign(n, std::vector<int>(n));

    // Считываем матрицу смежности
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            file >> m[i][j];

    return true;
}

// BFS от вершины k
std::vector<int> Graph::bfs(int k) {
    std::vector<int> visited(n, 0);   // массив посещений
    std::queue<int> q;                // очередь BFS
    std::vector<int> order;           // порядок обхода

    k--; // переводим в индексацию 0..n-1

    visited[k] = 1;
    q.push(k);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        order.push_back(v + 1); // сохраняем номер вершины (обратно в 1..n)

        // Перебираем соседей в порядке возрастания номеров
        for (int j = 0; j < n; j++) {
            if (m[v][j] != 0 && !visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }

    return order;
}
