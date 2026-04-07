#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    int n;                              // количество вершин
    std::vector<std::vector<int>> m;    // матрица смежности

public:
    // Загрузка графа из файла
    bool loadFromFile(const std::string& filename);

    // BFS от вершины k (нумерация с 1)
    std::vector<int> bfs(int k);
};

#endif
