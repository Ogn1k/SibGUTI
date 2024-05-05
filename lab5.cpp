#include <iostream>
#include <vector>

using namespace std;

void DFS(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int u = 0; u < graph[v].size(); u++) {
        if (graph[v][u] && !visited[u]) {
            DFS(u, graph, visited, component);
        }
    }
}

int main() {
    int n;
    cout << "Введите количество вершин графа: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Введите матрицу смежности графа:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(n, false);
    int componentCount = 0;
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            vector<int> component;
            DFS(v, graph, visited, component);
            cout << "Компонента связности " << ++componentCount << ": ";
            for (int vertex : component) {
                cout << vertex + 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}