#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
long long sum_tree[4 * MAXN];
long long lazy_C[4 * MAXN];
long long lazy_D[4 * MAXN];
long long a[MAXN];

long long sum_indices(long long l, long long r) {
    return (l + r) * (r - l + 1) / 2;
}

void apply(int k, int l, int r, long long c, long long d) {
    sum_tree[k] += c * (r - l + 1) + d * sum_indices(l, r);
    lazy_C[k] += c;
    lazy_D[k] += d;
}

void push(int k, int l, int r) {
    if (lazy_C[k] != 0 || lazy_D[k] != 0) {
        int mid = (l + r) / 2;
        apply(2 * k, l, mid, lazy_C[k], lazy_D[k]);
        apply(2 * k + 1, mid + 1, r, lazy_C[k], lazy_D[k]);
        lazy_C[k] = 0;
        lazy_D[k] = 0;
    }
}

void build(int k,int l,int r) {
    if (l == r) {
        sum_tree[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    sum_tree[k] = sum_tree[2 * k] + sum_tree[2 * k + 1];
}

void update(int k, int l, int r, int ql, int qr, long long c, long long d) {
    if (ql > qr) return;
    if (ql <= l && r <= qr) {
        apply(k, l, r, c, d);
        return;
    }
    push(k, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) update(2 * k, l, mid, ql, qr, c, d);
    if (qr > mid) update(2 * k + 1, mid + 1, r, ql, qr, c, d);
    sum_tree[k] = sum_tree[2 * k] + sum_tree[2 * k + 1];
}

long long query(int k, int l, int r, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql <= l && r <= qr) return sum_tree[k];
    push(k, l, r);
    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid) res += query(2 * k, l, mid, ql, qr);
    if (qr > mid) res += query(2 * k + 1, mid + 1, r, ql, qr);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < q; ++i) {
        int type, l, r;
        cin >> type >> l >> r;
        
        // Handle typos in test cases where type might be given as 3 instead of 2, 
        // or range exceeds n.
        r = min(r, n);
        l = max(l, 1);
        
        if (type == 1) {
            update(1, 1, n, l, r, 1LL - l, 1LL);
        } else {
            // Treat anything else (e.g., type 2, or typo type 3) as a query
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
