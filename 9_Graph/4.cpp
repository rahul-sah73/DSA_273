#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    DSU dsu(n);

    while(m--) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    vector<int> reps;
    for (int i = 1; i <= n; ++i) {
        if (dsu.find(i) == i) {
            reps.push_back(i);
        }
    }

    cout << reps.size() - 1 << "\n";
    for (size_t i = 1; i < reps.size(); ++i) {
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }

    return 0;
}

