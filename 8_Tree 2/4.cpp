#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int printheap(int N) {
    return 0;
}

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    long long max_weight = 0;
    
    for (int i = 0; i < m; ++i) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            max_weight += edges[i].w;
        }
    }
    
    cout << max_weight << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

