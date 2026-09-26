#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, i, j;
    if (!(cin >> n >> q)) return 0;
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for(i=1;i<=n;i++) {
        string row;
        cin >> row;
        for(j=1;j<=n;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (row[j-1] == '*' ? 1 : 0);
        }
    }
    
    for(int k=0; k<q; k++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1];
        cout << ans << "\n";
    }
    
    return 0;
}
