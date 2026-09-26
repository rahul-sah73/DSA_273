#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    map<int, int> freq;
    int i;
    for(i=0;i<N;i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    int Q;
    cin >> Q;
    
    int current_size = N;
    for (int q = 0; q < Q; ++q) {
        int val;
        cin >> val;
        
        bool can_insert = true;
        if (freq[val] >= 2) {
            can_insert = false;
        } else if (freq[val] == 1) {
            auto it = freq.rbegin();
            if (it->first == val) {
                can_insert = false;
            }
        }
        
        if (can_insert) {
            freq[val]++;
            current_size++;
        }
        cout << current_size << "\n";
    }
    
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " ";
    }
    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        if (it->second == 2) {
            cout << it->first << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

