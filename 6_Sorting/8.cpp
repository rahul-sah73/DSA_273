#include <iostream>
using namespace std;

void sort(int a[], int n) {
    int i;
    for(i=0;i<n-1;i++) {
        for(int j=0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
    }
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[100005];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a, n);
        if (a[n-1] > k) {
            cout << a[n-1] - k << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
