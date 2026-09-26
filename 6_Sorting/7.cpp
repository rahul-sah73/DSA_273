#include <iostream>
using namespace std;

void sort(int a[], int n, int flag) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if (flag == 1) {
                if (a[j] > a[j+1]) {
                    int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                }
            } else {
                if (a[j] < a[j+1]) {
                    int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                }
            }
        }
    }
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        int a[100], b[100];
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        sort(a, n, 1);
        sort(b, n, 0);
        long long sum = 0;
        for(int i=0; i<n; i++) sum += (long long)a[i] * b[i];
        cout << sum << endl;
    }
    return 0;
}
