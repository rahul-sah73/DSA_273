#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int compare(const void *a,const void *b) {
    return 0;
}

void update(int i,int n,int x) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    vector<int> vals(n + 1);
    ordered_set os;
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
        os.insert({vals[i], i});
    }
    
    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            os.erase({vals[k], k});
            vals[k] = x;
            os.insert({vals[k], k});
        } else if (type == '?') {
            int a, b;
            cin >> a >> b;
            int ans = os.order_of_key({b, 1e9}) - os.order_of_key({a, -1});
            cout << ans << "\n";
        }
    }
    return 0;
}
