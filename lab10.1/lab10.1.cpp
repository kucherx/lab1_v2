#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Функція для зчитування графа з файлу та створення матриці ваг
vector<vector<int>> readGraphAndCreateWeightMatrix(const string& filename, int& n) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Pomylka vidkrytya failu!" << endl;
        exit(1);
    }

    int m;
    file >> n >> m;  // Зчитуємо кількість вершин і ребер

    // Ініціалізуємо матрицю ваг розміром n x n з нескінченними значеннями (наприклад, -1 для неіснуючих ребер)
    vector<vector<int>> weightMatrix(n, vector<int>(n, -1));

    // Зчитуємо ребра та заповнюємо матрицю ваг
    for (int i = 0; i < m; i++) {
        int v, u, w;
        file >> v >> u >> w;  // Зчитуємо початкову і кінцеву вершину та вагу ребра

        // Заповнюємо матрицю (припускаємо, що граф орієнтований)
        weightMatrix[v - 1][u - 1] = w;  // Використовуємо v-1 та u-1, бо індекси у матриці починаються з 0
    }

    file.close();
    return weightMatrix;
}

// Функція для виведення матриці ваг на екран та у файл
void printWeightMatrix(const vector<vector<int>>& weightMatrix, const string& outputFilename) {
    ofstream outFile(outputFilename);

    cout << "Matrytsia vag:\n";
    for (const auto& row : weightMatrix) {
        for (int weight : row) {
            if (weight == -1) {
                cout << setw(4) << "INF";  // Для неіснуючих ребер виводимо "∞"
                outFile << "INF ";
            }
            else {
                cout << setw(4) << weight;
                outFile << weight << " ";
            }
        }
        cout << endl;
        outFile << endl;
    }

    outFile.close();
}

int main() {
    string inputFilename = "input.txt";  // Назва вхідного файлу
    string outputFilename = "output.txt";  // Назва вихідного файлу для матриці ваг

    int n;  // Кількість вершин
    auto weightMatrix = readGraphAndCreateWeightMatrix(inputFilename, n);

    printWeightMatrix(weightMatrix, outputFilename);

    return 0;
}
