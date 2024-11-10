#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iomanip>

using namespace std;

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
struct DFSResult {
    int vertex;
    int dfsNumber;
    vector<int> stackContents;
};

// Функція для DFS з поверненням протоколу обходу
vector<DFSResult> depthFirstSearch(const unordered_map<int, vector<int>>& graph, int startVertex) {
    unordered_map<int, bool> visited;
    stack<int> dfsStack;
    unordered_map<int, int> dfsNumber;
    int counter = 1;

    dfsStack.push(startVertex);
    dfsNumber[startVertex] = counter++;
    visited[startVertex] = true;

    vector<DFSResult> result;

    while (!dfsStack.empty()) {
        int currentVertex = dfsStack.top();
        dfsStack.pop();

        // Зберігаємо поточну вершину, її DFS-номер і стан стеку для протоколу обходу
        vector<int> stackContents;
        stack<int> tempStack = dfsStack;
        while (!tempStack.empty()) {
            stackContents.push_back(tempStack.top());
            tempStack.pop();
        }

        result.push_back({ currentVertex, dfsNumber[currentVertex], stackContents });

        for (int neighbor : graph.at(currentVertex)) {
            if (!visited[neighbor]) {
                dfsStack.push(neighbor);
                visited[neighbor] = true;
                dfsNumber[neighbor] = counter++;
            }
        }
    }

    return result;
}

int main() {
    string filename;
    cout << "Vvedit imya failu z opysom grafu: ";
    cin >> filename;

    auto graph = readGraphFromFile(filename);

    int startVertex;
    cout << "Vvedit pochatkovu vershynu: ";
    cin >> startVertex;

    cout << "\nProtokol obhodu grafu:\n";
    cout << left << setw(15) << "Potochna vershyna" << setw(15) << "DFS-nomer" << "Vmist steku" << endl;
    cout << "------------------------------------------------" << endl;

    auto dfsResult = depthFirstSearch(graph, startVertex);

    for (const auto& entry : dfsResult) {
        cout << left << setw(15) << entry.vertex << setw(15) << entry.dfsNumber;
        for (int val : entry.stackContents) cout << val << " ";
        cout << endl;
    }

    return 0;
}
