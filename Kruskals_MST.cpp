#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
char u, v;
int w;
};
int parent[26];
int find(int x) {
if (parent[x] == x)
return x;
return parent[x] = find(parent[x]);
}
int main() {
int n, e, total = 0, count = 0;
Edge a[100];
cout << "Enter number of vertices: ";
cin >> n;
cout << "Enter number of edges: ";
cin >> e;
if (n <= 0 || n > 26 || e < 0 || e > 100) {
cout << "Invalid input";
return 0;
}
cout << "Enter edges (Vertex1 Vertex2 Weight):\n";
for (int i = 0; i < e; i++) {
cin >> a[i].u >> a[i].v >> a[i].w;
if (a[i].u < 'A' || a[i].u >= 'A' + n ||
a[i].v < 'A' || a[i].v >= 'A' + n ||
a[i].u == a[i].v || a[i].w <= 0) {
cout << "Invalid edge";
return 0;
}
}
sort(a, a + e, [](Edge x, Edge y) {
return x.w < y.w;
});
for (int i = 0; i < n; i++)
parent[i] = i;
cout << "\nEdges in MST:\n";
for (int i = 0; i < e && count < n - 1; i++) {
int u = find(a[i].u - 'A');
int v = find(a[i].v - 'A');
if (u != v) {
parent[u] = v;
cout << a[i].u << " - " << a[i].v
<< " : " << a[i].w << endl;
total += a[i].w;
count++;
}
}
if (count != n - 1) {
cout << "MST not possible";
return 0;
}
cout << "Total MST Weight: " << total;
return 0;
}