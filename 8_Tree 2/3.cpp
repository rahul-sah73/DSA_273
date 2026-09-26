#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], rev_adj[MAXN];
vector<int> order;
bool vis[MAXN];
int scc[MAXN];

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int id) {
    scc[u] = id;
    for (int v : rev_adj[u]) {
        if (!scc[v]) dfs2(v, id);
    }
}

bool can_reach(int u, int target_scc, vector<bool>& visited_scc, const vector<vector<int>>& scc_adj) {
    if (u == target_scc) return true;
    visited_scc[u] = true;
    for (int v : scc_adj[u]) {
        if (!visited_scc[v] && can_reach(v, target_scc, visited_scc, scc_adj)) return true;
    }
    return false;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        rev_adj[i].clear();
        vis[i] = false;
        scc[i] = 0;
    }
    order.clear();
    
    int mm = m;
    while(mm--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs1(i);
    }
    
    int scc_cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (!scc[u]) {
            dfs2(u, ++scc_cnt);
        }
    }
    
    if (scc_cnt == 1) {
        cout << 0 << "\n";
        return;
    }
    
    vector<int> in_degree(scc_cnt + 1, 0);
    vector<int> out_degree(scc_cnt + 1, 0);
    vector<vector<int>> scc_adj(scc_cnt + 1);
    
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) {
                out_degree[scc[u]]++;
                in_degree[scc[v]]++;
                scc_adj[scc[u]].push_back(scc[v]);
            }
        }
    }
    
    vector<int> sources, sinks;
    vector<int> scc_rep(scc_cnt + 1);
    for (int i = 1; i <= n; ++i) {
        scc_rep[scc[i]] = i;
    }
    
    for (int i = 1; i <= scc_cnt; ++i) {
        if (in_degree[i] == 0) sources.push_back(i);
        if (out_degree[i] == 0) sinks.push_back(i);
    }
    
    vector<bool> matched_sink(scc_cnt + 1, false);
    vector<int> S, T, U, V;
    
    for (int src : sources) {
        int found_sink = -1;
        vector<bool> visited_scc(scc_cnt + 1, false);
        vector<int> q;
        q.push_back(src);
        visited_scc[src] = true;
        
        int head = 0;
        while (head < q.size()) {
            int u = q[head++];
            if (out_degree[u] == 0 && !matched_sink[u]) {
                found_sink = u;
                break;
            }
            for (int v : scc_adj[u]) {
                if (!visited_scc[v]) {
                    visited_scc[v] = true;
                    q.push_back(v);
                }
            }
        }
        
        if (found_sink != -1) {
            S.push_back(src);
            T.push_back(found_sink);
            matched_sink[found_sink] = true;
        } else {
            U.push_back(src);
        }
    }
    
    for (int snk : sinks) {
        if (!matched_sink[snk]) {
            V.push_back(snk);
        }
    }
    
    vector<int> S_arr = S;
    for (int u : U) S_arr.push_back(u);
    
    vector<int> T_arr = T;
    for (int v : V) T_arr.push_back(v);
    
    int k = max(S_arr.size(), T_arr.size());
    cout << k << "\n";
    
    for (int i = 0; i < k; ++i) {
        int from = T_arr[i % T_arr.size()];
        int to = S_arr[(i + 1) % S_arr.size()];
        cout << scc_rep[from] << " " << scc_rep[to] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

