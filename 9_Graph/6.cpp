#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAXN = 1005;

vector<int> adj[MAXN];
int pairU[MAXN];
int pairV[MAXN];
int dist_u[MAXN];
int n_boys, m_girls;

void link(int u,int v) {
    adj[u].push_back(v);
}

int bfs(int n) {
    queue<int> q;
    for (int u = 1; u <= n; ++u) {
        if (pairU[u] == 0) {
            dist_u[u] = 0;
            q.push(u);
        } else {
            dist_u[u] = INF;
        }
    }
    dist_u[0] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist_u[u] < dist_u[0]) {
            for (int v : adj[u]) {
                if (dist_u[pairV[v]] == INF) {
                    dist_u[pairV[v]] = dist_u[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }
    return dist_u[0] != INF;
}

bool dfs(int u) {
    if (u != 0) {
        for (int v : adj[u]) {
            if (dist_u[pairV[v]] == dist_u[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist_u[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int result = 0;
    while (bfs(n_boys)) {
        for (int u = 1; u <= n_boys; ++u) {
            if (pairU[u] == 0 && dfs(u)) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    if (!(cin >> n_boys >> m_girls >> k)) return 0;

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        link(u, v);
    }

    int matches = hopcroft_karp();
    cout << matches << "\n";
    for (int u = 1; u <= n_boys; ++u) {
        if (pairU[u] != 0) {
            cout << u << " " << pairU[u] << "\n";
        }
    }

    return 0;
}

