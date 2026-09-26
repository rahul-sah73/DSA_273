#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int capacity[505][505];
int adj[505][505];
int parent_node[505];

int bfs(int n,int s,int t) {
    fill(parent_node, parent_node + n + 1, -1);
    parent_node[s] = s;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v = 1; v <= n; ++v) {
            if (parent_node[v] == -1 && capacity[u][v] > 0) {
                parent_node[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == t)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        capacity[u][v]++;
        adj[u][v]++;
    }

    int max_flow = 0;
    int flow;
    while ((flow = bfs(n, 1, n))) {
        max_flow += flow;
        int curr = n;
        while (curr != 1) {
            int prev = parent_node[curr];
            capacity[prev][curr] -= flow;
            capacity[curr][prev] += flow;
            curr = prev;
        }
    }

    cout << max_flow << "\n";

    for (int i = 0; i < max_flow; ++i) {
        vector<int> path;
        int curr = 1;
        path.push_back(curr);
        while (curr != n) {
            bool found = false;
            for (int nxt = 1; nxt <= n; ++nxt) {
                if (adj[curr][nxt] > 0 && capacity[curr][nxt] < adj[curr][nxt]) {
                    adj[curr][nxt]--; // consume one used edge
                    capacity[curr][nxt]++; // restore to match adj invariant if needed
                    curr = nxt;
                    path.push_back(curr);
                    found = true;
                    break;
                }
            }
            if (!found) break; // Should not happen
        }
        cout << path.size() << "\n";
        for (int j = 0; j < path.size(); ++j) {
            cout << path[j] << (j == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}

