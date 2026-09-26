#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        int n; cin >> n;
        vector<int> girls(n), boys(n);
        for(int i = 0;i<n;i++) cin >> girls[i];
        for(int i = 0;i<n;i++) cin >> boys[i];
        sort(girls.begin(), girls.end());
        sort(boys.rbegin(), boys.rend());
        int ideal = 0;
        for(int i = 0;i<n;i++) {
            if (girls[i] % boys[i] == 0 || boys[i] % girls[i] == 0) {
                ideal++;
            }
        }
        cout << ideal << endl;
    }
    return 0;
}
