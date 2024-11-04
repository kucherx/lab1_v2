#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Функція для зчитування графа з файлу
void readGraphFromFile(const std::string& filename, int& n, int& m, std::vector<std::pair<int, int>>& edges) {
    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    infile >> n >> m;  // Зчитуємо кількість вершин і ребер
    edges.resize(m);

    // Зчитуємо ребра графа
    for (int i = 0; i < m; ++i) {
        infile >> edges[i].first >> edges[i].second;
        edges[i].first--;  // Переходимо від індексації з 1 до індексації з 0
        edges[i].second--;
    }

    infile.close();
}

// Функція для створення матриці суміжності
std::vector<std::vector<int>> createAdjacencyMatrix(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n, 0));

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Якщо граф орієнтований, цей рядок можна прибрати
    }

    return adjMatrix;
}

// Функція для створення матриці інцидентності
std::vector<std::vector<int>> createIncidenceMatrix(int n, int m, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> incMatrix(n, std::vector<int>(m, 0));

    for (int j = 0; j < m; ++j) {
        int u = edges[j].first;
        int v = edges[j].second;
        incMatrix[u][j] = 1;
        incMatrix[v][j] = 1;  // Якщо граф орієнтований, можна змінити на `incMatrix[v][j] = -1`
    }

    return incMatrix;
}

// Функція для виведення матриці на екран
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Функція для запису матриці у файл
void writeMatrixToFile(const std::vector<std::vector<int>>& matrix, const std::string& filename) {
    std::ofstream outfile(filename);

    if (!outfile) {
        std::cerr << "Помилка відкриття файлу для запису!" << std::endl;
        return;
    }

    for (const auto& row : matrix) {
        for (int val : row) {
            outfile << val << " ";
        }
        outfile << std::endl;
    }

    outfile.close();
}

int main() {
    int n, m;
    std::vector<std::pair<int, int>> edges;

    std::string inputFile = "graph.txt";  // Введіть ім'я файлу з графом
    std::string adjacencyOutputFile = "adjacency_matrix.txt";
    std::string incidenceOutputFile = "incidence_matrix.txt";

    // Зчитування графа з файлу
    readGraphFromFile(inputFile, n, m, edges);

    // Створення матриці суміжності
    auto adjacencyMatrix = createAdjacencyMatrix(n, edges);

    // Створення матриці інцидентності
    auto incidenceMatrix = createIncidenceMatrix(n, m, edges);

    // Виведення матриць на екран
    std::cout << "Matrytsya sumiznosti:" << std::endl;
    printMatrix(adjacencyMatrix);

    std::cout << "\nMatrytsya identychnosti:" << std::endl;
    printMatrix(incidenceMatrix);

    // Запис матриць у файли
    writeMatrixToFile(adjacencyMatrix, adjacencyOutputFile);
    writeMatrixToFile(incidenceMatrix, incidenceOutputFile);

    return 0;
}
