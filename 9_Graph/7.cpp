#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent_node[100005];
int sz[100005];
int num_components;
int max_size;

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

int join(int i,int j) {
    int a = find_set(i);
    int b = find_set(j);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent_node[b] = a;
        sz[a] += sz[b];
        num_components--;
        max_size = max(max_size, sz[a]);
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i) {
        parent_node[i] = i;
        sz[i] = 1;
    }
    num_components = n;
    max_size = 1;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        join(u, v);
        cout << num_components << " " << max_size << "\n";
    }

    return 0;
}

