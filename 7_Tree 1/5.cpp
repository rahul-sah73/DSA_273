#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int tree_arr[4 * MAXN];

void build(int *aa,int k,int l,int r) {
    if (l == r) {
        tree_arr[k] = aa[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(aa, 2 * k, l, mid);
    build(aa, 2 * k + 1, mid + 1, r);
    tree_arr[k] = min(tree_arr[2 * k], tree_arr[2 * k + 1]);
}

int query(int k,int l,int r,int ql,int qr) {
    if (ql <= l && r <= qr) {
        return tree_arr[k];
    }
    if (qr < l || ql > r) {
        return 1e9 + 7; 
    }
    int mid = l + (r - l) / 2;
    int leftMin = query(2 * k, l, mid, ql, qr);
    int rightMin = query(2 * k + 1, mid + 1, r, ql, qr);
    return min(leftMin, rightMin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    int* aa = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> aa[i];
    }
    
    build(aa, 1, 1, n);
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << "\n";
    }
    
    delete[] aa;
    return 0;
}
