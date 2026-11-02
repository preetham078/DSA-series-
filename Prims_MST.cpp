#include <iostream>
using namespace std;

int main() {
    int n, g[26][26], key[26], parent[26], total = 0;
    bool mst[26] = {};

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > 26) {
        cout << "Invalid input";
        return 0;
    }

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++) {
        key[i] = 999999;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int c = 0; c < n; c++) {
        int u = -1, mn = 999999;

        for (int i = 0; i < n; i++)
            if (!mst[i] && key[i] < mn)
                mn = key[i], u = i;

        if (u == -1) {
            cout << "MST not possible";
            return 0;
        }

        mst[u] = true;

        for (int v = 0; v < n; v++)
            if (g[u][v] && !mst[v] && g[u][v] < key[v])
                key[v] = g[u][v], parent[v] = u;
    }

    cout << "\nEdges in MST:\n";

    for (int i = 1; i < n; i++) {
        cout << char('A' + parent[i]) << " - "
             << char('A' + i) << " : "
             << g[i][parent[i]] << endl;

        total += g[i][parent[i]];
    }

    cout << "Total MST Weight: " << total;

    return 0;
}