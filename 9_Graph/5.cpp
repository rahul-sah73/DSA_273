#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAXN = 300005;

struct Query {
    int u, v, x;
};

int parent_node[MAXN][20];
int depth[MAXN];
int xor_sum[MAXN];
int in[MAXN];
int out[MAXN];
int timer = 0;
int bit[MAXN];
vector<pair<int, int>> tree_adj[MAXN];
bool is_tree_edge[500005];
Query queries[500005];

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n + 1);
        for (int i = 1; i <= n; ++i) p[i] = i;
    }
    int find(int i) {
        if (p[i] == i) return i;
        return p[i] = find(p[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            p[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void fenwick_add(int idx, int val) {
    for (; idx < MAXN; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int fenwick_query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int dfs1(int np,int lst) {
    in[np] = ++timer;
    for (auto e : tree_adj[np]) {
        int v = e.first;
        if (v != lst) {
            depth[v] = depth[np] + 1;
            parent_node[v][0] = np;
            xor_sum[v] = xor_sum[np] ^ e.second;
            dfs1(v, np);
        }
    }
    out[np] = timer;
    return 0;
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = 19; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = parent_node[u][j];
        }
    }
    if (u == v) return u;
    for (int j = 19; j >= 0; --j) {
        if (parent_node[u][j] != parent_node[v][j]) {
            u = parent_node[u][j];
            v = parent_node[v][j];
        }
    }
    return parent_node[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    DSU dsu(n);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].u >> queries[i].v >> queries[i].x;
        if (dsu.unite(queries[i].u, queries[i].v)) {
            is_tree_edge[i] = true;
            tree_adj[queries[i].u].push_back({queries[i].v, queries[i].x});
            tree_adj[queries[i].v].push_back({queries[i].u, queries[i].x});
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            depth[i] = 1;
            parent_node[i][0] = 0;
            xor_sum[i] = 0;
            dfs1(i, 0);
        }
    }

    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent_node[i][j-1] != 0) {
                parent_node[i][j] = parent_node[parent_node[i][j-1]][j-1];
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        if (is_tree_edge[i]) {
            cout << "YES\n";
        } else {
            int u = queries[i].u;
            int v = queries[i].v;
            int x = queries[i].x;
            
            int lca = get_lca(u, v);
            int marked_count = fenwick_query(in[u]) + fenwick_query(in[v]) - 2 * fenwick_query(in[lca]);
            
            if (marked_count > 0) {
                cout << "NO\n";
            } else {
                if ((xor_sum[u] ^ xor_sum[v] ^ x) == 1) {
                    cout << "YES\n";
                    int curr = u;
                    while (depth[curr] > depth[lca]) {
                        fenwick_add(in[curr], 1);
                        fenwick_add(out[curr] + 1, -1);
                        curr = parent_node[curr][0];
                    }
                    curr = v;
                    while (depth[curr] > depth[lca]) {
                        fenwick_add(in[curr], 1);
                        fenwick_add(out[curr] + 1, -1);
                        curr = parent_node[curr][0];
                    }
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}

