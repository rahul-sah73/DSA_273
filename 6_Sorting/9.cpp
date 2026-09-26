#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        int n, k, p;
        cin >> n >> k >> p;
        vector<vector<int>> pref(n, vector<int>(k + 1, 0));
        for(int i = 0;i < n;i++) {
            for(int j = 1; j <= k; j++) {
                int val;
                cin >> val;
                pref[i][j] = pref[i][j-1] + val;
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
        for(int i = 0;i < n;i++) {
            for(int j = 0; j <= p; j++) {
                for(int c = 0; c <= k && c <= j; c++) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j-c] + pref[i][c]);
                }
            }
        }
        cout << dp[n][p] << endl;
    }
    return 0;
}
