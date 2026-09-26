#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long val, h;
    bool operator<(const Point& o) const { return val < o.val; }
};

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t-->0) {
        int n;
        cin >> n;
        vector<Point> pts;
        for(int i = 0;i < n;i++) {
            long long x, y, h;
            cin >> x >> y >> h;
            pts.push_back({y - x, h});
        }
        sort(pts.begin(), pts.end());
        
        vector<Point> merged;
        for(int i=0; i<n; i++) {
            if (merged.empty() || merged.back().val != pts[i].val) {
                merged.push_back(pts[i]);
            } else {
                merged.back().h += pts[i].h;
            }
        }
        
        int m = merged.size();
        vector<long long> pref(m);
        pref[0] = merged[0].h;
        for(int i=1; i<m; i++) pref[i] = pref[i-1] + merged[i].h;
        
        bool found = false;
        int l = 0, r = m - 1;
        while(l<= r) {
            int mid = (l+r)/2;
            long long L_at = (mid > 0 ? pref[mid-1] : 0);
            long long R_at = pref[m-1] - pref[mid];
            if (L_at == R_at) { found = true; break; }
            
            long long L_after = pref[mid];
            long long R_after = pref[m-1] - pref[mid];
            if (L_after == R_after) { found = true; break; }
            
            if (L_after < R_after) {
                l = mid + 1;
            } else if (L_at > R_at) {
                r = mid - 1;
            } else {
                break;
            }
        }
        if (found) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
