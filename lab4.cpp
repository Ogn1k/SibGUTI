#include <iostream>
#include <vector>
#include <locale.h>
#include <sstream>
#include <algorithm>

using namespace std;

bool isFloat(const std::string& str) 
{
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f; 
    return iss.eof() && !iss.fail();
}

float stringToFloat(const std::string& str) 
{
    std::istringstream iss(str);
    float result;
    iss >> std::noskipws >> result; 
    return result;
}

// Рекурсивная функция для обхода в глубину
void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[node][neighbor] == 1 && !visited[neighbor]) {
            dfs(graph, visited, neighbor, component);
        }
    }
}

// Функция для поиска компонент связности
vector<vector<int>> findConnectedComponents(const vector<vector<int>>& adjMatrix) {
    int numVertices = adjMatrix.size();
    vector<bool> visited(numVertices, false);
    vector<vector<int>> components;

    for (int vertex = 0; vertex < numVertices; ++vertex) {
        if (!visited[vertex]) {
            vector<int> component;
            dfs(adjMatrix, visited, vertex, component);
            components.push_back(component);
        }
    }

    return components;
}

int main() {

    setlocale(LC_ALL, "");
    // Пример матрицы смежности (замените на ввод пользователя)
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };

    
    // std::string aa = "";
    // std::string ab = "";
    // int i=0;

    // std::cout << "enter array\n";
    // while(aa != "end")
    // {
    //     while(ab != "end")
    //     {
    //         std::cin >> aa;
    //         if(isFloat(aa))
    //         {
    //             adjacencyMatrix[i].insert(adjacencyMatrix[i].begin(), stringToFloat(ab));
    //         }
    //     }
    //     i++;
    // }

    auto connectedComponents = findConnectedComponents(adjacencyMatrix);
    for (int i = 0; i < connectedComponents.size(); ++i) {
        cout << "Компонента " << i + 1 << ": ";
        for (int vertex : connectedComponents[i]) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
