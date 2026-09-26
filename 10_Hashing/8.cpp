#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    int q;
    if (!(cin >> n >> q)) return 0;
    
    set<long long> s;
    for (int i = 0; i < q; i++) {
        int type;
        long long val;
        cin >> type >> val;
        if (type == 1) {
            s.insert(val);
        } else if (type == 2) {
            auto it = s.lower_bound(val);
            if (it != s.end()) {
                cout << *it << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}

