#include <vector>
#include <iostream>
using namespace std;
vector<bool> visited(100, false);
vector<vector<int>> adj_list(100);

void dfs(int v, int parent) {
    if (visited[v]) return;
    visited[v] = true;
    cout << v << " ";
    for (int i=1; i<adj_list[v].size(); ++i) {
        if (adj_list[v][i]==parent) continue;
        else if (visited[adj_list[v][i]]) {
            cout << "cycle";
            exit(0);
        }
        dfs(adj_list[v][i], v);
    }
}
int main() {
    int v, e, v1, v2, i=1;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;
    cout << "Enter the vertices: ";
    for (int i=0; i<e; ++i) {
        cin >> v1 >> v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    while (i<=v) {
        if (!visited[i]) dfs(i, 0);
        i++;
    }
    return 0;
}