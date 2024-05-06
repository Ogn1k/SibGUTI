#include <iostream>
#include <locale.h>
#include <vector>
#include <assert.h>

using namespace std;

enum Choise
{
    NOTHING = -2,
    END = -1,
    PRINT_GRAPH = 0,
    EDIT_GRAPH = 1,
    GRAPH_VERTICES = 2,
    FIND_SCC = 3,
    FIND_SCC_SPECIAL = 4
};

template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.front() = std::move(vec.back());
    vec.pop_back();
}

void DFS1(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int u = 0; u < graph[v].size(); u++) {
        if (graph[v][u] && !visited[u]) {
            DFS1(u, graph, visited, component);
        }
    }
}

void find_comp(vector<vector<int>> graph, int n)
{

    vector<bool> visited(n, false);
    int componentCount = 0;
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            vector<int> component;
            DFS1(v, graph, visited, component);
            cout << "Компонента связности " << ++componentCount << ": ";
            for (int vertex : component) {
                cout << vertex + 1 << ' ';
            }
            cout << '\n';
        }
    }

}

void printGraph(vector<vector<int>>& graph, int row = -1, int col = -1) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (i == row || j == col) {
                cout << "\033[4m" << graph[i][j] << "\033[0m ";  // Подчеркивание
            } else {
                cout << graph[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

void editGraph(vector<vector<int>>& graph) {
    int row, col, value;
    cout << "Введите номер строки для редактирования: ";
    cin >> row;
    cout << "Введите номер столбца для редактирования: ";
    cin >> col;
    cout << "Введите новое значение: ";
    cin >> value;
    graph[row - 1][col - 1] = value;  // Индексация с 0

    cout << "Обновленная матрица смежности:\n";
    printGraph(graph, row - 1, col - 1);
}

void resizeGraph(vector<vector<int>>& graph) {
    int newSize;
    cout << "Введите новое количество вершин: ";
    cin >> newSize;

    graph.resize(newSize);
    for (auto& row : graph) {
        row.resize(newSize);
    }

    cout << "Граф обновлен. Текущее количество вершин: " << newSize << '\n';
}



void DFS2(int v, vector<vector<int>>& graphT, vector<bool>& visited) {
    visited[v] = true;
    cout << v + 1 << ' ';
    for (int u = 0; u < graphT[v].size(); u++) {
        if (graphT[v][u] && !visited[u]) {
            DFS2(u, graphT, visited);
        }
    }
}

void findSCCs(vector<vector<int>>& graph) {
    vector<int> vectordfs;
    vector<bool> visited(graph.size(), false);

    for (int v = 0; v < graph.size(); v++) {
        if (!visited[v]) {
            DFS1(v, graph, visited, vectordfs);
        }
    }

    vector<vector<int>> graphT(graph.size(), vector<int>(graph.size()));
    for (int v = 0; v < graph.size(); v++) {
        for (int u = 0; u < graph[v].size(); u++) {
            graphT[u][v] = graph[v][u];
        }
    }

    fill(visited.begin(), visited.end(), false);
    while (!vectordfs.empty()) {
        int v = vectordfs.front();
        pop_front(vectordfs);
        if (!visited[v]) {
            DFS2(v, graphT, visited);
            cout << '\n';
        }
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    int n = 5;
    // cout << "Введите количество вершин графа: ";
    // cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 1;
        }
    }

    // cout << "Введите матрицу смежности графа:\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> graph[i][j];
    //     }
    // }

    Choise choise;
    int aa;

    while(choise != END)
    {
        switch (choise) 
        {
        case PRINT_GRAPH:
            printGraph(graph);
            choise = NOTHING;
            break;
        case EDIT_GRAPH:
            editGraph(graph);
            choise = NOTHING;
            break;
        case GRAPH_VERTICES:
            resizeGraph(graph);
            choise = NOTHING;
            break;
        case FIND_SCC:
            find_comp(graph, n);
            choise = NOTHING;
            break;
        case FIND_SCC_SPECIAL:
            findSCCs(graph);
            choise = NOTHING;
            break;
        default:
            std::cout << "-1. выйти из программы\n0. вывести граф\n1. изменить граф\n2. изменить кол-во вершин графа\n3. поиск компонент связности\n4. поиск компонент сильной связности в ориентированном графе\n";
            if (!(std::cin >> aa)) { std::cout << "send help"; choise = NOTHING; break; }
            choise = static_cast<Choise>(aa);
            break;
            
        }
    }
    

    return 0;
}