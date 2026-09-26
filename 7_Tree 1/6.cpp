#include <iostream>
#include <vector>

using namespace std;

int up[200005][20];

void link(int i,int j) {
    up[i][0] = j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        link(i, boss);
    }
    
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j-1] != 0) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < 20; j++) {
            if (k & (1 << j)) {
                x = up[x][j];
            }
        }
        if (x == 0) cout << -1 << "\n";
        else cout << x << "\n";
    }
    
    return 0;
}
