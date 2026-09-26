#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    map<string, vector<long long>> spendings;
    for (int i = 0; i < n; ++i) {
        string s;
        long long x;
        cin >> s >> x;
        spendings[s].push_back(x);
    }
    
    long long max_sum = -1;
    string best_festival = "";
    
    for (auto& pair : spendings) {
        sort(pair.second.rbegin(), pair.second.rend());
        long long current_sum = 0;
        for (int i = 0; i < min(3, (int)pair.second.size()); ++i) {
            current_sum += pair.second[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_festival = pair.first;
        } else if (current_sum == max_sum) {
            if (best_festival == "" || pair.first < best_festival) {
                best_festival = pair.first;
            }
        }
    }
    
    cout << best_festival << " " << max_sum << "\n";
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

