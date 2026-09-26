#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> code(n - 2);
    vector<int> degree(n + 1, 1);
    
    for (int i = 0; i < n - 2; ++i) {
        cin >> code[i];
        degree[code[i]]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }
    
    for (int i = 0; i < n - 2; ++i) {
        int leaf = q.top();
        q.pop();
        
        int u = code[i];
        cout << leaf << " " << u << "\n";
        
        degree[u]--;
        if (degree[u] == 1) {
            q.push(u);
        }
    }
    
    int u = q.top();
    q.pop();
    int v = q.top();
    q.pop();
    
    cout << u << " " << v << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

