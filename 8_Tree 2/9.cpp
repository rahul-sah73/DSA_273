#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int in_time[MAXN], out_time[MAXN];
int timer = 0;
string s;
vector<int> char_pos[26];

void dfs(int u, int p) {
    in_time[u] = ++timer;
    char_pos[s[u - 1] - 'a'].push_back(timer);
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    
    out_time[u] = timer;
}

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    
    cin >> s;
    
    int i;
    for(i = 0;i<N-1;i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    while(Q--) {
        int u;
        char c;
        cin >> u >> c;
        
        int char_idx = c - 'a';
        int l = in_time[u];
        int r = out_time[u];
        
        auto it1 = lower_bound(char_pos[char_idx].begin(), char_pos[char_idx].end(), l);
        auto it2 = upper_bound(char_pos[char_idx].begin(), char_pos[char_idx].end(), r);
        
        cout << (it2 - it1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

