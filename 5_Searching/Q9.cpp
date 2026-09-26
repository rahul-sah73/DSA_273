#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    for(int t=0;t<T;t++) {
        int n;
        long long d;
        cin >> n >> d;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for(int i=n-1;i>=0;i--) {
            d = (d / x[i]) * x[i];
        }
        cout << d << "\n";
    }
    return 0;
}
