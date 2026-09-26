#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<vector<int>, int> subtree_id;

int get_id(vector<int>& children) {
    sort(children.begin(), children.end());
    if (subtree_id.find(children) == subtree_id.end()) {
        subtree_id[children] = subtree_id.size();
    }
    return subtree_id[children];
}

int dfs(int u, int p, const vector<vector<int>>& adj) {
    vector<int> children;
    for (int v : adj[u]) {
        if (v != p) {
            children.push_back(dfs(v, u, adj));
        }
    }
    return get_id(children);
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj1(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    
    vector<vector<int>> adj2(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    int id1 = dfs(1, 0, adj1);
    int id2 = dfs(1, 0, adj2);
    
    if (id1 == id2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
