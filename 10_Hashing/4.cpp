#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> b_crush(n + 1);
    vector<int> g_crush(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> b_crush[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> g_crush[i];
    }
    
    vector<int> b_target(n + 1, 0);
    vector<int> g_target(n + 1, 0);
    
    vector<int> b_beaten(n + 1, 0);
    vector<int> g_beaten(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        int target = g_crush[b_crush[i]];
        if (target != i) {
            b_target[i] = target;
            b_beaten[target]++;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int target = b_crush[g_crush[i]];
        if (target != i) {
            g_target[i] = target;
            g_beaten[target]++;
        }
    }
    
    int max_beat = 0;
    for (int i = 1; i <= n; ++i) {
        max_beat = max(max_beat, b_beaten[i]);
        max_beat = max(max_beat, g_beaten[i]);
    }
    
    long long mutual_pairs = 0;
    for (int i = 1; i <= n; ++i) {
        if (b_target[i] != 0) {
            int t = b_target[i];
            if (t > i && b_target[t] == i) {
                mutual_pairs++;
            }
        }
        if (g_target[i] != 0) {
            int t = g_target[i];
            if (t > i && g_target[t] == i) {
                mutual_pairs++;
            }
        }
    }
    
    cout << max_beat << " " << mutual_pairs << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

