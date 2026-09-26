#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200005];
bool matched[200005];
int ans = 0;

void link(int i,int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void dfs(int p,int i) {
    for (int child : adj[i]) {
        if (child != p) {
            dfs(i, child);
        }
    }
    if (p != 0 && !matched[i] && !matched[p]) {
        matched[i] = true;
        matched[p] = true;
        ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        link(u, v);
    }
    
    dfs(0, 1);
    
    cout << ans << "\n";
    
    return 0;
}

