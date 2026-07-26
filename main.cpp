#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& order) {
    visited[v] = true;

    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, order);
        }
    }

    order.push(v);
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Ne udalos otkryt fail input.txt" << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> graph[i][j];
        }
    }

    file.close();

    vector<bool> visited(n, false);
    stack<int> order;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, order);
        }
    }

    cout << "Topologicheskyi poryadok vershin: ";
    while (!order.empty()) {
        cout << order.top() + 1 << " ";
        order.pop();
    }
    cout << endl;

    return 0;
}