#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
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
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m1, m2;
    if (!(cin >> n >> m1 >> m2)) return 0;
    
    DSU dsu1(n), dsu2(n);
    
    while(m1--) {
        int u, v;
        cin >> u >> v;
        dsu1.unite(u, v);
    }
    
    while(m2--) {
        int u, v;
        cin >> u >> v;
        dsu2.unite(u, v);
    }
    
    vector<pair<int, int>> ans;
    
    for (int i = 2; i <= n; i++) {
        if (dsu1.find(1) != dsu1.find(i) && dsu2.find(1) != dsu2.find(i)) {
            ans.push_back({1, i});
            dsu1.unite(1, i);
            dsu2.unite(1, i);
        }
    }
    
    vector<int> L1, L2;
    for (int i = 2; i <= n; i++) {
        if (dsu1.find(i) == i && dsu1.find(i) != dsu1.find(1)) {
            L1.push_back(i);
        }
        if (dsu2.find(i) == i && dsu2.find(i) != dsu2.find(1)) {
            L2.push_back(i);
        }
    }
    
    int k = min(L1.size(), L2.size());
    for (int i = 0; i < k; i++) {
        ans.push_back({L1[i], L2[i]});
    }
    
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}
