#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Segment {
    ll xl, xr;
};

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        ll n, L;
        cin >> n >> L;
        vector<Segment> a(n);
        for(ll i=0;i<n;i++) {
            cin >> a[i].xl >> a[i].xr;
        }
        sort(a.begin(), a.end(), [](const Segment& x, const Segment& y){
            if (x.xl != y.xl) return x.xl < y.xl;
            return x.xr < y.xr;
        });
        
        bool found = false;
        for(ll i=0;i<n;i++) {
            ll start = a[i].xl;
            ll maxright = start + L;
            ll cur_right = start;
            for(ll j=0;j<n;j++) {
                if (a[j].xl >= start && a[j].xr <= maxright) {
                    if (a[j].xl <= cur_right) {
                        cur_right = max(cur_right, a[j].xr);
                    }
                }
            }
            if(cur_right==maxright) {
                found = true;
                break;
            }
        }
        if (found) cout << "Yes";
        else cout << "No";
    }
    return 0;
}
