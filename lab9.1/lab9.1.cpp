#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Функція для зчитування графа з файлу
unordered_map<int, vector<int>> readGraphFromFile(const string& filename) {
    unordered_map<int, vector<int>> graph;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Pomylka vidkrytya failu!" << endl;
        return graph;
    }

    int vertex, neighbor;
    while (file >> vertex >> neighbor) {
        graph[vertex].push_back(neighbor);
        graph[neighbor].push_back(vertex); // Якщо граф ненаправлений
    }

    file.close();
    return graph;
}

// Структура для зберігання результату обходу
struct BFSResult {
    int vertex;
    int bfsNumber;
    vector<int> queueContents;
};

// Функція для BFS з поверненням протоколу обходу
vector<BFSResult> breadthFirstSearch(const unordered_map<int, vector<int>>& graph, int startVertex) {
    unordered_map<int, bool> visited;
    queue<int> bfsQueue;
    unordered_map<int, int> bfsNumber;
    int counter = 1;

    bfsQueue.push(startVertex);
    bfsNumber[startVertex] = counter++;
    visited[startVertex] = true;

    vector<BFSResult> result;

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        // Зберігаємо поточну вершину, її BFS-номер і стан черги для протоколу обходу
        vector<int> queueContents;
        queue<int> tempQueue = bfsQueue;
        while (!tempQueue.empty()) {
            queueContents.push_back(tempQueue.front());
            tempQueue.pop();
        }

        result.push_back({ currentVertex, bfsNumber[currentVertex], queueContents });

        for (int neighbor : graph.at(currentVertex)) {
            if (!visited[neighbor]) {
                bfsQueue.push(neighbor);
                visited[neighbor] = true;
                bfsNumber[neighbor] = counter++;
            }
        }
    }

    return result;
}

int main() {
    string filename;
    cout << "Vvedit imya failu z opysom graphu: ";
    cin >> filename;

    auto graph = readGraphFromFile(filename);

    int startVertex;
    cout << "Vvedit pochatkovu vershynu: ";
    cin >> startVertex;

    cout << "\nProtokol obhodu graphu:\n";
    cout << left << setw(15) << "Potochna vershyna" << setw(15) << "BFS-nomer" << "Vmist chergu" << endl;
    cout << "------------------------------------------------" << endl;

    auto bfsResult = breadthFirstSearch(graph, startVertex);

    for (const auto& entry : bfsResult) {
        cout << setw(15) << entry.vertex << setw(15) << entry.bfsNumber;
        for (int val : entry.queueContents) cout << val << " ";
        cout << endl;
    }

    return 0;
}
