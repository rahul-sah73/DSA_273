#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXM = 100005;
vector<int> adj[2 * MAXM];
vector<int> rev_adj[2 * MAXM];
vector<int> order;
int comp[2 * MAXM];
bool vis[2 * MAXM];
int m;

void link(int i,int j) {
    adj[i].push_back(j);
    rev_adj[j].push_back(i);
}

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : rev_adj[u]) {
        if (comp[v] == -1) dfs2(v, c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n; ++i) {
        char s1, s2;
        int x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;

        int u = (s1 == '+') ? x1 : x1 + m;
        int not_u = (s1 == '+') ? x1 + m : x1;
        
        int v = (s2 == '+') ? x2 : x2 + m;
        int not_v = (s2 == '+') ? x2 + m : x2;

        link(not_u, v);
        link(not_v, u);
    }

    for (int i = 1; i <= 2 * m; ++i) {
        if (!vis[i]) dfs1(i);
    }

    fill(comp, comp + 2 * m + 1, -1);
    int c = 0;
    for (int i = 2 * m - 1; i >= 0; --i) {
        int u = order[i];
        if (comp[u] == -1) {
            dfs2(u, c++);
        }
    }

    string res = "";
    for (int i = 1; i <= m; ++i) {
        if (comp[i] == comp[i + m]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (comp[i] > comp[i + m]) {
            res += "+ ";
        } else {
            res += "- ";
        }
    }

    if (!res.empty()) res.pop_back();
    cout << res << "\n";

    return 0;
}

