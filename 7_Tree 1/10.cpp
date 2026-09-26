#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
int tree_arr[4 * MAXN];
int vals[MAXN];

void build(int k,int l,int r) {
    if (l == r) {
        tree_arr[k] = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree_arr[k] = tree_arr[2 * k] + tree_arr[2 * k + 1];
}

int query_and_remove(int k, int l, int r, int pos) {
    tree_arr[k]--;
    if (l == r) {
        return vals[l];
    }
    int mid = l + (r - l) / 2;
    if (tree_arr[2 * k] >= pos) {
        return query_and_remove(2 * k, l, mid, pos);
    } else {
        return query_and_remove(2 * k + 1, mid + 1, r, pos - tree_arr[2 * k]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }
    
    build(1, 1, n);
    
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        cout << query_and_remove(1, 1, n, pos) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
