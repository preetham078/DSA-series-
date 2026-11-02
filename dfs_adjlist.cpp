#include <iostream>
#include <list>
using namespace std;

list<int> adj[100];
bool visited[100] = {false};

void dfs(int v) {
    visited[v] = true;

    cout << v << " ";

    for (int x : adj[v])
        if (!visited[x])
            dfs(x);
}

int main() {
    int n, e, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of vertices";
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    if (e < 0 || e > n * (n - 1) / 2) {
        cout << "Invalid number of edges";
        return 0;
    }

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < e; i++) {
        cin >> u >> v;

        if (u < 0 || v < 0 || u >= n || v >= n) {
            cout << "Invalid edge";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex";
        return 0;
    }

    cout << "Depth First Search Traversal: ";

    dfs(start);

    return 0;
}