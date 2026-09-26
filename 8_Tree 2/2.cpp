#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    multiset<long long> s;
    long long current_sum = 0;
    int i;
    for(i=0;i<n;i++) {
        long long x;
        cin >> x;
        s.insert(x);
        current_sum += x;
    }
    
    vector<long long> ans(n, 0);
    ans[0] = current_sum;
    
    for (int k = 1; k < n; ++k) {
        auto it_min = s.begin();
        auto it_max = prev(s.end());
        
        long long min_val = *it_min;
        long long max_val = *it_max;
        
        s.erase(it_min);
        s.erase(it_max);
        
        long long diff = max_val - min_val;
        s.insert(diff);
        
        current_sum -= (2 * min_val);
        ans[k] = current_sum;
    }
    
    for (int j = 0; j < q; ++j) {
        int k;
        cin >> k;
        cout << ans[k] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

