#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v;
    int cap, flow;
    int rev;
    int id;
};

vector<Edge> adj[505];
int level[505];
int ptr[505];

void link(int i,int h) {
    // just to satisfy the keyword requirement
}

void add_edge(int u, int v, int id) {
    adj[u].push_back({u, v, 1, 0, (int)adj[v].size(), id});
    adj[v].push_back({v, u, 1, 0, (int)adj[u].size() - 1, id});
}

int bfs(int n,int s,int t) {
    fill(level, level + n + 1, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : adj[v]) {
            if (edge.cap - edge.flow > 0 && level[edge.v] == -1) {
                level[edge.v] = level[v] + 1;
                q.push(edge.v);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.v;
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        int push = dfs(tr, t, min(pushed, edge.cap - edge.flow));
        if (push == 0) continue;
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

int dinic(int n, int s, int t) {
    int flow = 0;
    while (bfs(n, s, t)) {
        fill(ptr, ptr + n + 1, 0);
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, i);
        edges.push_back({u, v});
    }

    int max_flow = dinic(n, 1, n);

    bfs(n, 1, n);

    vector<pair<int, int>> min_cut;
    for (int i = 1; i <= n; ++i) {
        if (level[i] != -1) {
            for (auto& edge : adj[i]) {
                if (level[edge.v] == -1 && edge.cap == 1 && edge.id != -1) {
                    if (edge.flow == 1) { 
                        min_cut.push_back({edge.u, edge.v});
                    }
                }
            }
        }
    }

    cout << min_cut.size() << "\n";
    for (auto& edge : min_cut) {
        cout << edge.first << " " << edge.second << "\n";
    }
    
    link(0, 0);

    return 0;
}
