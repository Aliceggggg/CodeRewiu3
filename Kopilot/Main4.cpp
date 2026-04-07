#include <iostream>
#include "Graph.h"

int main() {
    setlocale(LC_ALL, "ru");
    Graph g;

    if (!g.loadFromFile("FileName1.txt")) {
        std::cout << "Ошибка: не удалось открыть файл\n";
        return 1;
    }

    int k;
    std::cout << "Введите стартовую вершину k: ";
    std::cin >> k;

    std::vector<int> result = g.bfs(k);

    std::cout << "Достижимые вершины в порядке BFS:\n";
    for (int v : result)
        std::cout << v << " ";

    std::cout << std::endl;

    return 0;
}
