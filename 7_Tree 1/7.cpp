#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct state {
    int len, link;
    map<int, int> next;
};

const int MAXL=200005;
state st[MAXL];
int sz, last;

void sam_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
}

int sam_extend(int last, int c) {
    if (st[last].next.count(c)) {
        int q = st[last].next[c];
        if (st[q].len == st[last].len + 1) return q;
        int clone = sz++;
        st[clone].len = st[last].len + 1;
        st[clone].next = st[q].next;
        st[clone].link = st[q].link;
        while (last != -1 && st[last].next[c] == q) {
            st[last].next[c] = clone;
            last = st[last].link;
        }
        st[q].link = clone;
        return clone;
    }
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    return cur;
}

vector<int> adj[100005];
int deg[100005];

void dfs(int u, int p, int last_state) {
    int cur_state = sam_extend(last_state, deg[u]);
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, cur_state);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
    sam_init();
    dfs(1, 0, 0);
    
    long long ans = 0;
    for (int i = 1; i < sz; i++) {
        ans += st[i].len - st[st[i].link].len;
    }
    cout << ans << "\n";
    
    return 0;
}
