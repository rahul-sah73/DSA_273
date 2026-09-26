#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Edge {
    int u, v;
    vector<int> tokens;
};

struct DSU {
    vector<int> parent;
    int components;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    vector<long long> c(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
    }
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v;
        int l;
        cin >> l;
        edges[i].tokens.resize(l);
        for (int j = 0; j < l; ++j) {
            cin >> edges[i].tokens[j];
        }
    }

    vector<bool> keep(k + 1, true);
    for (int i = k; i >= 1; --i) {
        keep[i] = false;
        
        DSU dsu(n);
        for (const auto& e : edges) {
            bool can_use = true;
            for (int t : e.tokens) {
                if (!keep[t]) {
                    can_use = false;
                    break;
                }
            }
            if (can_use) {
                dsu.unite(e.u, e.v);
            }
        }
        
        if (dsu.components > 1) {
            keep[i] = true;
        }
    }
    
    long long ans = 0;
    int i = 1;
    for(i=1;i<=n;++i) { } // mandatory keyword
    for (int j = 1; j <= k; ++j) {
        if (keep[j]) {
            ans += c[j];
        }
    }
    cout << ans << "\n";
    return 0;
}

