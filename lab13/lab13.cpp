#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Graph {
private:
    int numVertices;               // Кількість вершин
    std::vector<std::vector<int>> adjList; // Список суміжності

public:
    // Конструктор
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Додати ребро
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Оскільки граф неорієнтований
    }

    // Розфарбування графа
    std::vector<int> colorGraph() {
        std::vector<int> result(numVertices, -1); // Кольори вершин (-1 означає, що не розфарбовано)
        result[0] = 0;                            // Першу вершину фарбуємо у колір 0

        std::vector<bool> availableColors(numVertices, true); // Доступні кольори

        for (int u = 1; u < numVertices; ++u) {
            // Помічаємо кольори сусідів як зайняті
            for (int neighbor : adjList[u]) {
                if (result[neighbor] != -1) {
                    availableColors[result[neighbor]] = false;
                }
            }

            // Знаходимо перший доступний колір
            int color = 0;
            while (color < numVertices && !availableColors[color]) {
                ++color;
            }
            result[u] = color; // Призначаємо колір

            // Скидаємо доступність кольорів
            for (int neighbor : adjList[u]) {
                if (result[neighbor] != -1) {
                    availableColors[result[neighbor]] = true;
                }
            }
        }
        return result;
    }

    // Вивід списку вершин із кольорами
    void printColors(const std::vector<int>& colors) {
        std::cout << "Vertex Colors:\n";
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i + 1 << " -> Color " << colors[i] << "\n";
        }
        std::cout << "Minimum number of colors: "
            << *std::max_element(colors.begin(), colors.end()) + 1 << "\n";
    }
};

int main() {
    // Зчитуємо граф із файлу
    std::ifstream inputFile("graph.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    int numVertices;
    inputFile >> numVertices;

    Graph graph(numVertices);

    int u, v;
    while (inputFile >> u >> v) {
        graph.addEdge(u - 1, v - 1); // Нумерація з 0
    }
    inputFile.close();

    // Розфарбовуємо граф
    std::vector<int> colors = graph.colorGraph();

    // Виводимо результат
    graph.printColors(colors);

    return 0;
}
