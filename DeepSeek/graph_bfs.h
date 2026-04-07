#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
private:
    int n;                          // Количество вершин
    vector<vector<int>> matrix;     // Матрица смежности

public:
    /**
     * @brief Конструктор графа
     * @param size Количество вершин
     */
    Graph(int size);

    /**
     * @brief Добавляет дугу между вершинами
     * @param from Начальная вершина
     * @param to Конечная вершина
     * @param weight Вес дуги
     */
    void addEdge(int from, int to, int weight);

    /**
     * @brief Выполняет поиск в ширину от заданной вершины
     * @param startVertex Начальная вершина (k)
     * @return Вектор вершин в порядке обхода
     */
    vector<int> bfs(int startVertex);

    /**
     * @brief Загружает граф из файла
     * @param filename Имя файла
     * @return Указатель на созданный граф или nullptr при ошибке
     */
    static Graph* loadFromFile(const string& filename);

    /**
     * @brief Выводит матрицу смежности (для отладки)
     */
    void printMatrix();
};

#endif